# include "../h_test.h"

void	tests_shearing_xy(void)
{
	t_shearing	shearing;
	t_matrix	transform;
	t_point		point;
	t_point		result;
	t_point		expec;

	shearing = set_shearing();
	point = create_point(2, 3, 4);
	transform = shearing_matrix(shearing);
	result = multiply_matrix_tuple(transform, point);
	expec = create_point(5, 3, 4);
	TEST_ASSERT_EQUAL_DOUBLE(expec.x, result.x);
	TEST_ASSERT_EQUAL_DOUBLE(expec.y, result.y);
	TEST_ASSERT_EQUAL_DOUBLE(expec.z, result.z);
}

void	tests_shearing_xz(void)
{
	t_shearing	shearing;
	t_matrix	transform;
	t_point		point;
	t_point		result;
	t_point		expec;

	shearing = set_shearing();
	shearing.x_y = 0;
	shearing.x_z = 1;
	point = create_point(2, 3, 4);
	transform = shearing_matrix(shearing);
	result = multiply_matrix_tuple(transform, point);
	expec = create_point(6, 3, 4);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, expec.x);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, expec.y);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, expec.z);
}

void	tests_shearing_yx(void)
{
	t_shearing	shearing;
	t_matrix	transform;
	t_point		point;
	t_point		result;
	t_point		expec;

	shearing = set_shearing();
	shearing.x_y = 0;
	shearing.y_x = 1;
	point = create_point(2, 3, 4);
	transform = shearing_matrix(shearing);
	result = multiply_matrix_tuple(transform, point);
	expec = create_point(2, 5, 4);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, expec.x);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, expec.y);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, expec.z);
}

void	tests_shearing_yz(void)
{
	t_shearing	shearing;
	t_matrix	transform;
	t_point		point;
	t_point		result;
	t_point		expec;

	shearing = set_shearing();
	shearing.x_y = 0;
	shearing.y_z = 1;
	point = create_point(2, 3, 4);
	transform = shearing_matrix(shearing);
	result = multiply_matrix_tuple(transform, point);
	expec = create_point(2, 7, 4);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, expec.x);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, expec.y);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, expec.z);
}

void	tests_shearing_zx(void)
{
	t_shearing	shearing;
	t_matrix	transform;
	t_point		point;
	t_point		result;
	t_point		expec;

	shearing = set_shearing();
	shearing.x_y = 0;
	shearing.z_x = 1;
	point = create_point(2, 3, 4);
	transform = shearing_matrix(shearing);
	result = multiply_matrix_tuple(transform, point);
	expec = create_point(2, 3, 6);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, expec.x);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, expec.y);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, expec.z);
}

void	tests_shearing_zy(void)
{
	t_shearing	shearing;
	t_matrix	transform;
	t_point		point;
	t_point		result;
	t_point		expec;

	shearing = set_shearing();
	shearing.x_y = 0;
	shearing.z_y = 1;
	point = create_point(2, 3, 4);
	transform = shearing_matrix(shearing);
	result = multiply_matrix_tuple(transform, point);
	expec = create_point(2, 3, 7);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, expec.x);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, expec.y);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, expec.z);
}

void	test_shearing(void)
{
	RUN_TEST(tests_shearing_xy);
	RUN_TEST(tests_shearing_xz);
	RUN_TEST(tests_shearing_yx);
	RUN_TEST(tests_shearing_yz);
	RUN_TEST(tests_shearing_zx);
	RUN_TEST(tests_shearing_zy);
}