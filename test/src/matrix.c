#include "matrix.h"

#include "unity.h"
#include "fptc-ns.h"

void	test_mul(void) {
	t_mat	m1, m2;

	m1 = mat((fpt[4][4]){
		{fl2fpt(1), fl2fpt(2), fl2fpt(3), fl2fpt(4)},
		{fl2fpt(5), fl2fpt(6), fl2fpt(7), fl2fpt(8)},
		{fl2fpt(9), fl2fpt(8), fl2fpt(7), fl2fpt(6)},
		{fl2fpt(5), fl2fpt(4), fl2fpt(3), fl2fpt(2)}
	});
	m2 = mat((fpt[4][4]){
		{fl2fpt(-2), fl2fpt(1), fl2fpt(2), fl2fpt(3)},
		{fl2fpt(3), fl2fpt(2), fl2fpt(1), fl2fpt(-1)},
		{fl2fpt(4), fl2fpt(3), fl2fpt(6), fl2fpt(5)},
		{fl2fpt(1), fl2fpt(2), fl2fpt(7), fl2fpt(8)}
	});

	t_mat	test;

	test = mat((fpt[4][4]){
		{fl2fpt(20), fl2fpt(22), fl2fpt(50), fl2fpt(48)},
		{fl2fpt(44), fl2fpt(54), fl2fpt(114), fl2fpt(108)},
		{fl2fpt(40), fl2fpt(58), fl2fpt(110), fl2fpt(102)},
		{fl2fpt(16), fl2fpt(26), fl2fpt(46), fl2fpt(42)}
	});

	mat_mul(&m1, &m2);
	TEST_ASSERT_EQUAL_INT32(test.m[0][0], m1.m[0][0]);
	TEST_ASSERT_EQUAL_INT32(test.m[0][1], m1.m[0][1]);
	TEST_ASSERT_EQUAL_INT32(test.m[0][2], m1.m[0][2]);
	TEST_ASSERT_EQUAL_INT32(test.m[0][3], m1.m[0][3]);
	TEST_ASSERT_EQUAL_INT32(test.m[1][0], m1.m[1][0]);
	TEST_ASSERT_EQUAL_INT32(test.m[1][1], m1.m[1][1]);
	TEST_ASSERT_EQUAL_INT32(test.m[1][2], m1.m[1][2]);
	TEST_ASSERT_EQUAL_INT32(test.m[1][3], m1.m[1][3]);
	TEST_ASSERT_EQUAL_INT32(test.m[2][0], m1.m[2][0]);
	TEST_ASSERT_EQUAL_INT32(test.m[2][1], m1.m[2][1]);
	TEST_ASSERT_EQUAL_INT32(test.m[2][2], m1.m[2][2]);
	TEST_ASSERT_EQUAL_INT32(test.m[2][3], m1.m[2][3]);
	TEST_ASSERT_EQUAL_INT32(test.m[3][0], m1.m[3][0]);
	TEST_ASSERT_EQUAL_INT32(test.m[3][1], m1.m[3][1]);
	TEST_ASSERT_EQUAL_INT32(test.m[3][2], m1.m[3][2]);
	TEST_ASSERT_EQUAL_INT32(test.m[3][3], m1.m[3][3]);
}

void	test_2x2(void) {
	t_mat	m;

	m = mat((fpt[4][4]){
		 {fl2fpt(-3), fl2fpt(5)},
		 {fl2fpt(1), fl2fpt(-2)}
		 });
	TEST_ASSERT_EQUAL_INT32(fl2fpt(-3), m.m[0][0]);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(5), m.m[0][1]);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(1), m.m[1][0]);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(-2), m.m[1][1]);
}

void	test_3x3(void) {
	t_mat	m;

	m = mat((fpt[4][4]){
		 {fl2fpt(-3), fl2fpt(5), fl2fpt(0)},
		 {fl2fpt(1), fl2fpt(-2), fl2fpt(-7)},
		 {fl2fpt(0), fl2fpt(1), fl2fpt(1)}
		 });
	TEST_ASSERT_EQUAL_INT32(fl2fpt(-3), m.m[0][0]);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(-2), m.m[1][1]);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(1), m.m[2][2]);
}

void	test_4x4(void) {
	t_mat	m;

	m = mat((fpt[4][4]){
		 {fl2fpt(1), fl2fpt(2), fl2fpt(3), fl2fpt(4)},
		 {fl2fpt(5.5), fl2fpt(6.5), fl2fpt(7.5), fl2fpt(8.5)},
		 {fl2fpt(9), fl2fpt(10), fl2fpt(11), fl2fpt(12)},
		 {fl2fpt(13.5), fl2fpt(14.5), fl2fpt(15.5), fl2fpt(16.5)}
		 });
	TEST_ASSERT_EQUAL_INT32(fl2fpt(1), m.m[0][0]);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(4), m.m[0][3]);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(5.5), m.m[1][0]);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(7.5), m.m[1][2]);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(11), m.m[2][2]);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(13.5), m.m[3][0]);
	TEST_ASSERT_EQUAL_INT32(fl2fpt(15.5), m.m[3][2]);
}

void setUp() {}

void tearDown() {}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_4x4);
	RUN_TEST(test_3x3);
	RUN_TEST(test_2x2);
	RUN_TEST(test_mul);
	return UNITY_END();
}
