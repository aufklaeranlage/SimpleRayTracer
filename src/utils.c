#include "utils.h"

#include "fptc-ns.h"
#include <stdbool.h>

bool	fpt_equal(fpt a, fpt b) {
	if (fpt_abs(fpt_sub(a, b)) < EPSILON)
		return (true);
	return (false);
}
