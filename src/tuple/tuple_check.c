#include "tuple.h"

#include <stdbool.h>

bool	tup_equal(const t_tup *a, const t_tup *b) {
	return (a->x == b->x && a->y == b->y && a->z == b->z && a->w == b->w);
}
