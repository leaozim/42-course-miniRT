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
	double	x1, y1, z1, w1;
	double	x2, y2, z2, w2;
	t_tuple	tupleA;
	t_tuple	tupleB;
	t_tuple	sum;
	int 	i;

	i = 0;
	sum = create_tuple(4, 4, 4, 4); // valores aleatorios pra teste.
	while (i < MAX_INTERATIONS)
	{
		x1 = rand_double();
		y1 = rand_double();
		z1 = rand_double();
		w1 = rand_double();
		tupleA = create_tuple(x1, y1, z1, w1);
		x2 = rand_double();
		y2 = rand_double();
		z2 = rand_double();
		w2 = rand_double();
		tupleB = create_tuple(x2, y2, z2, w2);
//		sum = adding_tuples(tupleA, tupleB); função a ser criada, adding_tuples -> recebe t_tuple A e t_tuple B e retorna a soma das duas tuplas t_tuple.
//  	prototipo t_tuple	adding_tuple(t_tuple a, t_tuple b);
		TEST_ASSERT_EQUAL_DOUBLE((x1 + x2), sum.x);
		TEST_ASSERT_EQUAL_DOUBLE((y1 + y2), sum.y);
		TEST_ASSERT_EQUAL_DOUBLE((z1 + z2), sum.z);
		TEST_ASSERT_EQUAL_DOUBLE((w1 + w2), sum.w);
		i++;
	}

}

void	sub_tuples(void)
{

}

void test_operation_tuple(void)
{
	RUN_TEST(is_tuple_value_correct);
	RUN_TEST(add_tuples);
}
