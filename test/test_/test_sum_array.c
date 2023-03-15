 #include "../h_test.h"

char    *sum_array(char *a, char *b)
{
	char *c;

	c = strcat(a, b);
	return (c);
}

void	valid_sum_array(void)
{
	char	a[7] = {1, 2, 3};
	char	b[4] = {3, 4, 2};
	char	result[7] = {1, 2, 3, 3, 4 ,5};
	TEST_ASSERT_EQUAL_MEMORY(result, sum_array(a, b), 7);
}

void test_sum_array(void)
{
	RUN_TEST(valid_sum_array);
}