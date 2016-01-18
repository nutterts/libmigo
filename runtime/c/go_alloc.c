#include "runtime.h"

void*
__go_alloc(uintptr size)
{
	return runtime_malloc(size);
}