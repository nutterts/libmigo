/* runtime_panicstring.h -- Golos runtime error */

#include "runtime.h"

void
runtime_panicstring(const char *s)
{
  puts("RT-Panic: ");
  puts(s);
  putch(10);
  runtime_abort();
}