#include "tuple.h"

bool	tup_equal(const t_tup *a, cosnt t_tup *b) {
	return (a->x == b->x && a->y == b->y && a->z == b->z && a->w == b->w)
}
