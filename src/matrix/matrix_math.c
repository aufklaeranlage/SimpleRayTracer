#include "matrix.h"

#include "fptc-ns.h"

t_mat	*mat_mul(t_mat *a, const t_mat *b) {
	t_mat	m;

	m.m[0][0] = fpt_mul(a->m[0][0], b->m[0][0]) + fpt_mul(a->m[0][1], b->m[1][0]) +
		fpt_mul(a->m[0][2], b->m[2][0]) + fpt_mul(a->m[0][3], b->m[3][0]);
	m.m[0][1] = fpt_mul(a->m[0][0], b->m[0][1]) + fpt_mul(a->m[0][1], b->m[1][1]) +
		fpt_mul(a->m[0][2], b->m[2][1]) + fpt_mul(a->m[0][3], b->m[3][1]);
	m.m[0][2] = fpt_mul(a->m[0][0], b->m[0][2]) + fpt_mul(a->m[0][1], b->m[1][2]) +
		fpt_mul(a->m[0][2], b->m[2][2]) + fpt_mul(a->m[0][3], b->m[3][2]);
	m.m[0][3] = fpt_mul(a->m[0][0], b->m[0][3]) + fpt_mul(a->m[0][1], b->m[1][3]) +
		fpt_mul(a->m[0][2], b->m[2][3]) + fpt_mul(a->m[0][3], b->m[3][3]);
	m.m[1][0] = fpt_mul(a->m[1][0], b->m[0][0]) + fpt_mul(a->m[1][1], b->m[1][0]) +
		fpt_mul(a->m[1][2], b->m[2][0]) + fpt_mul(a->m[1][3], b->m[3][0]);
	m.m[1][1] = fpt_mul(a->m[1][0], b->m[0][1]) + fpt_mul(a->m[1][1], b->m[1][1]) +
		fpt_mul(a->m[1][2], b->m[2][1]) + fpt_mul(a->m[1][3], b->m[3][1]);
	m.m[1][2] = fpt_mul(a->m[1][0], b->m[0][2]) + fpt_mul(a->m[1][1], b->m[1][2]) +
		fpt_mul(a->m[1][2], b->m[2][2]) + fpt_mul(a->m[1][3], b->m[3][2]);
	m.m[1][3] = fpt_mul(a->m[1][0], b->m[0][3]) + fpt_mul(a->m[1][1], b->m[1][3]) +
		fpt_mul(a->m[1][2], b->m[2][3]) + fpt_mul(a->m[1][3], b->m[3][3]);
	m.m[2][0] = fpt_mul(a->m[2][0], b->m[0][0]) + fpt_mul(a->m[2][1], b->m[1][0]) +
		fpt_mul(a->m[2][2], b->m[2][0]) + fpt_mul(a->m[2][3], b->m[3][0]);
	m.m[2][1] = fpt_mul(a->m[2][0], b->m[0][1]) + fpt_mul(a->m[2][1], b->m[1][1]) +
		fpt_mul(a->m[2][2], b->m[2][1]) + fpt_mul(a->m[2][3], b->m[3][1]);
	m.m[2][2] = fpt_mul(a->m[2][0], b->m[0][2]) + fpt_mul(a->m[2][1], b->m[1][2]) +
		fpt_mul(a->m[2][2], b->m[2][2]) + fpt_mul(a->m[2][3], b->m[3][2]);
	m.m[2][3] = fpt_mul(a->m[2][0], b->m[0][3]) + fpt_mul(a->m[2][1], b->m[1][3]) +
		fpt_mul(a->m[2][2], b->m[2][3]) + fpt_mul(a->m[2][3], b->m[3][3]);
	m.m[3][0] = fpt_mul(a->m[3][0], b->m[0][0]) + fpt_mul(a->m[3][1], b->m[1][0]) +
		fpt_mul(a->m[3][2], b->m[2][0]) + fpt_mul(a->m[3][3], b->m[3][0]);
	m.m[3][1] = fpt_mul(a->m[3][0], b->m[0][1]) + fpt_mul(a->m[3][1], b->m[1][1]) +
		fpt_mul(a->m[3][2], b->m[2][1]) + fpt_mul(a->m[3][3], b->m[3][1]);
	m.m[3][2] = fpt_mul(a->m[3][0], b->m[0][2]) + fpt_mul(a->m[3][1], b->m[1][2]) +
		fpt_mul(a->m[3][2], b->m[2][2]) + fpt_mul(a->m[3][3], b->m[3][2]);
	m.m[3][3] = fpt_mul(a->m[3][0], b->m[0][3]) + fpt_mul(a->m[3][1], b->m[1][3]) +
		fpt_mul(a->m[3][2], b->m[2][3]) + fpt_mul(a->m[3][3], b->m[3][3]);
	*a = m;
	return (a);
}

t_mat	*mat_transpose(t_mat *a) {
	t_mat	tmp;

	tmp = mat((fpt[4][4]) {
		 {a->m[0][0], a->m[1][0], a->m[2][0], a->m[3][0]},
		 {a->m[0][1], a->m[1][1], a->m[2][1], a->m[3][1]},
		 {a->m[0][2], a->m[1][2], a->m[2][2], a->m[3][2]},
		 {a->m[0][3], a->m[1][3], a->m[2][3], a->m[3][3]}
	});
	*a = tmp;
	return (a);
}
