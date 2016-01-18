// unknowndefine __SIZE_TYPE__ long unsigned int
// unknowndefine __PTRDIFF_TYPE__ long int
// unknowndefine __WCHAR_TYPE__ int
// unknowndefine __WINT_TYPE__ unsigned int
// unknowndefine __INTMAX_TYPE__ long long int
// unknowndefine __UINTMAX_TYPE__ long long unsigned int
// unknowndefine __CHAR16_TYPE__ short unsigned int
// unknowndefine __CHAR32_TYPE__ long unsigned int
// unknowndefine __SIG_ATOMIC_TYPE__ int
// unknowndefine __INT8_TYPE__ signed char
// unknowndefine __INT16_TYPE__ short int
// unknowndefine __INT32_TYPE__ long int
// unknowndefine __INT64_TYPE__ long long int
// unknowndefine __UINT8_TYPE__ unsigned char
// unknowndefine __UINT16_TYPE__ short unsigned int
// unknowndefine __UINT32_TYPE__ long unsigned int
// unknowndefine __UINT64_TYPE__ long long unsigned int
// unknowndefine __INT_LEAST8_TYPE__ signed char
// unknowndefine __INT_LEAST16_TYPE__ short int
// unknowndefine __INT_LEAST32_TYPE__ long int
// unknowndefine __INT_LEAST64_TYPE__ long long int
// unknowndefine __UINT_LEAST8_TYPE__ unsigned char
// unknowndefine __UINT_LEAST16_TYPE__ short unsigned int
// unknowndefine __UINT_LEAST32_TYPE__ long unsigned int
// unknowndefine __UINT_LEAST64_TYPE__ long long unsigned int
// unknowndefine __INT_FAST8_TYPE__ int
// unknowndefine __INT_FAST16_TYPE__ int
// unknowndefine __INT_FAST32_TYPE__ int
// unknowndefine __INT_FAST64_TYPE__ long long int
// unknowndefine __UINT_FAST8_TYPE__ unsigned int
// unknowndefine __UINT_FAST16_TYPE__ unsigned int
// unknowndefine __UINT_FAST32_TYPE__ unsigned int
// unknowndefine __UINT_FAST64_TYPE__ long long unsigned int
// unknowndefine __INTPTR_TYPE__ long int
// unknowndefine __UINTPTR_TYPE__ long unsigned int
// unknowndefine __DBL_MAX__ ((double)1.1)
// unknowndefine __DBL_MIN__ ((double)1.1)
// unknowndefine __DBL_EPSILON__ ((double)1.1)
// unknowndefine __DBL_DENORM_MIN__ ((double)1.1)
// unknowndefine NULL ((void *)0)
// unknowndefine op_t unsigned long int
// unknowndefine OPSIZ (sizeof(op_t))
type _ptrdiff_t int32
type _size_t uint32
type _wchar_t int32
// type _max_align_t struct { __max_align_ll int64; __max_align_ld INVALID-float-80; }
const _sizeof_max_align_t = 24
type _int8_t int8
type _int16_t int16
type _int32_t int32
type _int64_t int64
type _uint8_t uint8
type _uint16_t uint16
type _uint32_t uint32
type _uint64_t uint64
type _int_least8_t int8
type _int_least16_t int16
type _int_least32_t int32
type _int_least64_t int64
type _uint_least8_t uint8
type _uint_least16_t uint16
type _uint_least32_t uint32
type _uint_least64_t uint64
type _int_fast8_t int32
type _int_fast16_t int32
type _int_fast32_t int32
type _int_fast64_t int64
type _uint_fast8_t uint32
type _uint_fast16_t uint32
type _uint_fast32_t uint32
type _uint_fast64_t uint64
type _intptr_t int32
type _uintptr_t uint32
type _intmax_t int64
type _uintmax_t uint64
type _int8 int8
type _uint8 uint8
type _int16 int16
type _uint16 uint16
type _int32 int32
type _uint32 uint32
type _int64 int64
type _uint64 uint64
type _float32 float32
type _float64 float64
type _intptr int32
type _uintptr uint32
type _intgo int32
type _uintgo uint32
type _uintreg uint32
type _bool uint8
type _byte uint8
type _String struct { str *uint8; len int32; }
const _sizeof_String = 8
type _root struct { decl *byte; size uint32; }
const _sizeof_root = 8
type _root_list struct { next *_root_list; roots [0]_root; }
const _sizeof_root_list = 4
type ___go_type_descriptor struct { __code uint8; __align uint8; __field_align uint8; __size uint32; __hash uint32; __hashfn func(*byte, uint32) uint32; __equalfn func(*byte, *byte, uint32) bool; __gc *uint32; __reflection *_String; __uncommon *___go_uncommon_type; __pointer_to_this *___go_type_descriptor; __zero *byte; }
const _sizeof___go_type_descriptor = 40
type ___go_map_type struct { __common ___go_type_descriptor; __key_type *___go_type_descriptor; __val_type *___go_type_descriptor; }
const _sizeof___go_map_type = 48
func ___go_type_hash_identity (*byte, uint32) uint32 __asm__("__go_type_hash_identity")
func ___go_type_equal_identity (*byte, *byte, uint32) bool __asm__("__go_type_equal_identity")
var _runtime_memory_size _int32_t
var _runtime_memory_top _int32_t
var _runtime_memory_bottom _int32_t
var _runtime_memory_pos _int32_t
func _runtime_malloc (uint32) *byte __asm__("runtime_malloc")
func _cls () __asm__("cls")
func _putch (uint8) __asm__("putch")
func _puts (*int8) __asm__("puts")
func _settextcolor (uint8, uint8) __asm__("settextcolor")
func _textmode_init () __asm__("textmode_init")
func _memcpy (*byte, *byte, uint32) *byte __asm__("memcpy")
func _abort () __asm__("abort")
func _memcmp (*byte, *byte, uint32) int32 __asm__("memcmp")
func _memset (*byte, int32, uint32) *byte __asm__("memset")
func _strlen (*int8) uint32 __asm__("strlen")
func _memsetw (*byte, int32, uint32) *byte __asm__("memsetw")
func _outportb (uint32, uint8) __asm__("outportb")
func _itop (int32) uint32 __asm__("itop")
func _runtime_abort () __asm__("runtime_abort")
func _runtime_panicstring (*int8) __asm__("runtime_panicstring")
func ___go_register_gc_roots (*_root_list) __asm__("__go_register_gc_roots")
func ___go_alloc (uint32) *byte __asm__("__go_alloc")
func ___go_free (*byte) __asm__("__go_free")
func ___go_type_hash_identity (*byte, uint32) uint32 __asm__("__go_type_hash_identity")
func ___go_type_equal_identity (*byte, *byte, uint32) bool __asm__("__go_type_equal_identity")
func ___go_type_hash_error (*byte, uint32) uint32 __asm__("__go_type_hash_error")
func ___go_type_equal_error (*byte, *byte, uint32) bool __asm__("__go_type_equal_error")
const _INTMAX_MIN = (-_INTMAX_MAX - 1)
const _UINTMAX_MAX = ___UINTMAX_MAX__
const ___ORDER_PDP_ENDIAN__ = 3412
const _INT_FAST8_MIN = (-_INT_FAST8_MAX - 1)
const ___FLT_MANT_DIG__ = 24
const _INT_LEAST64_MAX = ___INT_LEAST64_MAX__
const ___DEC64_MANT_DIG__ = 16
const ___INT_LEAST64_MAX__ = 0x7fffffffffffffff
const ___DBL_MIN_EXP__ = (-1021)
const _GO_COMPLEX128 = 16
const ___LONG_MAX__ = 0x7fffffff
const _GO_FLOAT32 = 13
const ___INT_FAST16_MAX__ = 0x7fffffff
const _INT_LEAST64_MIN = (-_INT_LEAST64_MAX - 1)
const ___STDC_UTF_32__ = 1
const ___FLT_EVAL_METHOD__ = 2
const ___UINTPTR_MAX__ = 0xffffffff
const ___FLT_MIN__ = 1.1
const ___INT16_MAX__ = 0x7fff
const ___FLT_MIN_EXP__ = (-125)
const ___INT_LEAST8_MAX__ = 0x7f
const ___SIG_ATOMIC_MAX__ = 0x7fffffff
const _GO_FUNC = 19
const _GO_MAP = 21
const _UINT64_MAX = ___UINT64_MAX__
const ___GCC_ATOMIC_BOOL_LOCK_FREE = 2
const _GO_INT8 = 3
const _UINT_LEAST16_MAX = ___UINT_LEAST16_MAX__
const ___SIZEOF_PTRDIFF_T__ = 4
const ___code_model_32__ = 1
const ___UINT_FAST64_MAX__ = 0xffffffffffffffff
const ___SIG_ATOMIC_MIN__ = (-___SIG_ATOMIC_MAX__ - 1)
const _INT_LEAST16_MIN = (-_INT_LEAST16_MAX - 1)
const _GO_INTERFACE = 20
const ___FLT_RADIX__ = 2
const ___PRAGMA_REDEFINE_EXTNAME = 1
const ___DEC32_SUBNORMAL_MIN__ = 0.000001E-95
const _INT_LEAST32_MIN = (-_INT_LEAST32_MAX - 1)
const ___ATOMIC_ACQUIRE = 2
const ___FLT_MAX__ = 1.1
const ___i386 = 1
const ___DECIMAL_DIG__ = 21
const ___UINTMAX_MAX__ = 0xffffffffffffffff
const ___GCC_ATOMIC_CHAR16_T_LOCK_FREE = 2
const ___STDC_VERSION__ = 201112
const ___UINT_LEAST16_MAX__ = 0xffff
const _i386 = 1
const ___ATOMIC_RELAXED = 0
const ___SIZEOF_DOUBLE__ = 8
const ___FLT_DECIMAL_DIG__ = 9
const ___GCC_ATOMIC_CHAR32_T_LOCK_FREE = 2
const ___GCC_IEC_559_COMPLEX = 2
const ___DBL_HAS_DENORM__ = 1
const ___SIZEOF_FLOAT128__ = 16
const ___GCC_ATOMIC_TEST_AND_SET_TRUEVAL = 1
const ___SIZEOF_LONG_DOUBLE__ = 12
const _GO_UINT16 = 9
const ___SIZEOF_INT__ = 4
const ___DBL_DECIMAL_DIG__ = 17
const ___DEC32_MIN__ = 1E-95
const ___SIZEOF_WCHAR_T__ = 4
const ___STDC__ = 1
const ___GNUC_MINOR__ = 3
const ___SIZEOF_WINT_T__ = 4
const ___UINT_FAST16_MAX__ = 0xffffffff
const ___FLT_DENORM_MIN__ = 1.1
const ___ORDER_BIG_ENDIAN__ = 4321
const ___GCC_ATOMIC_LONG_LOCK_FREE = 2
const ___SIZEOF_SHORT__ = 2
const _PTRDIFF_MAX = ___PTRDIFF_MAX__
const _WCHAR_MAX = ___WCHAR_MAX__
const ___DEC128_MIN__ = 1E-6143
const _UINT32_MAX = ___UINT32_MAX__
const _GO_CODE_MASK = 0x1f
const ___LDBL_HAS_INFINITY__ = 1
const ___INT_MAX__ = 0x7fffffff
const ___DEC32_MAX__ = 9.999999E96
const ___FINITE_MATH_ONLY__ = 0
const ___DBL_MAX_EXP__ = 1024
const ___LDBL_MAX__ = 1.1
const ___DBL_MIN_10_EXP__ = (-307)
const ___LDBL_MAX_10_EXP__ = 4932
const ___GNUC_PATCHLEVEL__ = 0
const _GO_UINT = 7
const ___LDBL_HAS_QUIET_NAN__ = 1
const ___ORDER_LITTLE_ENDIAN__ = 1234
const ___UINT32_MAX__ = 0xffffffff
const ___DEC64_MIN_EXP__ = (-382)
const ___UINT_LEAST32_MAX__ = 0xffffffff
const ___LONG_LONG_MAX__ = 0x7fffffffffffffff
const ___DEC128_SUBNORMAL_MIN__ = 0.000000000000000000000000000000001E-6143
const ___FLT_MAX_EXP__ = 128
const _GO_PTR = 22
const ___ATOMIC_CONSUME = 1
const _INT_FAST32_MAX = ___INT_FAST32_MAX__
const _WCHAR_MIN = ___WCHAR_MIN__
const ___DBL_HAS_INFINITY__ = 1
const ___DEC128_MAX__ = 9.999999999999999999999999999999999E6144
const _GO_UINT8 = 8
const ___UINT_LEAST8_MAX__ = 0xff
const _INT_FAST16_MIN = (-_INT_FAST16_MAX - 1)
const _GO_DIRECT_IFACE = (1 << 5)
const ___DEC128_EPSILON__ = 1E-33
const _WINT_MIN = ___WINT_MIN__
const ___SIZEOF_SIZE_T__ = 4
const _GO_SLICE = 23
const ___DBL_HAS_QUIET_NAN__ = 1
const ___INT_FAST32_MAX__ = 0x7fffffff
const ___ATOMIC_SEQ_CST = 5
const ___DEC128_MANT_DIG__ = 34
const _SIZE_MAX = ___SIZE_MAX__
const ___GCC_IEC_559 = 2
const ___INT32_MAX__ = 0x7fffffff
const ___LDBL_MANT_DIG__ = 64
const _GO_STRING = 24
const ___DEC128_MAX_EXP__ = 6145
const _INT64_MAX = ___INT64_MAX__
const _UINT_FAST16_MAX = ___UINT_FAST16_MAX__
const ___GCC_ATOMIC_INT_LOCK_FREE = 2
const ___FLT_HAS_INFINITY__ = 1
const ___FLT_MAX_10_EXP__ = 38
const ___ATOMIC_HLE_ACQUIRE = 65536
const _GO_BOOL = 1
const ___STDC_HOSTED__ = 0
const _GO_UINT32 = 10
const _UINT_FAST32_MAX = ___UINT_FAST32_MAX__
const ___LDBL_MIN__ = 1.1
const _INT_LEAST8_MAX = ___INT_LEAST8_MAX__
const ___DEC32_MANT_DIG__ = 7
const ___GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 = 1
const ___GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 = 1
const ___FLOAT_WORD_ORDER__ = ___ORDER_LITTLE_ENDIAN__
const ___GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 = 1
const ___CHAR_BIT__ = 8
const ___GCC_ATOMIC_SHORT_LOCK_FREE = 2
const ___SHRT_MAX__ = 0x7fff
const ___GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 = 1
const _SIG_ATOMIC_MAX = ___SIG_ATOMIC_MAX__
const _GO_INT16 = 4
const _INT_FAST16_MAX = ___INT_FAST16_MAX__
const _UINT_FAST64_MAX = ___UINT_FAST64_MAX__
const _INT_LEAST8_MIN = (-_INT_LEAST8_MAX - 1)
const _UINT8_MAX = ___UINT8_MAX__
const _GO_NO_POINTERS = (1 << 7)
const _INTPTR_MIN = (-_INTPTR_MAX - 1)
const ___i686__ = 1
const ___ATOMIC_HLE_RELEASE = 131072
const _SIG_ATOMIC_MIN = ___SIG_ATOMIC_MIN__
const ___LDBL_MAX_EXP__ = 16384
const _INT_LEAST32_MAX = ___INT_LEAST32_MAX__
const _UINT16_MAX = ___UINT16_MAX__
const _GO_ARRAY = 17
const ___DBL_MAX_10_EXP__ = 308
const ___STDC_UTF_16__ = 1
const ___SIZEOF_POINTER__ = 4
const _GO_FLOAT64 = 14
const ___GCC_ATOMIC_POINTER_LOCK_FREE = 2
const ___INT_LEAST16_MAX__ = 0x7fff
const ___UINT_LEAST64_MAX__ = 0xffffffffffffffff
const ___FLT_EPSILON__ = 1.1
const ___DEC64_EPSILON__ = 1E-15
const ___INTMAX_MAX__ = 0x7fffffffffffffff
const ___i686 = 1
const ___INTPTR_MAX__ = 0x7fffffff
const _UINTPTR_MAX = ___UINTPTR_MAX__
const ___INT8_MAX__ = 0x7f
const ___SIZEOF_LONG_LONG__ = 8
const ___DBL_MANT_DIG__ = 53
const _GO_GC_PROG = (1 << 6)
const _INT_FAST64_MAX = ___INT_FAST64_MAX__
const ___i386__ = 1
const ___SIZEOF_LONG__ = 4
const ___UINT64_MAX__ = 0xffffffffffffffff
const ___UINT_FAST32_MAX__ = 0xffffffff
const _INT_FAST64_MIN = (-_INT_FAST64_MAX - 1)
const ___FLT_DIG__ = 6
const ___BYTE_ORDER__ = ___ORDER_LITTLE_ENDIAN__
const ___PTRDIFF_MAX__ = 0x7fffffff
const _GO_STRUCT = 25
const ___UINT8_MAX__ = 0xff
const _INT8_MAX = ___INT8_MAX__
const ___VERSION__ = "5.3.0"
const _UINT_FAST8_MAX = ___UINT_FAST8_MAX__
const ___SCHAR_MAX__ = 0x7f
const ___ATOMIC_ACQ_REL = 4
const ___DEC64_MAX__ = 9.999999999999999E384
const ___DEC64_SUBNORMAL_MIN__ = 0.000000000000001E-383
const ___DEC64_MIN__ = 1E-383
const _false = 0
const ___WCHAR_MIN__ = (-___WCHAR_MAX__ - 1)
const _INT8_MIN = (-_INT8_MAX - 1)
const ___GXX_ABI_VERSION = 1009
const ___INT_FAST8_MAX__ = 0x7fffffff
const _INT64_MIN = (-_INT64_MAX - 1)
const _INT_FAST32_MIN = (-_INT_FAST32_MAX - 1)
const _INT16_MAX = ___INT16_MAX__
const _WINT_MAX = ___WINT_MAX__
const ___LDBL_MIN_10_EXP__ = (-4931)
const ___LDBL_EPSILON__ = 1.1
const _GO_CHAN = 18
const ___FLT_HAS_DENORM__ = 1
const _INT32_MAX = ___INT32_MAX__
const _INT16_MIN = (-_INT16_MAX - 1)
const ___pentiumpro__ = 1
const ___pentiumpro = 1
const ___WCHAR_MAX__ = 0x7fffffff
const _PTRDIFF_MIN = (-_PTRDIFF_MAX - 1)
const _GO_UNSAFE_POINTER = 26
const _GO_INT64 = 6
const ___GCC_ATOMIC_WCHAR_T_LOCK_FREE = 2
const ___BIGGEST_ALIGNMENT__ = 16
const _INT32_MIN = (-_INT32_MAX - 1)
const _GO_INT = 2
const ___SIZE_MAX__ = 0xffffffff
const ___ATOMIC_RELEASE = 3
const _GO_INT32 = 5
const ___INT64_MAX__ = 0x7fffffffffffffff
const ___LDBL_DIG__ = 18
const ___SIZEOF_FLOAT80__ = 12
const ___DEC128_MIN_EXP__ = (-6142)
const ___WINT_MIN__ = 0
const ___FLT_HAS_QUIET_NAN__ = 1
const ___DEC32_EPSILON__ = 1E-6
const ___ELF__ = 1
const _GO_UINT64 = 11
const _INTPTR_MAX = ___INTPTR_MAX__
const ___DEC32_MIN_EXP__ = (-94)
const ___WINT_MAX__ = 0xffffffff
const ___GCC_HAVE_DWARF2_CFI_ASM = 1
const ___GCC_ATOMIC_CHAR_LOCK_FREE = 2
const ___LDBL_DENORM_MIN__ = 1.1
const ___DEC64_MAX_EXP__ = 385
const ___GNUC__ = 5
const ___DEC32_MAX_EXP__ = 97
const ___FLT_MIN_10_EXP__ = (-37)
const ___GNUC_STDC_INLINE__ = 1
const ___OPTIMIZE__ = 1
const ___INT_LEAST32_MAX__ = 0x7fffffff
const ___SIZEOF_FLOAT__ = 4
const ___UINT_FAST8_MAX__ = 0xffffffff
const _UINT_LEAST8_MAX = ___UINT_LEAST8_MAX__
const _INT_FAST8_MAX = ___INT_FAST8_MAX__
const ___LDBL_HAS_DENORM__ = 1
const ___LDBL_MIN_EXP__ = (-16381)
const ___INT_FAST64_MAX__ = 0x7fffffffffffffff
const _GO_UINTPTR = 12
const _UINT_LEAST32_MAX = ___UINT_LEAST32_MAX__
const _INTMAX_MAX = ___INTMAX_MAX__
const _UINT_LEAST64_MAX = ___UINT_LEAST64_MAX__
const ___DEC_EVAL_METHOD__ = 2
const ___DBL_DIG__ = 15
const _GO_COMPLEX64 = 15
const ___UINT16_MAX__ = 0xffff
const _true = 1
const ___GCC_ATOMIC_LLONG_LOCK_FREE = 2
const _INT_LEAST16_MAX = ___INT_LEAST16_MAX__
type ___go_uncommon_type struct {}
