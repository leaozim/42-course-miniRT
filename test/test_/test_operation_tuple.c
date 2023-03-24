# include "../h_test.h"

#include <stdlib.h>
#define MAX_INTERATIONS 100

double	rand_double()
{
	double valor = ((double) rand() * 2) / ( double ) RAND_MAX;
	return (valor);
}

void	is_tuple_value_correct(void)
{
	double	x, y, z, w;
	int		i;
	t_tuple	tuple;

	while (i < MAX_INTERATIONS)
	{
		x = rand_double();
		y = rand_double();
		z = rand_double();
		w = rand_double();
		tuple = create_tuple(x, y, z, w);
		TEST_ASSERT_EQUAL_DOUBLE(x, tuple.x);
		TEST_ASSERT_EQUAL_DOUBLE(y, tuple.y);
		TEST_ASSERT_EQUAL_DOUBLE(z, tuple.z);
		TEST_ASSERT_EQUAL_DOUBLE(w, tuple.w);
		i++;
	}
}

void	add_tuples(void)
{
	char	a[4] = {3, -2, 5, 1};
	char	b[4] = {-2, 3, 1, 0};
	char	result[4] = {1, 1, 6, 1};
	TEST_ASSERT_EQUAL_MEMORY(result, adding_tuples(a, b), sizeof(result));
}

void test_operation_tuple(void)
{
	RUN_TEST(is_tuple_value_correct);
	RUN_TEST(add_tuples);
}
