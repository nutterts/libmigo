#include "runtime.h"

void
runtime_abort(void)
{
	abort();	// Proper abort
	while(1);   // Never reached but silences 'no return, returns' warnings.
}