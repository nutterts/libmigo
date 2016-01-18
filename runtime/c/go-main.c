/* The main function.  */

#include "runtime.h"

extern void main_init(void) __asm__ ("__go_init_main");
extern void main_main(void) __asm__ ("main.main");

void
main (void)
{
  textmode_init();
  main_init();
  main_main();
}
