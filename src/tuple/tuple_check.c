#include "tuple.h"

#include <stdbool.h>

bool	tup_equal(const t_tup *a, const t_tup *b) {
	return (a->x == b->x && a->y == b->y && a->z == b->z && a->w == b->w);
}

bool	fpt_equal(fpt a, fpt b) {
	if (fpt_abs(fpt_sub(a, b)) < EPSILON)
		return (true);
	return (false);
}
