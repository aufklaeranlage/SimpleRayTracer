#include "unity.h"

#include "tuple.h"
#include "fptc.h"

static void	tup_point(void);

static void	tup_vec3d(void);

static void	plain_point(void);

static void	plain_vec3d(void);

void setUp(void) {

}

void tearDown(void) {

}

int	main(void) {
	UNITY_BEGIN();
	RUN_TEST(tup_point);
	RUN_TEST(tup_vec3d);
	RUN_TEST(plain_point);
	RUN_TEST(plain_vec3d);
	return UNITY_END();
}

static void	tup_point(void) {
	t_tup	t;

	t = tup(fl2fpt(4.3),fl2fpt(-4.2),fl2fpt(3.1),fl2fpt(1.0));
	TEST_ASSERT_EQUAL_INT32(fl2fpt(4.3), t.x);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(-4.2), t.y);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(3.1), t.z);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(1.0), t.w);
}

static void	tup_vec3d(void) {
	t_tup	t;

	t = tup(fl2fpt(4.3),fl2fpt(-4.2),fl2fpt(3.1),fl2fpt(0.0));
	TEST_ASSERT_EQUAL_INT32(fl2fpt(4.3), t.x);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(-4.2), t.y);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(3.1), t.z);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(0.0), t.w);
}

static void	plain_point(void) {
	t_tup	t;

	t = point(i2fpt(4), i2fpt(-4), i2fpt(3));
	TEST_ASSERT_EQUAL_INT32(i2fpt(4), t.x);
	TEST_ASSERT_EQUAL_INT32(i2fpt(-4), t.y);
	TEST_ASSERT_EQUAL_INT32(i2fpt(3), t.z);
	TEST_ASSERT_EQUAL_INT32(i2fpt(1), t.w);
}

static void	plain_vec3d(void) {
	t_tup	t;

	t = vec3d(i2fpt(4), i2fpt(-4), i2fpt(3));
	TEST_ASSERT_EQUAL_INT32(i2fpt(4), t.x);
	TEST_ASSERT_EQUAL_INT32(i2fpt(-4), t.y);
	TEST_ASSERT_EQUAL_INT32(i2fpt(3), t.z);
	TEST_ASSERT_EQUAL_INT32(i2fpt(0), t.w);
}
