#include "runtime.h"
#include "unwind.h"

_Unwind_Reason_Code
__gccgo_personality_v0(int, _Unwind_Action, _Unwind_Exception_Class,
		      struct _Unwind_Exception *, struct _Unwind_Context *)
  __attribute__ ((no_split_stack, flatten));

_Unwind_Reason_Code
__gccgo_personality_v0(int version,
		      _Unwind_Action actions,
		      _Unwind_Exception_Class exception_class,
		      struct _Unwind_Exception *ue_header,
		      struct _Unwind_Context *context)
{
	runtime_panicstring("__gccgo_personality_v0 not implemented!!");
}