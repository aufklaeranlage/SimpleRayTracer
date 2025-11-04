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

t_mat	mat_copy(const t_mat *m);

t_mat	mat_identity(void);

/* Checks */

bool	mat_equal(const t_mat *a, const t_mat *b);

/* Math */

t_mat	*mat_mul(t_mat *a, const t_mat *b);

t_mat	*mat_transpose(t_mat *a);

bool	mat_inverse(t_mat *m1);

#endif
