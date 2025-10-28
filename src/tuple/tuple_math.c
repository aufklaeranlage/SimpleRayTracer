#include "tuple.h"

#include "fptc-ns.h"

// !!! WARNING !!!
// All of these functions perform no memory checks to make sure that no invalid
// pointers are being passed

// Takes two pointers for tuples and adds the second onto the first.
// Returns the added value of the two in the tuple pointed to by the first
// pointer.
t_tup	*tup_add(t_tup *a, const t_tup *b) {
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	a->w += b->w;
	return (a);
}

// Takes two pointers for tuples and subtracts the second from the first.
// Returns the added value of the two in the tuple pointed to by the first
// pointer.
t_tup	*tup_sub(t_tup *a, const t_tup *b) {
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
	a->w -= b->w;
	return (a);
}
