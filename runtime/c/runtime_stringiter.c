#include "runtime.h"
#include "go-string.h"

#define charntorune(pv, str, len) __go_get_rune(str, len, pv)

enum
{
	Runeself	= 0x80,
};

intgo runtime_stringiter(String s, intgo k) __asm__ ("runtime.stringiter");
intgo runtime_stringiter(String s, intgo k)
{
	intgo retk;
	int32 l;

	if(k >= s.len) {
		// retk=0 is end of iteration
		retk = 0;
		goto out;
	}

	l = s.str[k];
	if(l < Runeself) {
		retk = k+1;
		goto out;
	}

	// multi-char rune
	retk = k + charntorune(&l, s.str+k, s.len-k);

out:
return retk;
}

struct runtime_stringiter2_ret {
	intgo retk;
	int32 retv;
};

struct runtime_stringiter2_ret runtime_stringiter2(String s, intgo k) __asm__ ("runtime.stringiter2");
struct runtime_stringiter2_ret runtime_stringiter2(String s, intgo k)
{
	intgo retk;
	int32 retv;

	if(k >= s.len) {
		// retk=0 is end of iteration
		retk = 0;
		retv = 0;
		goto out;
	}

	retv = s.str[k];
	if(retv < Runeself) {
		retk = k+1;
		goto out;
	}

	// multi-char rune
	retk = k + charntorune(&retv, s.str+k, s.len-k);

out:
  {
    struct runtime_stringiter2_ret __ret;
    __ret.retk = retk;
    __ret.retv = retv;
    return __ret;
  }
}
