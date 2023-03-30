# include "../h_test.h"

void    test_rotation_y(void)
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
	TEST_ASSERT_EQUAL_DOUBLE(result.w, 1);

	// rotation = rotation_y(M_PI / 2)  segundo teste
	result = multiply_matrix_tuple(rotation, point);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, 1);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, 0);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, 0);
	TEST_ASSERT_EQUAL_DOUBLE(result.w, 1);
}

void    test_rotation_z(void)
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
	TEST_ASSERT_EQUAL_DOUBLE(result.w, 1);

	// rotation = rotation_z(M_PI / 2)  segundo teste
	result = multiply_matrix_tuple(rotation, point);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, -1);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, 0);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, 0);
	TEST_ASSERT_EQUAL_DOUBLE(result.w, 1);
}

void    test_rotation(void)
{
	RUN_TEST(test_rotation_y);
    RUN_TEST(test_rotation_z);
}