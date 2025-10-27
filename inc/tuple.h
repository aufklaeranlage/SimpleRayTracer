#ifndef TUPLE_H
# define TUPLE_H

# include "fpn.h"

typedef struct s_tuple {
	t_fpn	x;
	t_fpn	y;
	t_fpn	z;
	t_fpn	w;
}	t_tuple;

t_tuple	tuple(t_fpn x, t_fpn y, t_fpn z, t_fpn w);

#endif
