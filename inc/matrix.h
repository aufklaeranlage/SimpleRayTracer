#ifndef MATRIX_H
# define MATRIX_H

# include "fptc-ns.h"

# include <stdbool.h>

/* Limited to 4x4 max atm */
typedef struct s_mat {
	fpt	m[4][4];
}	t_mat;

/* Creation */

t_mat	mat(fpt m[4][4]);

/* Checks */

bool	mat_equal(const t_mat *a, const t_mat *b);

/* Math */

t_mat	*mat_mul(t_mat *a, const t_mat *b);

#endif
