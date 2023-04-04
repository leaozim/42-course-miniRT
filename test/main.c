# include "h_test.h"
#include "unity/unity_internals.h"

void setUp(void)
{

}

void tearDown(void)
{

}

int main(void)
{
	UNITY_BEGIN();
	test_operation_tuple();
	test_operation_color();
	test_matrix();
	test_transformations_matrix();
	test_rotation();
	test_shearing();
	test_ray_sphere();
	//RUN_TEST(test_canvas);
	return (UNITY_END());
}