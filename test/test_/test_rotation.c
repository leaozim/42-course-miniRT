# include "../h_test.h"


void	test_rotating_point_around_x(void)
{
	t_point		point;
	t_matrix	half_quarter;
	t_matrix	full_quarter;
	t_point		result;

	point = create_point(0, 1, 0);
	half_quarter = create_identity_matrix(); // substituir essa linha, pela função a baixo
	// half_quarter = rotação_x(M_PI / 4) 
	result = multiply_matrix_tuple(half_quarter, point);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, 0);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, sqrt(2) / 2);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, sqrt(2) / 2);

	full_quarter = create_identity_matrix(); // substituir essa linha, pela função a baixo
	// full_quarter = rotação_x(M_PI / 2) 
	result = multiply_matrix_tuple(full_quarter, point);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, 0);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, 0);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, 1);
}

void    test_rotating_point_around_y(void)
{
	t_point     point;
	t_matrix    rotation;
	t_point     result;

	point = create_point(0, 0, 1);
	// rotation = rotation_y(M_PI / 4) -> M_PI é uma constante pi 3,14 dentro da lib <math.h>
	result = multiply_matrix_tuple(rotation, point);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, sqrt(2) / 2);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, 0);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, sqrt(2) / 2);

	// rotation = rotation_y(M_PI / 2)  segundo teste
	result = multiply_matrix_tuple(rotation, point);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, 1);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, 0);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, 0);
}

void    test_rotating_point_around_z(void)
{
	t_point     point;
	t_matrix    rotation;
	t_point     result;

	point = create_point(0, 1, 0);
	// rotation = rotation_z(M_PI / 4) 
	result = multiply_matrix_tuple(rotation, point);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, -sqrt(2) / 2);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, sqrt(2) / 2);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, 0);

	// rotation = rotation_z(M_PI / 2)  segundo teste
	result = multiply_matrix_tuple(rotation, point);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, -1);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, 0);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, 0);
}

void	test_inverse_x_rotate_opposite_direction(void)
{
	t_point		point;
	t_matrix	half_quarter;
	t_point		result;
	t_matrix	inver;

	point = create_point(0, 1, 0);
	half_quarter = create_identity_matrix(); // substituir essa linha, pela função a baixo
	// half_quarter = rotação_x(M_PI / 4) 
	inver = inverse_matrix(half_quarter);
	result = multiply_matrix_tuple(inver, point);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, 0);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, sqrt(2) / 2);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, sqrt(2) / 2);
}

void    test_rotation(void)
{
	RUN_TEST(test_rotating_point_around_x);
	RUN_TEST(test_rotating_point_around_y);
    RUN_TEST(test_rotating_point_around_z);
	RUN_TEST(test_inverse_x_rotate_opposite_direction);
}