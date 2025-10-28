#include "tuple.h"

#include <stdbool.h>

bool	tup_equal(const t_tup *a, const t_tup *b) {
	return (fpt_equal(a->x, b->x) &&
		fpt_equal(a->y, b->y) &&
		fpt_equal(a->z, b->z) &&
		fpt_equal(a->w, b->w));
}

bool	fpt_equal(fpt a, fpt b) {
	if (fpt_abs(fpt_sub(a, b)) < EPSILON)
		return (true);
	return (false);
}
