#ifndef TUPLE_H
# define TUPLE_H

# include <stdio.h>	// needed for sscanf in ftpc.h
# include "fptc.h"

typedef struct s_tup {
	fpt	x;
	fpt	y;
	fpt	z;
	fpt	w;
}	t_tup;

// Creation

t_tup	tup(fpt x, fpt y, fpt z, fpt w);

t_tup	point(fpt x, fpt y, fpt z);

t_tup	vec3d(fpt x, fpt y, fpt z);

#endif
