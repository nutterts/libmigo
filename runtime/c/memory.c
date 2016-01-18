
#include "runtime.h"

/* A simple abrk style malloc to get things up and running */

int32_t runtime_sbrk_pos = -1;
int32_t runtime_sbrk_return;

void *runtime_sbrk(intptr_t increment)
{
	if (runtime_sbrk_pos == -1) runtime_sbrk_pos = (uintptr_t) &runtime_sbrk_top;
	if (increment == 0) return 0;
	if ((runtime_sbrk_pos + increment) <= (uintptr_t) &runtime_sbrk_bottom) 
	{
		runtime_sbrk_return = runtime_sbrk_pos;
		runtime_sbrk_pos += increment;
		return (void *) runtime_sbrk_return;
	}
	else
	{
		errno = ENOMEM;
		return (void *) -1;
	}
}