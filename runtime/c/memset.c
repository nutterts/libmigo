#include "runtime.h"

void *
memset (void *dstpp, int c, size_t len)
{
  int d0;
  unsigned long int dstp = (unsigned long int) dstpp;

  /* This explicit register allocation
     improves code very much indeed.  */
  register op_t x asm("ax");

  x = (unsigned char) c;

  /* Clear the direction flag, so filling will move forward.  */
  asm volatile("cld");

  /* This threshold value is optimal.  */
  if (len >= 12)
    {
      /* Fill X with four copies of the char we want to fill with.  */
      x |= (x << 8);
      x |= (x << 16);

      /* Adjust LEN for the bytes handled in the first loop.  */
      len -= (-dstp) % OPSIZ;

      /* There are at least some bytes to set.
	 No need to test for LEN == 0 in this alignment loop.  */

      /* Fill bytes until DSTP is aligned on a longword boundary.  */
      asm volatile("rep\n"
		   "stosb" /* %0, %2, %3 */ :
		   "=D" (dstp), "=c" (d0) :
		   "0" (dstp), "1" ((-dstp) % OPSIZ), "a" (x) :
		   "memory");

      /* Fill longwords.  */
      asm volatile("rep\n"
		   "stosl" /* %0, %2, %3 */ :
		   "=D" (dstp), "=c" (d0) :
		   "0" (dstp), "1" (len / OPSIZ), "a" (x) :
		   "memory");
      len %= OPSIZ;
    }

  /* Write the last few bytes.  */
  asm volatile("rep\n"
	       "stosb" /* %0, %2, %3 */ :
	       "=D" (dstp), "=c" (d0) :
	       "0" (dstp), "1" (len), "a" (x) :
	       "memory");

  return dstpp;
}