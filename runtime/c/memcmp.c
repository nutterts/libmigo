/* Extracted from glibc 
   License: LGPL */

/* Should be replaced with my own version but it'll work for now. */

#include "runtime.h"

int
memcmp (const void *__s1, const void *__s2, size_t __n)
{
  register unsigned long int __d0, __d1, __d2;
  register int __res;
  __asm__ __volatile__
    ("cld\n\t"
     "testl %3,%3\n\t"
     "repe; cmpsb\n\t"
     "je	1f\n\t"
     "sbbl	%0,%0\n\t"
     "orl	$1,%0\n"
     "1:"
     : "=&a" (__res), "=&S" (__d0), "=&D" (__d1), "=&c" (__d2)
     : "0" (0), "1" (__s1), "2" (__s2), "3" (__n),
       "m" ( *(struct { __extension__ char __x[__n]; } *)__s1),
       "m" ( *(struct { __extension__ char __x[__n]; } *)__s2)
     : "cc");
  return __res;
}