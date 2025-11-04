#include "matrix.h"

#include "unity.h"
#include "fptc-ns.h"

static void	testMat(const t_mat *test, const t_mat *m) {
	TEST_ASSERT_EQUAL_INT32(test->m[0][0], m->m[0][0]);
	TEST_ASSERT_EQUAL_INT32(test->m[0][1], m->m[0][1]);
	TEST_ASSERT_EQUAL_INT32(test->m[0][2], m->m[0][2]);
	TEST_ASSERT_EQUAL_INT32(test->m[0][3], m->m[0][3]);
	TEST_ASSERT_EQUAL_INT32(test->m[1][0], m->m[1][0]);
	TEST_ASSERT_EQUAL_INT32(test->m[1][1], m->m[1][1]);
	TEST_ASSERT_EQUAL_INT32(test->m[1][2], m->m[1][2]);
	TEST_ASSERT_EQUAL_INT32(test->m[1][3], m->m[1][3]);
	TEST_ASSERT_EQUAL_INT32(test->m[2][0], m->m[2][0]);
	TEST_ASSERT_EQUAL_INT32(test->m[2][1], m->m[2][1]);
	TEST_ASSERT_EQUAL_INT32(test->m[2][2], m->m[2][2]);
	TEST_ASSERT_EQUAL_INT32(test->m[2][3], m->m[2][3]);
	TEST_ASSERT_EQUAL_INT32(test->m[3][0], m->m[3][0]);
	TEST_ASSERT_EQUAL_INT32(test->m[3][1], m->m[3][1]);
	TEST_ASSERT_EQUAL_INT32(test->m[3][2], m->m[3][2]);
	TEST_ASSERT_EQUAL_INT32(test->m[3][3], m->m[3][3]);
}

void	test_inverse_product(void) {
	t_mat	m1;

	m1 = mat((fpt[4][4]){
		{fl2fpt(3), fl2fpt(-9), fl2fpt(7), fl2fpt(3)},
		{fl2fpt(3), fl2fpt(-8), fl2fpt(2), fl2fpt(-9)},
		{fl2fpt(-4), fl2fpt(4), fl2fpt(4), fl2fpt(1)},
		{fl2fpt(-6), fl2fpt(5), fl2fpt(-1), fl2fpt(1)}
	});

	t_mat	m2;

	m2 = mat((fpt[4][4]){
		{fl2fpt(8), fl2fpt(2), fl2fpt(2), fl2fpt(2)},
		{fl2fpt(3), fl2fpt(-1), fl2fpt(7), fl2fpt(0)},
		{fl2fpt(7), fl2fpt(0), fl2fpt(5), fl2fpt(4)},
		{fl2fpt(6), fl2fpt(-2), fl2fpt(0), fl2fpt(5)}
	});
	
	t_mat	m3;

	m3 = mat_copy(&m1);
	mat_mul(&m3, &m2);

	mat_inverse(&m2);

	mat_mul(&m3, &m2);

	// testMat(&m1, &m3);
	TEST_ASSERT_TRUE(mat_equal(&m1, &m3));
}

void	test_inverse_fail(void) {
	t_mat	m1;

	m1 = mat((fpt[4][4]){
		{fl2fpt(-4), fl2fpt(2), fl2fpt(-2), fl2fpt(-3)},
		{fl2fpt(9), fl2fpt(6), fl2fpt(2), fl2fpt(6)},
		{fl2fpt(0), fl2fpt(-5), fl2fpt(1), fl2fpt(-5)},
		{fl2fpt(0), fl2fpt(0), fl2fpt(0), fl2fpt(0)}
	});

	TEST_ASSERT_FALSE(mat_inverse(&m1));
}

