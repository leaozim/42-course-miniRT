# include "../h_test.h"

int	soma(int a, int b)
{
	return (a + b);
}

void	valid_soma(void)
{
	int a = 3;
	int b = 3;
	int result = 6;
	TEST_ASSERT_EQUAL_INT(result, soma(a, b));
	
}

void test_soma(void)
{

	RUN_TEST(valid_soma);
}