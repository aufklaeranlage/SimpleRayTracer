#include "tuple.h"

#include "fptc-ns.h"

// !!! WARNING !!!
// All of these functions perform no memory checks to make sure that no invalid
// pointers are being passed

// Takes two pointers for tuples and adds the second onto the first.
// Returns the to the first parameter.
t_tup	*tup_add(t_tup *a, const t_tup *b) {
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	a->w += b->w;
	return (a);
}

// Takes two pointers for tuples and subtracts the second from the first.
// Returns the to the first parameter.
t_tup	*tup_sub(t_tup *a, const t_tup *b) {
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
	a->w -= b->w;
	return (a);
}

// Takes a pointer to a tuple and negates the tuple pointed to by the pointer.
// Returns the pointer to the first parameter.
t_tup	*tup_neg(t_tup *a) {
	a->x = -a->x;
	a->y = -a->y;
	a->z = -a->z;
	a->w = -a->w;
	return (a);
}

// Takes a pointer to a tuple and a scaling factor. Multiplies all elments in
// the tuple by the scaling factor.
// Returns the pointer to the first parameter.
t_tup	*tup_scale(t_tup *a, fpt scale) {
	a->x = fpt_mul(a->x, scale);
	a->y = fpt_mul(a->y, scale);
	a->z = fpt_mul(a->z, scale);
	a->w = fpt_mul(a->w, scale);
	return (a);
}

// Returns the magnitude of a tuple. Only takes x, y, and z of the tuple into
// account, since it's supposed to be used only with vectors.
fpt		tup_magn(const t_tup *a) {
	return (fpt_sqrt(
		fpt_add(fpt_mul(a->x, a->x),
			fpt_add(fpt_mul(a->y, a->y),
				(fpt_mul(a->z, a->z))))));
}