void	test_inverse(void) {
	t_mat	m1;

	m1 = mat((fpt[4][4]){
		{fl2fpt(-5), fl2fpt(2), fl2fpt(6), fl2fpt(-8)},
		{fl2fpt(1), fl2fpt(-5), fl2fpt(1), fl2fpt(8)},
		{fl2fpt(7), fl2fpt(7), fl2fpt(-6), fl2fpt(-7)},
		{fl2fpt(1), fl2fpt(-3), fl2fpt(7), fl2fpt(4)}
	});

	t_mat	test;

	test = mat((fpt[4][4]){
		{fl2fpt(0.21805), fl2fpt(0.45113), fl2fpt(0.24060), fl2fpt(-0.04511)},
		{fl2fpt(-0.80827), fl2fpt(-1.45677), fl2fpt(-0.44361), fl2fpt(0.52068)},
		{fl2fpt(-0.07895), fl2fpt(-0.22368), fl2fpt(-0.05263), fl2fpt(0.19737)},
		{fl2fpt(-0.52256), fl2fpt(-0.81391), fl2fpt(-0.30075), fl2fpt(0.30639)}
	});

	TEST_ASSERT_TRUE(mat_inverse(&m1));
	// testMat(&test, &m1);
	TEST_ASSERT_TRUE(mat_equal(&test, &m1));
}

void	test_transpose(void) {
	t_mat	m1;

	m1 = mat((fpt[4][4]){
		{fl2fpt(0), fl2fpt(9), fl2fpt(3), fl2fpt(0)},
		{fl2fpt(9), fl2fpt(8), fl2fpt(0), fl2fpt(8)},
		{fl2fpt(1), fl2fpt(8), fl2fpt(5), fl2fpt(3)},
		{fl2fpt(0), fl2fpt(0), fl2fpt(5), fl2fpt(8)}
	});

	t_mat	test;

	test = mat((fpt[4][4]){
		{fl2fpt(0), fl2fpt(9), fl2fpt(1), fl2fpt(0)},
		{fl2fpt(9), fl2fpt(8), fl2fpt(8), fl2fpt(0)},
		{fl2fpt(3), fl2fpt(0), fl2fpt(5), fl2fpt(5)},
		{fl2fpt(0), fl2fpt(8), fl2fpt(3), fl2fpt(8)}
	});

	mat_transpose(&m1);

	testMat(&test, &m1);
}

void	test_copy(void) {
	t_mat	m1, cpy;

	m1 = mat((fpt[4][4]){
		{fl2fpt(0), fl2fpt(1), fl2fpt(2), fl2fpt(4)},
		{fl2fpt(1), fl2fpt(2), fl2fpt(4), fl2fpt(8)},
		{fl2fpt(2), fl2fpt(4), fl2fpt(8), fl2fpt(16)},
		{fl2fpt(4), fl2fpt(8), fl2fpt(16), fl2fpt(32)}
	});
	
	cpy = mat_copy(&m1);

	testMat(&m1, &cpy);
}

void	test_ident(void) {
	t_mat	m1, id;

	m1 = mat((fpt[4][4]){
		{fl2fpt(0), fl2fpt(1), fl2fpt(2), fl2fpt(4)},
		{fl2fpt(1), fl2fpt(2), fl2fpt(4), fl2fpt(8)},
		{fl2fpt(2), fl2fpt(4), fl2fpt(8), fl2fpt(16)},
		{fl2fpt(4), fl2fpt(8), fl2fpt(16), fl2fpt(32)}
	});

	id = mat_identity();

	TEST_ASSERT_EQUAL_INT32(FPT_ONE, id.m[0][0]);
	TEST_ASSERT_EQUAL_INT32(FPT_ONE, id.m[1][1]);
	TEST_ASSERT_EQUAL_INT32(FPT_ONE, id.m[2][2]);
	TEST_ASSERT_EQUAL_INT32(FPT_ONE, id.m[3][3]);

	t_mat	test;

	test = mat_copy(&m1);

	mat_mul(&m1, &id);

	testMat(&test, &m1);
}

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

	testMat(&test, &m1);
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
	RUN_TEST(test_ident);
	RUN_TEST(test_copy);
	RUN_TEST(test_transpose);
	RUN_TEST(test_inverse);
	RUN_TEST(test_inverse_fail);
	RUN_TEST(test_inverse_product);
	return UNITY_END();
}
