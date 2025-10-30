#include "matrix.h"

#include "fptc-ns.h"

t_mat	mat(fpt m[4][4]) {
	t_mat	ret;

	ret.m[0][0] = m[0][0];
	ret.m[0][1] = m[0][1];
	ret.m[0][2] = m[0][2];
	ret.m[0][3] = m[0][3];
	ret.m[1][0] = m[1][0];
	ret.m[1][1] = m[1][1];
	ret.m[1][2] = m[1][2];
	ret.m[1][3] = m[1][3];
	ret.m[2][0] = m[2][0];
	ret.m[2][1] = m[2][1];
	ret.m[2][2] = m[2][2];
	ret.m[2][3] = m[2][3];
	ret.m[3][0] = m[3][0];
	ret.m[3][1] = m[3][1];
	ret.m[3][2] = m[3][2];
	ret.m[3][3] = m[3][3];
	return (ret);
}
