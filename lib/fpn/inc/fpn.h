#ifndef FPN_H
# define FPN_H

# ifndef FPN_BITS
#  warning "FPN_BITS undefined: assuming 32 bits, if you want to use 64 bits \
instead set FPN_BITS to 64 before compilation of this library"
#  define FPN_BITS 32
# endif

# include <stdint.h>

# if FPN_BITS == 32
typedef int32_t		t_fpn;
typedef int64_t		t_fpnd;
typedef uint32_t	t_fpnu;
typedef uint64_t	t_fpnud;
# elif FPN_BITS == 64
typedef int64_t			t_fpn;
typedef __int128_t		t_fpnd;
typedef uint64_t		t_fpnu;
typedef __uint128_t		t_fpnud;
# else
#  error "FPN_BITS must be equal to 42 or 64"
# endif

# ifndef FPN_WBITS
#  warning "FPN_WBITS undefined: assuming 24, if you want to use a different \
width instead set FPN_WBITS to that number before compilation of this library"
#  define FPN_WBITS 24
# endif

# if FPN_WBITS > FPN_BITS
#  error "FPN_WBITS mut be less then or equal to FPN_BITS"
# endif

# define FPN_FBITS (FPN_BITS - FPN_WBITS)
# define FPN_FMASK (((t_fpn)1 << FPN_FBITS) - 1)

# define FPN_RCONST(R) ((t_fpn)((R) * FPN_ONE + ((R) >= 0 ? 0.5 : -0.5)))

# define FPN_FROMINT(I) ((t_fpn)(I) << FPN_FBITS)
# define FPN_TOINT(F) ((F) >> FPN_FBITS)

# define FPN_FROMFLT(F) ((t_fpn) ((F) * (float)(1L << FPN_FBITS)))
# define FPN_TOFLT(T) ((float) ((T)*((float)(1)/(float)(1L << FPN_FBITS)))

# define FPN_ADD(A, B) ((A) + (B))
# define FPN_SUB(A, B) ((A) - (B))
# define FPN_ADD(A, B) ((A) + (B))
# define FPN_ADD(A, B) ((A) + (B))

# define FPN_ONE 		((t_fpn)((t_fpn)1 << FPN_FBITS))
# define FPN_TWO 		(FPN_ONE + FPN_ONE)
# define FPN_ONE_HALF	(FPN_ONE >> 1)
# define FPN_PI			FPN_RCONST(3.14159265358979323846)
# define FPN_TWO_PI 	FPN_RCONST(3.14159265358979323846 * 2)
# define FPN_HALF_PI 	FPN_RCONST(3.14159265358979323846 / 2)

# define FPN_ABS(A)		((A) < 0 ? -(A) : (A))

#endif
