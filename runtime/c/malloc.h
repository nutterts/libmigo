// Copyright 2009 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

/* Modfified for Golos */

// MTypes describes the types of blocks allocated within a span.
// The compression field describes the layout of the data.
//
// MTypes_Empty:
//     All blocks are free, or no type information is available for
//     allocated blocks.
//     The data field has no meaning.
// MTypes_Single:
//     The span contains just one block.
//     The data field holds the type information.
//     The sysalloc field has no meaning.
// MTypes_Words:
//     The span contains multiple blocks.
//     The data field points to an array of type [NumBlocks]uintptr,
//     and each element of the array holds the type of the corresponding
//     block.
// MTypes_Bytes:
//     The span contains at most seven different types of blocks.
//     The data field points to the following structure:
//         struct {
//             type  [8]uintptr       // type[0] is always 0
//             index [NumBlocks]byte
//         }
//     The type of the i-th block is: data.type[data.index[i]]

#ifndef __MALLOC_H__
#define __MALLOC_H__

#include "runtime.h"


enum
{
	PageShift	= 13,
	PageSize	= 1<<PageShift,
	PageMask	= PageSize - 1,
};

enum
{
	// Computed constant.  The definition of MaxSmallSize and the
	// algorithm in msize.c produce some number of different allocation
	// size classes.  NumSizeClasses is that number.  It's needed here
	// because there are static arrays of this length; when msize runs its
	// size choosing algorithm it double-checks that NumSizeClasses agrees.
	NumSizeClasses = 67,

	// Tunable constants.
	MaxSmallSize = 32<<10,

	// Tiny allocator parameters, see "Tiny allocator" comment in malloc.goc.
	TinySize = 16,
	TinySizeClass = 2,

	FixAllocChunk = 16<<10,		// Chunk size for FixAlloc
	MaxMHeapList = 1<<(20 - PageShift),	// Maximum page length for fixed-size list in MHeap.
	HeapAllocChunk = 1<<20,		// Chunk size for heap growth

	// Number of bits in page to span calculations (4k pages).
	// On Windows 64-bit we limit the arena to 32GB or 35 bits (see below for reason).
	// On other 64-bit platforms, we limit the arena to 128GB, or 37 bits.
	// On 32-bit, we don't bother limiting anything, so we use the full 32-bit address.
#if __SIZEOF_POINTER__ == 8
	MHeapMap_Bits = 37 - PageShift,
#else
	MHeapMap_Bits = 32 - PageShift,
#endif

	// Max number of threads to run garbage collection.
	// 2, 3, and 4 are all plausible maximums depending
	// on the hardware details of the machine.  The garbage
	// collector scales well to 8 cpus.
	MaxGcproc = 8,
};

typedef	uintptr	PageID;		// address >> PageShift

// Maximum memory allocation size, a hint for callers.
// This must be a #define instead of an enum because it
// is so large.
#if __SIZEOF_POINTER__ == 8
#define	MaxMem	(1ULL<<(MHeapMap_Bits+PageShift))	/* 128 GB or 32 GB */
#else
#define	MaxMem	((uintptr)-1)
#endif

// Size classes.  Computed and initialized by InitSizes.
//
// SizeToClass(0 <= n <= MaxSmallSize) returns the size class,
//	1 <= sizeclass < NumSizeClasses, for n.
//	Size class 0 is reserved to mean "not small".
//
// class_to_size[i] = largest size in class i
// class_to_allocnpages[i] = number of pages to allocate when
//	making new objects in class i

uintptr	runtime_roundupsize(uintptr);

#endif