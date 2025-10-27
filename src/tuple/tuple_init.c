#include "tuple.h"

#include "fpn.h"

t_tuple	tuple(t_fpn x, t_fpn y, t_fpn z, t_fpn w) {
	return ((t_tuple) {x, y, z, w});
}
