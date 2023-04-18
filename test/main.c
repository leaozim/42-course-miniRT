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
	test_hit();
	test_ray();
	test_light_and_shading();
	test_world();
	test_shape();
	test_cylinders();
	test_canvas();
	return (UNITY_END());
}