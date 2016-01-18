#ifndef __MATH_H__
#define __MATH_H__

/* Unions */

typedef union
{
	float value;
    uint32_t word;
} ieee_float_shape_type;

typedef union
{
	double value;
	struct
	{
		uint32_t lsw;
		uint32_t msw;
	} parts;
	uint64_t word;
} ieee_double_shape_type;

typedef union
{
	long double value;
	struct
	{
		int sign_exponent:16;
		unsigned int empty:16;
		uint32_t msw;
		uint32_t lsw;
	} parts;
} ieee_long_double_shape_type;

/* Defines */

#define signbit(x) \
    (sizeof (x) == sizeof (float) \
    ? __signbitf (x) \
    : sizeof (x) == sizeof (double) \
    ? __signbit (x) : __signbitl (x))

#define isinf(x) \
    (sizeof (x) == sizeof (float) \
    ? __isinff (x) \
    : sizeof (x) == sizeof (double) \
    ? __isinf (x) : __isinfl (x))

#  define isnan(x) \
	(sizeof (x) == sizeof (float)                        \
	? __isnanf (x)                                  \
	: sizeof (x) == sizeof (double)                         \
? __isnan (x) : __isnanl (x))

#define GET_FLOAT_WORD(i,d) \
do { \
	ieee_float_shape_type gf_u; \
	gf_u.value = (d); \
	(i) = gf_u.word; \
} while (0)

#define GET_HIGH_WORD(i,d) \
do { \
	ieee_double_shape_type gh_u; \
	gh_u.value = (d); \
	(i) = gh_u.parts.msw; \
} while (0)

#define GET_LDOUBLE_WORDS(exp,ix0,ix1,d) \
do { \
	ieee_long_double_shape_type ew_u; \
	ew_u.value = (d); \
	(exp) = ew_u.parts.sign_exponent; \
	(ix0) = ew_u.parts.msw; \
	(ix1) = ew_u.parts.lsw; \
} while (0)

 
#define EXTRACT_WORDS(ix0,ix1,d) \
do { \
	ieee_double_shape_type ew_u; \
	ew_u.value = (d); \
	(ix0) = ew_u.parts.msw; \
	(ix1) = ew_u.parts.lsw; \
} while (0)

/* Inline functions */

inline
int
__signbitf (float x)
{
	int32_t hx;
 
	GET_FLOAT_WORD (hx, x);
	return hx & 0x80000000;
}

inline
int
__signbit (double x)
{
	int32_t hx;
 
	GET_HIGH_WORD (hx, x);
	return hx & 0x80000000;
}

inline
int
__signbitl (long double x)
{
  union { 
  	long double l; 
  	int i[3]; 
  } 
  u = { l: x };
  return (u.i[2] & 0x8000) != 0;
}

inline
int __isinfl(long double x)
{
	int32_t se,hx,lx;
	GET_LDOUBLE_WORDS(se,hx,lx,x);
	/* This additional ^ 0x80000000 is necessary because in Intel's
	   internal representation of the implicit one is explicit.  */
	lx |= (hx ^ 0x80000000) | ((se & 0x7fff) ^ 0x7fff);
	lx |= -lx;
	se &= 0x8000;
	return ~(lx >> 31) & (1 - (se >> 14));
}

inline
int
__isinff (float x)
{
	int32_t ix,t;
	GET_FLOAT_WORD(ix,x);
	t = ix & 0x7fffffff;
	t ^= 0x7f800000;
	t |= -t;
	return ~(t >> 31) & (ix >> 30);
}

inline
int
__isinf (double x)
{
	int32_t hx,lx;
	EXTRACT_WORDS(hx,lx,x);
	lx |= (hx & 0x7fffffff) ^ 0x7ff00000;
	lx |= -lx;
	return ~(lx >> 31) & (hx >> 30);
}
inline
int 
__isnanl(long double x)
{
	int32_t se,hx,lx;
	GET_LDOUBLE_WORDS(se,hx,lx,x);
	se = (se & 0x7fff) << 1;
	/* The additional & 0x7fffffff is required because Intel's
	   extended format has the normally implicit 1 explicit
	   present.  Sigh!  */
	lx |= hx & 0x7fffffff;
	se |= (uint32_t)(lx|(-lx))>>31;
	se = 0xfffe - se;
	return (int)((uint32_t)(se))>>16;
}

inline
int 
__isnanf(float x)
{
	int32_t ix;
	GET_FLOAT_WORD(ix,x);
	ix &= 0x7fffffff;
	ix = 0x7f800000 - ix;
	return (int)(((uint32_t)(ix))>>31);
}

inline
int 
__isnan(double x)
{
	int32_t hx,lx;
	EXTRACT_WORDS(hx,lx,x);
	hx &= 0x7fffffff;
	hx |= (uint32_t)(lx|(-lx))>>31;
	hx = 0x7ff00000 - hx;
	return (int)(((uint32_t)hx)>>31);
}

#endif