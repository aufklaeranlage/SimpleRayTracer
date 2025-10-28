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
		fpt_mul(a->x, a->x) + fpt_mul(a->y, a->y) + fpt_mul(a->z, a->z)));
}

// Takes a pointer to a tuple, normalizes the tuple in place.
// Returns the pointer to the first parameter.
t_tup	*tup_norm(t_tup *a) {
	fpt	magnitude;
	
	magnitude = tup_magn(a);
	return (tup_scale(a, fpt_div(FPT_ONE, magnitude)));
}

// Takes two pointers to tuples and returns their dot product.
// Doesn't take w into account, since this should only be used on vectors.
fpt		tup_dot(const t_tup *a, const t_tup *b) {
	return (fpt_mul(a->x, b->x) + fpt_mul(a->y, b->y) + fpt_mul(a->z, b->z));
}

// Takes two pointers to tuples and returns calculates their cross product,
// the result get's stored in the first tuple.
// Returns the pointer to the first parameter.
t_tup	*tup_cross(t_tup *a, const t_tup *b) {
	t_tup	v1;

	v1 = vec3d(fpt_sub(fpt_mul(a->y, b->z), fpt_mul(a->z, b->y)),
			fpt_sub(fpt_mul(a->z, b->x), fpt_mul(a->x, b->z)),
			fpt_sub(fpt_mul(a->x, b->y), fpt_mul(a->y, b->x)));
	*a = v1;
	return (a);
}

// Takes two pointers to tuples and multiplies the second with the first.
// Returns the to the first parameter.
t_tup	*tup_mul(t_tup *a, const t_tup *b) {
	a->x = fpt_mul(a->x, b->x);
	a->y = fpt_mul(a->y, b->y);
	a->z = fpt_mul(a->z, b->z);
	a->w = fpt_mul(a->w, b->w);
	return (a);
}
