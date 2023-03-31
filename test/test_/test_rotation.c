# include "../h_test.h"

void	test_rotating_point_around_x(void)
{
	t_point		point;
	t_matrix	rotation;
	t_point		result;

	point = create_point(0, 1, 0);
	rotation = rotation_x(M_PI / 4);
	result = multiply_matrix_tuple(rotation, point);
	TEST_ASSERT_EQUAL_DOUBLE(0, result.x);
	TEST_ASSERT_EQUAL_DOUBLE(sqrt(2) / 2, result.y);
	TEST_ASSERT_EQUAL_DOUBLE(sqrt(2) / 2, result.z);

	rotation = rotation_x(M_PI / 2);
	result = multiply_matrix_tuple(rotation, point);
	TEST_ASSERT_TRUE(is_equal_tuple((t_tuple){0, 0, 1, 1}, result));
}

void	test_rotating_point_around_y(void)
{
	t_point		point;
	t_matrix	rotation;
	t_point		result;

	point = create_point(0, 0, 1);
	rotation = rotation_y(M_PI / 4);
	result = multiply_matrix_tuple(rotation, point);
	TEST_ASSERT_EQUAL_DOUBLE(sqrt(2) / 2, result.x);
	TEST_ASSERT_EQUAL_DOUBLE(0, result.y);
	TEST_ASSERT_EQUAL_DOUBLE(sqrt(2) / 2, result.z);

	rotation = rotation_y(M_PI / 2);
	result = multiply_matrix_tuple(rotation, point);
	TEST_ASSERT_TRUE(is_equal_tuple((t_tuple){1, 0, 0, 1}, result));
}

void	test_rotating_point_around_z(void)
{
	t_point		point;
	t_matrix	rotation;
	t_point		result;

	point = create_point(0, 1, 0);
	rotation = rotation_z(M_PI / 4);
	result = multiply_matrix_tuple(rotation, point);
	TEST_ASSERT_TRUE(is_equal_tuple((t_tuple){-(sqrt(2)/2), (sqrt(2)/2), 0, 1}, result));

	rotation = rotation_z(M_PI / 2);
	result = multiply_matrix_tuple(rotation, point);
	TEST_ASSERT_TRUE(is_equal_tuple((t_tuple){-1, 0, 0, 1}, result));

}

void	test_inverse_x_rotate_opposite_direction(void)
{
	t_point		point;
	t_matrix	half_quarter;
	t_point		result;
	t_matrix	inver;

	point = create_point(0, 1, 0);
	half_quarter = rotation_x(M_PI / 4);
	inver = inverse_matrix(half_quarter);
	result = multiply_matrix_tuple(inver, point);
	TEST_ASSERT_EQUAL_DOUBLE(0, result.x);
	TEST_ASSERT_EQUAL_DOUBLE(sqrt(2) / 2, result.y);
	TEST_ASSERT_EQUAL_DOUBLE(-sqrt(2) / 2, result.z);
}

void	test_rotation(void)
{
	RUN_TEST(test_rotating_point_around_x);
	RUN_TEST(test_rotating_point_around_y);
	RUN_TEST(test_rotating_point_around_z);
	RUN_TEST(test_inverse_x_rotate_opposite_direction);
}