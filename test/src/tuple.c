#include "unity.h"

#include "tuple.h"
#include "fptc-ns.h"

static void	tup_point(void);

static void	tup_vec3d(void);

static void	plain_point(void);

static void	plain_vec3d(void);

static void	test_add(void);

static void	test_sub_pt(void);

static void	test_sub_vec(void);

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
	RUN_TEST(test_add);
	RUN_TEST(test_sub_pt);
	RUN_TEST(test_sub_vec);
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

static void	test_add(void) {
	t_tup	t1 = tup(i2fpt(3), i2fpt(-2), i2fpt(5), i2fpt(1));
	t_tup	t2 = tup(i2fpt(-2), i2fpt(3), i2fpt(1), i2fpt(0));

	tup_add(&t1, &t2);
	TEST_ASSERT_EQUAL_INT32(i2fpt(1), t1.x);
	TEST_ASSERT_EQUAL_INT32(i2fpt(1), t1.y);
	TEST_ASSERT_EQUAL_INT32(i2fpt(6), t1.z);
	TEST_ASSERT_EQUAL_INT32(i2fpt(1), t1.w);
}

static void	test_sub_pt(void) {
	t_tup	p1 = point(i2fpt(3), i2fpt(2), i2fpt(1));
	t_tup	p2 = point(i2fpt(5), i2fpt(6), i2fpt(7));

	t_tup	test = vec3d(i2fpt(-2), i2fpt(-4), i2fpt(-6));

	TEST_ASSERT_TRUE(tup_equal(tup_sub(&p1, &p2), &test));
}

static void	test_sub_vec(void) {
	t_tup	p1 = point(i2fpt(3), i2fpt(2), i2fpt(1));
	t_tup	v2 = vec3d(i2fpt(5), i2fpt(6), i2fpt(7));

	t_tup	test = point(i2fpt(-2), i2fpt(-4), i2fpt(-6));

	TEST_ASSERT_TRUE(tup_equal(tup_sub(&p1, &v2), &test));
}
