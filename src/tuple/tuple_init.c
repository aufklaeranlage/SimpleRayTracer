#include "tuple.h"

#include "fptc.h"

t_tup	tup(fpt x, fpt y, fpt z, fpt w) {
	return ((t_tup) {x, y, z, w});
}

t_tup	point(fpt x, fpt y, fpt z) {
	return ((t_tup) {x, y, z, i2fpt(1)});
}

t_tup	vec3d(fpt x, fpt y, fpt z) {
	return ((t_tup) {x, y, z, i2fpt(0)});
}
