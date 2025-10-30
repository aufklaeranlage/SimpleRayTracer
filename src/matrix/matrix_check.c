#include "matrix.h"

#include "utils.h"

#include "fptc-ns.h"
#include <stdbool.h>

bool	mat_equal(const t_mat *a, const t_mat *b) {
	return (fpt_equal(a->m[0][0], b->m[0][0]) &&
		 fpt_equal(a->m[0][1], b->m[0][1]) &&
		 fpt_equal(a->m[0][2], b->m[0][2]) &&
		 fpt_equal(a->m[0][3], b->m[0][3]) &&
		 fpt_equal(a->m[1][0], b->m[1][0]) &&
		 fpt_equal(a->m[1][1], b->m[1][1]) &&
		 fpt_equal(a->m[1][2], b->m[1][2]) &&
		 fpt_equal(a->m[1][3], b->m[1][3]) &&
		 fpt_equal(a->m[2][0], b->m[2][0]) &&
		 fpt_equal(a->m[2][1], b->m[2][1]) &&
		 fpt_equal(a->m[2][2], b->m[2][2]) &&
		 fpt_equal(a->m[2][3], b->m[2][3]) &&
		 fpt_equal(a->m[3][0], b->m[3][0]) &&
		 fpt_equal(a->m[3][1], b->m[3][1]) &&
		 fpt_equal(a->m[3][2], b->m[3][2]) &&
		 fpt_equal(a->m[3][3], b->m[3][3]));
}
