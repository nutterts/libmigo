// Copyright 2009 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

/* This file supports C files copied from the 6g runtime library.
   This is a version of the 6g runtime.h rewritten for gccgo's version
   of the code.  */

#ifndef __RUNTIME_H__
#define __RUNTIME_H__

#include <stddef.h>
#include <stdint.h>
#include "errno.h"
#include "go-assert.h"


typedef signed int   int8    __attribute__ ((mode (QI)));
typedef unsigned int uint8   __attribute__ ((mode (QI)));
typedef signed int   int16   __attribute__ ((mode (HI)));
typedef unsigned int uint16  __attribute__ ((mode (HI)));
typedef signed int   int32   __attribute__ ((mode (SI)));
typedef unsigned int uint32  __attribute__ ((mode (SI)));
typedef signed int   int64   __attribute__ ((mode (DI)));
typedef unsigned int uint64  __attribute__ ((mode (DI)));
typedef float        float32 __attribute__ ((mode (SF)));
typedef double       float64 __attribute__ ((mode (DF)));
typedef signed int   intptr __attribute__ ((mode (pointer)));
typedef unsigned int uintptr __attribute__ ((mode (pointer)));

typedef intptr		intgo; // Go's int
typedef uintptr		uintgo; // Go's uint

typedef uintptr		uintreg;

/* Defined types.  */
typedef	uint8			bool;
typedef	uint8			byte;
typedef	struct	String		String;



/* Definitions */
#define LIBMIGO

/* GLIBC identifiers */
#define op_t    unsigned long int
#define OPSIZ   (sizeof(op_t))


/* Structures */

struct String
{
	const byte*	str;
	intgo		len;
};

/* Enumerations */
enum
{
	true	= 1,
	false	= 0,
};

/*
 * structures
 */




// A list of global variables that the garbage collector must scan.
struct root_list {
	struct root_list *next;
	struct root {
		void *decl;
		size_t size;
	} roots[];
};

/* dlmalloc */
void* malloc(size_t);
void  free(void*);
void* calloc(size_t, size_t);
void* realloc(void*, size_t);

/* Memory Management */
extern int32_t runtime_sbrk_size;
extern int32_t runtime_sbrk_top;
extern int32_t runtime_sbrk_bottom;
extern int32_t runtime_sbrk_pos;  
void *runtime_sbrk(intptr_t increment);

#define sbrk(increment) runtime_sbrk(increment)
#define runtime_malloc(size) malloc(size) 

/* Textmode */
void cls();
void putch(unsigned char c);
void puts(const char *str);
void settextcolor(unsigned char forecolor, unsigned char backcolor);
void textmode_init();

/* Itoa */
void strreverse(char* begin, char* end);
void itoa(int64_t value, char* str, int base);

/* Mini-libc */
void 		*memcpy(void *restrict s1, const void *restrict s2, size_t n);
void		abort(void);
int 		memcmp (const void *__s1, const void *__s2, size_t __n);
void 		*memset (void *dstpp, int c, size_t len);
size_t 		strlen (const char *str);
void 		*memsetw(void *s, int c, size_t n);

/* Port I/O */
inline void outportb(unsigned int port,unsigned char value)
{
   asm volatile ("outb %%al,%%dx": :"d" (port), "a" (value));
}

/* Function prototypes */
uintptr_t	itop(intgo); 
void		runtime_abort(void) __attribute__ ((noreturn));
void		runtime_panicstring(const char*) __attribute__ ((noreturn));
void		__go_register_gc_roots(struct root_list*);
void 		*__go_alloc (unsigned int __attribute__ ((mode (pointer))));
void		__go_free(void *v);

#endif