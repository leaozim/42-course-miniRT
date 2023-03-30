# include "../h_test.h"



void	tests_shearing_first(void)
{
	t_shearing	shearing;
	t_matrix	s;
	t_point		point;
	t_point		result;
	t_point		expec;

	shearing = set_shearing();
	point = create_point(2, 3, 4);
	// s = shearing(shearing) função a ser criada -> t_matrix shearing(t_shearing shearing);
	result = multiply_matrix_tuple(s, point);
	expec = create_point(5, 3, 4);
	TEST_ASSERT_EQUAL_DOUBLE(result.x, expec.x);
	TEST_ASSERT_EQUAL_DOUBLE(result.y, expec.y);
	TEST_ASSERT_EQUAL_DOUBLE(result.z, expec.z);
}

void	test_shearing(void)
{
	RUN_TEST(tests_shearing_first);
}