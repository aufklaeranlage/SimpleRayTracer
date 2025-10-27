#include "fpn.h"

// Multiplies two fixed point number, returns the result, does not protect
// against over or underflow
inline t_fpn	fpn_mul(t_fpn A, t_fpn B) {
	return (((t_fpn)A * (t_fpn)B) >> FPN_FBITS);
}

// Divides two fixed point number, returns the result, does not protect
// against division by zero
inline t_fpn	fpn_div(t_fpn A, t_fpn B) {
	return (((t_fpn)A << FPN_FBITS) / (t_fpn)B);
}

// Returns the square root of the given number, or -1 in case of error
inline t_fpn	fpn_sqrt(t_fpn A) {
	int	invert;
	int	iter;
	int	l, i, s;

	invert = 0;
	iter = FPN_FBITS;
	if (A < 0)
		return (-1);
	if (A == 0 || A == FPN_ONE)
		return (A);
	if (A < FPN_ONE && A > 6) {
		invert = 1;
		A = fpn_div(FPN_ONE, A);
	}
	if (A > FPN_ONE) {
		s = A;
		iter = 0;
		while (s > 0) {
			s >>= 2;
			++iter;
		}
	}
	i = 0;
	l = (A >> 1) + 1;
	while (i < iter) {
		l = (l + fpn_div(A, l)) >> 1;
		++i;
	}
	if (invert)
		return (fpn_div(FPN_ONE, l));
	return (l);
}

inline t_fpn	fpn_sin(t_fpn fp) {
	int			sign;
	t_fpn		sqr, res;
	const t_fpn	SK[2] = {
		FPN_RCONST(7.61e-03),
		FPN_RCONST(1.6605e-01)
	};

	sign = 1;
	fp %= 2 * FPN_PI;
	if (fp < 0)
		fp = FPN_TWO_PI + fp;
	if ((fp > FPN_HALF_PI) && (fp <= FPN_PI)) {
		fp = FPN_PI - fp;
	} else if ((fp > FPN_PI) && (fp <= (FPN_PI + FPN_HALF_PI))) {
		fp = fp - FPN_PI;
		sign = -1;
	} else if (fp > (FPN_PI + FPN_HALF_PI)) {
		fp = (FPN_PI << 1) - fp;
		sign = -1;
	}
	sqr = fpn_mul(fp, fp);
	res = SK[0];
	res = fpn_mul(res, sqr);
	res -= SK[1];
	res = fpn_mul(res, sqr);
	res += FPN_ONE;
	res = fpn_mul(res, fp);
	return (sign * res);
}

inline t_fpn	fpn_cos(t_fpn A) {
	return (fpn_sin(FPN_HALF_PI - A));
}

inline t_fpn	fpn_tan(t_fpn A) {
	return (fpn_div(fpn_sin(A), fpn_cos(A)));
}

inline t_fpn	fpn_exp(t_fpn fp) {
	t_fpn xabs, k, z, R, xp;
	const t_fpn LN2 = FPN_RCONST(0.69314718055994530942);
	const t_fpn LN2_INV = FPN_RCONST(1.4426950408889634074);
	const t_fpn EXP_P[5] = {
		FPN_RCONST(1.66666666666666019037e-01),
		FPN_RCONST(-2.77777777770155933842e-03),
		FPN_RCONST(6.61375632143793436117e-05),
		FPN_RCONST(-1.65339022054652515390e-06),
		FPN_RCONST(4.13813679705723846039e-08),
	};

	if (fp == 0)
		return (FPN_ONE);
	xabs = FPN_ABS(fp);
	k = fpn_mul(xabs, LN2_INV);
	k += FPN_ONE_HALF;
	k &= ~FPN_FMASK;
	if (fp < 0)
		k = -k;
	fp -= fpn_mul(k, LN2);
	z = fpn_mul(fp, fp);
	/* Taylor */
	R = FPN_TWO +
	    fpn_mul(z, EXP_P[0] + fpn_mul(z, EXP_P[1] +
	    fpn_mul(z, EXP_P[2] + fpn_mul(z, EXP_P[3] +
	    fpn_mul(z, EXP_P[4])))));
	xp = FPN_ONE + fpn_div(fpn_mul(fp, FPN_TWO), R - fp);
	if (k < 0)
		k = FPN_ONE >> (-k >> FPN_FBITS);
	else
		k = FPN_ONE << (k >> FPN_FBITS);
	return (fpn_mul(k, xp));
}
inline t_fpn	fpn_ln(t_fpn x)
{
	t_fpn log2, xi;
	t_fpn f, s, z, w, R;
	const t_fpn LN2 = FPN_RCONST(0.69314718055994530942);
	const t_fpn LG[7] = {
		FPN_RCONST(6.666666666666735130e-01),
		FPN_RCONST(3.999999999940941908e-01),
		FPN_RCONST(2.857142874366239149e-01),
		FPN_RCONST(2.222219843214978396e-01),
		FPN_RCONST(1.818357216161805012e-01),
		FPN_RCONST(1.531383769920937332e-01),
		FPN_RCONST(1.479819860511658591e-01)
	};

	if (x < 0)
		return (0);
	if (x == 0)
		return 0xffffffff;

	log2 = 0;
	xi = x;
	while (xi > FPN_TWO) {
		xi >>= 1;
		log2++;
	}
	f = xi - FPN_ONE;
	s = fpn_div(f, FPN_TWO + f);
	z = fpn_mul(s, s);
	w = fpn_mul(z, z);
	R = fpn_mul(w, LG[1] + fpn_mul(w, LG[3]
	    + fpn_mul(w, LG[5]))) + fpn_mul(z, LG[0]
	    + fpn_mul(w, LG[2] + fpn_mul(w, LG[4]
	    + fpn_mul(w, LG[6]))));
	return (fpn_mul(LN2, (log2 << FPN_FBITS)) + f
	    - fpn_mul(s, f - R));
}

// Returns the power value (n^exp) of the given fixed point number
inline t_fpn	fpn_pow(t_fpn n, t_fpn exp) {
	if (exp == 0)
		return (FPN_ONE);
	if (n < 0)
		return (0);
	return (fpn_exp(fpn_mul(fpn_ln(n), exp)));
}
