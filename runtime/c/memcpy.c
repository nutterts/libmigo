/* Extracted from glibc for Golos 
   License: LGPL */

/* Should be replaced, but it'll make things work for now. */

#include "runtime.h"

/* memcpy */
# define __memcpy(dest, src, n) \
  (__extension__ (__builtin_constant_p (n)              \
      ? __memcpy_c ((dest), (src), (n))           \
      : __memcpy_g ((dest), (src), (n))))
# define __memcpy_c(dest, src, n) \
  ((n) == 0                     \
   ? (dest)                     \
   : (((n) % 4 == 0)                    \
      ? __memcpy_by4 (dest, src, n)               \
      : (((n) % 2 == 0)                   \
   ? __memcpy_by2 (dest, src, n)                \
   : __memcpy_g (dest, src, n))))

void *
__memcpy_by4 (void *__dest, const void *__src, size_t __n)
{
  register unsigned long int __d0, __d1;
  register void *__tmp = __dest;
  __asm__ __volatile__
    ("1:\n\t"
     "movl  (%2),%0\n\t"
     "leal  4(%2),%2\n\t"
     "movl  %0,(%1)\n\t"
     "leal  4(%1),%1\n\t"
     "decl  %3\n\t"
     "jnz 1b"
     : "=&r" (__d0), "=&r" (__tmp), "=&r" (__src), "=&r" (__d1)
     : "1" (__tmp), "2" (__src), "3" (__n / 4)
     : "memory", "cc");
  return __dest;
}

void *
__memcpy_by2 (void *__dest, const void *__src, size_t __n)
{
  register unsigned long int __d0, __d1;
  register void *__tmp = __dest;
  __asm__ __volatile__
    ("shrl  $1,%3\n\t"
     "jz  2f\n"                 /* only a word */
     "1:\n\t"
     "movl  (%2),%0\n\t"
     "leal  4(%2),%2\n\t"
     "movl  %0,(%1)\n\t"
     "leal  4(%1),%1\n\t"
     "decl  %3\n\t"
     "jnz 1b\n"
     "2:\n\t"
     "movw  (%2),%w0\n\t"
     "movw  %w0,(%1)"
     : "=&q" (__d0), "=&r" (__tmp), "=&r" (__src), "=&r" (__d1)
     : "1" (__tmp), "2" (__src), "3" (__n / 2)
     : "memory", "cc");
  return __dest;
}

void *
__memcpy_g (void *__dest, const void *__src, size_t __n)
{
  register unsigned long int __d0, __d1, __d2;
  register void *__tmp = __dest;
  __asm__ __volatile__
    ("cld\n\t"
     "shrl  $1,%%ecx\n\t"
     "jnc 1f\n\t"
     "movsb\n"
     "1:\n\t"
     "shrl  $1,%%ecx\n\t"
     "jnc 2f\n\t"
     "movsw\n"
     "2:\n\t"
     "rep; movsl"
     : "=&c" (__d0), "=&D" (__d1), "=&S" (__d2),
       "=m" ( *(struct { __extension__ char __x[__n]; } *)__dest)
     : "0" (__n), "1" (__tmp), "2" (__src),
       "m" ( *(struct { __extension__ char __x[__n]; } *)__src)
     : "cc");
  return __dest;
}

void *
memcpy(void *restrict s1, const void *restrict s2, size_t n)
{
  return __memcpy(s1, s2, n);
}