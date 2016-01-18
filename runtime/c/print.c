#include "runtime.h"
#include "math.h"

/* Readable names */
#define runtime_printstring	__go_print_string
#define runtime_printint	__go_print_int64
#define runtime_printbool	__go_print_bool
#define runtime_printfloat	__go_print_double

/* Functions */
static void
gwrite(const void *v, intgo n)
{
	int i;
	for (i = 0; i < n; i++)
		putch(*((unsigned char*)v + i));
}

void
runtime_printstring(String v)
{
	if(v.len > 0)
		gwrite(v.str, v.len);
}

void
__go_print_nl(void)
{
	putch(10);
}

void
runtime_printint(int64_t v)
{
	char *str = malloc(22);
	itoa(v, str, 10);
	puts(str);
	free(str);
}

void
runtime_printbool(_Bool v)
{
	if(v) {
		gwrite("true", 4);
		return;
	}
	gwrite("false", 5);
}

void
runtime_printfloat(double v)
{
	byte buf[20];
	int32 e, s, i, n;
	float64 h;

	if(isnan(v)) {
		gwrite("NaN", 3);
		return;
	}
	if(isinf(v)) {
		if(signbit(v)) {
			gwrite("-Inf", 4);
		} else {
			gwrite("+Inf", 4);
		}
		return;
	}

	n = 7;	// digits printed
	e = 0;	// exp
	s = 0;	// sign
	if(v == 0) {
		if(isinf(1/v) && 1/v < 0)
			s = 1;
	} else {
		// sign
		if(v < 0) {
			v = -v;
			s = 1;
		}

		// normalize
		while(v >= 10) {
			e++;
			v /= 10;
		}
		while(v < 1) {
			e--;
			v *= 10;
		}

		// round
		h = 5;
		for(i=0; i<n; i++)
			h /= 10;

		v += h;
		if(v >= 10) {
			e++;
			v /= 10;
		}
	}

	// format +d.dddd+edd
	buf[0] = '+';
	if(s)
		buf[0] = '-';
	for(i=0; i<n; i++) {
		s = v;
		buf[i+2] = s+'0';
		v -= s;
		v *= 10.;
	}
	buf[1] = buf[2];
	buf[2] = '.';

	buf[n+2] = 'e';
	buf[n+3] = '+';
	if(e < 0) {
		e = -e;
		buf[n+3] = '-';
	}

	buf[n+4] = (e/100) + '0';
	buf[n+5] = (e/10)%10 + '0';
	buf[n+6] = (e%10) + '0';
	gwrite(buf, n+7);
}