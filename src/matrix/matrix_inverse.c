#include "matrix.h"

#include "utils.h"

#include "fptc-ns.h"
#include <stdbool.h>

static void	divide_row(t_mat *m, int row, fpt scale, t_mat *inv) {
	m->m[row][0] = fpt_div(m->m[row][0], scale);
	m->m[row][1] = fpt_div(m->m[row][1], scale);
	m->m[row][2] = fpt_div(m->m[row][2], scale);
	m->m[row][3] = fpt_div(m->m[row][3], scale);
	inv->m[row][0] = fpt_div(inv->m[row][0], scale);
	inv->m[row][1] = fpt_div(inv->m[row][1], scale);
	inv->m[row][2] = fpt_div(inv->m[row][2], scale);
	inv->m[row][3] = fpt_div(inv->m[row][3], scale);
}

static void sub_scaled_row(t_mat *m, int dest, int src, fpt scale, t_mat *inv) {
	m->m[dest][0] = fpt_sub(m->m[dest][0], fpt_mul(m->m[src][0], scale));
	m->m[dest][1] = fpt_sub(m->m[dest][1], fpt_mul(m->m[src][1], scale));
	m->m[dest][2] = fpt_sub(m->m[dest][2], fpt_mul(m->m[src][2], scale));
	m->m[dest][3] = fpt_sub(m->m[dest][3], fpt_mul(m->m[src][3], scale));
	inv->m[dest][0] = fpt_sub(inv->m[dest][0], fpt_mul(inv->m[src][0], scale));
	inv->m[dest][1] = fpt_sub(inv->m[dest][1], fpt_mul(inv->m[src][1], scale));
	inv->m[dest][2] = fpt_sub(inv->m[dest][2], fpt_mul(inv->m[src][2], scale));
	inv->m[dest][3] = fpt_sub(inv->m[dest][3], fpt_mul(inv->m[src][3], scale));
}

static void	swap_rows(t_mat *m, int r1, int r2) {
	fpt	tmp[4];

	tmp[0] = m->m[r1][0];
	tmp[1] = m->m[r1][1];
	tmp[2] = m->m[r1][2];
	tmp[3] = m->m[r1][3];
	m->m[r1][0] = m->m[r2][0];
	m->m[r1][1] = m->m[r2][1];
	m->m[r1][2] = m->m[r2][2];
	m->m[r1][3] = m->m[r2][3];
	m->m[r2][0] = tmp[0];
	m->m[r2][1] = tmp[1];
	m->m[r2][2] = tmp[2];
	m->m[r2][3] = tmp[3];
}

static void	set_pivot(t_mat *m1, int pos, t_mat *inv) {
	fpt	tmp;
	int	pivot;
	fpt	pivotSize;
	int	i;

	i = pos + 1;
	pivot = i;
	pivotSize = m1->m[pivot][pivot];
	if (pivotSize < 0)
		pivotSize *= -1;
	while (i < 4) {
		tmp = m1->m[i][pos];
		if (tmp < 0)
			tmp *= -1;
		if (!fpt_equal(tmp, 0) && tmp > pivotSize) {
			pivot = i;
			pivotSize = tmp;
		}
		++i;
	}
	if (pivot == pos)
		return ;
	swap_rows(m1, pivot, pos);
	swap_rows(inv, pivot, pos);
}

static bool	zero_under_diagonal(t_mat *m1, int pos, t_mat *inv) {
	fpt	scale;
	int	i;

	i = pos + 1;
	while (i < 4) {
		if (m1->m[pos][pos] == 0)
			return (false);
		scale = fpt_div(m1->m[i][pos], m1->m[pos][pos]);
		sub_scaled_row(m1, i, pos, scale, inv);
		m1->m[i][pos] = 0;
		++i;
	}
	return (true);
}

static bool	equalize_diagonal(t_mat *m1, t_mat *inv) {
	int	i;
	fpt	divisor;

	i = 0;
	while (i < 4) {
		if (m1->m[i][i] == 0)
			return (false);
		divisor = m1->m[i][i];
		divide_row(m1, i, divisor, inv);
		m1->m[i][i] = FPT_ONE;
		++i;
	}
	return (true);
}

static bool zero_over_diagonal(t_mat *m1, int pos, t_mat *inv) {
	fpt	scale;
	int	i;

	i = 0;
	while (i < pos) {
		if (m1->m[pos][pos] == 0)
			return (false);
		scale = fpt_mul(m1->m[i][pos], m1->m[pos][pos]);
		sub_scaled_row(m1, i, pos, scale, inv);
		m1->m[i][pos] = 0;
		++i;
	}
	return (true);
}

bool	mat_inverse(t_mat *m1) {
	t_mat	inv;
	int		i;

	inv = mat_identity();
	i = 0;
	while (i < 3) {
		set_pivot(m1, i, &inv);
		if (!zero_under_diagonal(m1, i, &inv))
			return (false);
		++i;
	}
	if (!equalize_diagonal(m1, &inv))
		return (false);
	i = 3;
	while (i > 0) {
		if (!zero_over_diagonal(m1, i, &inv))
			return (false);
		--i;
	}
	*m1 = inv;
	return (true);
}
