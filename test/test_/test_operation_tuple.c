# include "../h_test.h"

void	is_tuple_value_correct(void)
{
	int a = 3;
	int b = 3;
	int result = 6;
	TEST_ASSERT_EQUAL_INT(result, soma(a, b));
}

void test_operation_tuple(void)
{
	RUN_TEST(is_tuple_value_correct);
}