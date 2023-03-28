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
	RUN_TEST(test_operation_tuple);
	RUN_TEST(test_operation_color);
	//RUN_TEST(test_canvas);
	return (UNITY_END());
}
