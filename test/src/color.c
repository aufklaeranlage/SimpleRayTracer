#include "tuple.h"

#include "unity.h"

void setUp(void) {

}

void tearDown(void) {

}

static void	test_add(void) {
	t_tup	c1 = colr(fl2fpt(0.9), fl2fpt(0.6), fl2fpt(0.75));
	t_tup	c2 = colr(fl2fpt(0.7), fl2fpt(0.1), fl2fpt(0.25));

	t_tup	test = colr(fl2fpt(1.6), fl2fpt(0.7), fl2fpt(1.0));

	TEST_ASSERT_TRUE(tup_equal(tup_add(&c1, &c2), &test));
}

static void	test_sub(void) {
	t_tup	c1 = colr(fl2fpt(0.9), fl2fpt(0.6), fl2fpt(0.75));
	t_tup	c2 = colr(fl2fpt(0.7), fl2fpt(0.1), fl2fpt(0.25));

	t_tup	test = colr(fl2fpt(0.2), fl2fpt(0.5), fl2fpt(0.5));

	TEST_ASSERT_TRUE(tup_equal(tup_sub(&c1, &c2), &test));
}

static void	test_scale(void) {
	t_tup	c1 = colr(fl2fpt(0.2), fl2fpt(0.3), fl2fpt(0.4));
	fpt		scale = fl2fpt(2.0);

	t_tup	test = colr(fl2fpt(0.4), fl2fpt(0.6), fl2fpt(0.8));

	TEST_ASSERT_TRUE(tup_equal(tup_scale(&c1, scale), &test));
}

static void	test_mul(void) {
	t_tup	c1 = colr(fl2fpt(1.0), fl2fpt(0.2), fl2fpt(0.4));
	t_tup	c2 = colr(fl2fpt(0.9), fl2fpt(1.0), fl2fpt(0.1));

	t_tup	test = colr(fl2fpt(0.9), fl2fpt(0.2), fl2fpt(0.04));

	TEST_ASSERT_TRUE(tup_equal(tup_mul(&c1, &c2), &test));
}

int	main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_add);	
	RUN_TEST(test_sub);	
	RUN_TEST(test_scale);	
	RUN_TEST(test_mul);	
	return (UNITY_END());
}
