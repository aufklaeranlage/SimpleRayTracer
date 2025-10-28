#include "unity.h"

#include "tuple.h"
#include "fptc-ns.h"

static void	tup_point(void);

static void	tup_vec3d(void);

static void	plain_point(void);

static void	plain_vec3d(void);

static void	plain_zero(void);

static void	test_add(void);

static void	test_sub_pt_pt(void);

static void	test_sub_pt_vec(void);

static void	test_sub_vec_vec(void);

static void	test_negate(void);

static void	test_scale_scalar(void);

static void	test_scale_fraction(void);

static void	test_magn(void);

static void	test_norm(void);

static void	test_dot(void);

static void	test_cross(void);

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
	RUN_TEST(plain_zero);
	RUN_TEST(test_add);
	RUN_TEST(test_sub_pt_pt);
	RUN_TEST(test_sub_pt_vec);
	RUN_TEST(test_sub_vec_vec);
	RUN_TEST(test_negate);
	RUN_TEST(test_scale_scalar);
	RUN_TEST(test_scale_fraction);
	RUN_TEST(test_magn);
	RUN_TEST(test_norm);
	RUN_TEST(test_dot);
	RUN_TEST(test_cross);
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

static void	plain_zero(void) {
	t_tup	t;

	t = tup0();
	TEST_ASSERT_EQUAL_INT32(i2fpt(0), t.x);
	TEST_ASSERT_EQUAL_INT32(i2fpt(0), t.y);
	TEST_ASSERT_EQUAL_INT32(i2fpt(0), t.z);
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

static void	test_sub_pt_pt(void) {
	t_tup	p1 = point(i2fpt(3), i2fpt(2), i2fpt(1));
	t_tup	p2 = point(i2fpt(5), i2fpt(6), i2fpt(7));

	t_tup	test = vec3d(i2fpt(-2), i2fpt(-4), i2fpt(-6));

	TEST_ASSERT_TRUE(tup_equal(tup_sub(&p1, &p2), &test));
}

static void	test_sub_pt_vec(void) {
	t_tup	p1 = point(i2fpt(3), i2fpt(2), i2fpt(1));
	t_tup	v2 = vec3d(i2fpt(5), i2fpt(6), i2fpt(7));

	t_tup	test = point(i2fpt(-2), i2fpt(-4), i2fpt(-6));

	TEST_ASSERT_TRUE(tup_equal(tup_sub(&p1, &v2), &test));
}

static void	test_sub_vec_vec(void) {
	t_tup	v1 = vec3d(i2fpt(3), i2fpt(2), i2fpt(1));
	t_tup	v2 = vec3d(i2fpt(5), i2fpt(6), i2fpt(7));

	t_tup	test = vec3d(i2fpt(-2), i2fpt(-4), i2fpt(-6));

	TEST_ASSERT_TRUE(tup_equal(tup_sub(&v1, &v2), &test));
}

static void	test_negate(void) {
	t_tup	t1 = tup(i2fpt(1), i2fpt(-2), i2fpt(3), i2fpt(-4));

	t_tup	test = tup(i2fpt(-1), i2fpt(2), i2fpt(-3), i2fpt(4));

	tup_neg(&t1);

	TEST_ASSERT_EQUAL_INT32(i2fpt(-1), t1.x);
	TEST_ASSERT_EQUAL_INT32(i2fpt(2), t1.y);
	TEST_ASSERT_EQUAL_INT32(i2fpt(-3), t1.z);
	TEST_ASSERT_EQUAL_INT32(i2fpt(4), t1.w);
	TEST_ASSERT_TRUE(tup_equal(&t1, &test));
}

static void	test_scale_scalar(void) {
	t_tup	t1 = tup(i2fpt(1), i2fpt(-2), i2fpt(3), i2fpt(-4));

	t_tup	test = tup(fl2fpt(3.5), fl2fpt(-7), fl2fpt(10.5), fl2fpt(-14));

	tup_scale(&t1, fl2fpt(3.5f));

	TEST_ASSERT_EQUAL_INT32(fl2fpt(3.5), t1.x);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(-7), t1.y);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(10.5), t1.z);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(-14), t1.w);
	TEST_ASSERT_TRUE(tup_equal(&t1, &test));
}

static void	test_scale_fraction(void) {
	t_tup	t1 = tup(i2fpt(1), i2fpt(-2), i2fpt(3), i2fpt(-4));

	t_tup	test = tup(fl2fpt(0.5), fl2fpt(-1), fl2fpt(1.5), fl2fpt(-2));

	tup_scale(&t1, fl2fpt(0.5f));

	TEST_ASSERT_EQUAL_INT32(fl2fpt(0.5), t1.x);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(-1), t1.y);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(1.5), t1.z);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(-2), t1.w);
	TEST_ASSERT_TRUE(tup_equal(&t1, &test));
}

static void	test_magn(void) {
	t_tup	v1 = vec3d(0, FPT_ONE, 0);

	TEST_ASSERT_EQUAL_INT32(FPT_ONE, tup_magn(&v1));
	
	v1 = vec3d(0, 0, FPT_ONE);

	TEST_ASSERT_EQUAL_INT32(FPT_ONE, tup_magn(&v1));
	
	v1 = vec3d(i2fpt(1), i2fpt(2), i2fpt(3));

	TEST_ASSERT_EQUAL_INT32(fpt_sqrt(i2fpt(14)), tup_magn(&v1));

	v1 = vec3d(i2fpt(-1), i2fpt(-2), i2fpt(-3));

	TEST_ASSERT_EQUAL_INT32(fpt_sqrt(i2fpt(14)), tup_magn(&v1));
}

static void	test_norm(void) {
	t_tup	t1 = vec3d(fl2fpt(4), fl2fpt(0), fl2fpt(0));

	tup_norm(&t1);

	TEST_ASSERT_EQUAL_INT32(fl2fpt(1), t1.x);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(0), t1.y);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(0), t1.z);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(0), t1.w);

	t1 = vec3d(fl2fpt(1), fl2fpt(2), fl2fpt(3));

	tup_norm(&t1);

	TEST_ASSERT_TRUE(fpt_equal(FPT_ONE, tup_magn(&t1)));
}

static void	test_dot(void) {
	t_tup	v1 = vec3d(fl2fpt(1), fl2fpt(2), fl2fpt(3));
	t_tup	v2 = vec3d(fl2fpt(2), fl2fpt(3), fl2fpt(4));

	TEST_ASSERT_EQUAL_INT32(i2fpt(20), tup_dot(&v1, &v2));
}

static void	test_cross(void) {
	t_tup	v1 = vec3d(fl2fpt(1), fl2fpt(2), fl2fpt(3));
	t_tup	v2 = vec3d(fl2fpt(2), fl2fpt(3), fl2fpt(4));

	t_tup	t1 = v1;
	t_tup	t2 = v2;

	tup_cross(&t1, &v2);

	TEST_ASSERT_EQUAL_INT32(fl2fpt(-1), t1.x);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(2), t1.y);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(-1), t1.z);
	
	tup_cross(&t2, &v1);

	TEST_ASSERT_EQUAL_INT32(fl2fpt(1), t2.x);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(-2), t2.y);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(1), t2.z);
}
