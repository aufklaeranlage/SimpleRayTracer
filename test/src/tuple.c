#include "unity.h"

#include "tuple.h"

static void	tuple_point(void);

static void	tuple_vector(void);

void setUp(void) {

}

void tearDown(void) {

}

int	main(void) {
	UNITY_BEGIN();
	RUN_TEST(tuple_point);
	RUN_TEST(tuple_vector);
	return UNITY_END();
}

static void	tuple_point(void) {
	t_tuple	t;

	t = tuple(FPN_FROMFLT(4.3),FPN_FROMFLT(-4.2),FPN_FROMFLT(3.1),FPN_FROMFLT(1.0));
	TEST_ASSERT_EQUAL_INT32(FPN_FROMFLT(4.3), t.x);
	TEST_ASSERT_EQUAL_INT32(FPN_FROMFLT(-4.2), t.y);
	TEST_ASSERT_EQUAL_INT32(FPN_FROMFLT(3.1), t.z);
	TEST_ASSERT_EQUAL_INT32(FPN_FROMFLT(1.0), t.w);
}

static void	tuple_vector(void) {
	t_tuple	t;

	t = tuple(FPN_FROMFLT(4.3),FPN_FROMFLT(-4.2),FPN_FROMFLT(3.1),FPN_FROMFLT(0.0));
	TEST_ASSERT_EQUAL_INT32(FPN_FROMFLT(4.3), t.x);
	TEST_ASSERT_EQUAL_INT32(FPN_FROMFLT(-4.2), t.y);
	TEST_ASSERT_EQUAL_INT32(FPN_FROMFLT(3.1), t.z);
	TEST_ASSERT_EQUAL_INT32(FPN_FROMFLT(0.0), t.w);
}
