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

void	test_add_tuples(void)
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
//  	prototipo t_tuple	adding_tuple(t_tuple tupleA, t_tuple tupleB);
		TEST_ASSERT_EQUAL_DOUBLE((x1 + x2), sum.x);
		TEST_ASSERT_EQUAL_DOUBLE((y1 + y2), sum.y);
		TEST_ASSERT_EQUAL_DOUBLE((z1 + z2), sum.z);
		TEST_ASSERT_EQUAL_DOUBLE((w1 + w2), sum.w);
		i++;
	}

}

void	test_sub_tuples(void)
{
	double	x1, y1, z1, w1;
	double	x2, y2, z2, w2;
	t_tuple	tupleA;
	t_tuple	tupleB;
	t_tuple	sub;
	int 	i;

	i = 0;
	sub = create_tuple(4, 4, 4, 4); // valores aleatorios pra teste.
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
//		sub = sub_tuples(tupleA, tupleB); função a ser criada, sub_tuples -> recebe t_tuple A e t_tuple B e retorna a subtração das duas tuplas (t_tuple).
//  	prototipo t_tuple	sub_tuple(t_tuple tupleA, t_tuple tupleB);
		TEST_ASSERT_EQUAL_DOUBLE((x1 - x2), sub.x);
		TEST_ASSERT_EQUAL_DOUBLE((y1 - y2), sub.y);
		TEST_ASSERT_EQUAL_DOUBLE((z1 - z2), sub.z);
		TEST_ASSERT_EQUAL_DOUBLE((w1 - w2), sub.w);
		i++;
	}

}

void	test_div_tuples(void)
{
	double	x1, y1, z1, w1;
	double	divide_n;
	t_tuple	tupleA;
	t_tuple	result;
	int 	i;

	i = 0;
	result = create_tuple(4, 4, 4, 4); // valores aleatorios pra teste.
	while (i < MAX_INTERATIONS)
	{
		x1 = rand_double();
		y1 = rand_double();
		z1 = rand_double();
		w1 = rand_double();
		tupleA = create_tuple(x1, y1, z1, w1);
		divide_n = rand_double();
//		result = divide_tuples(tupleA, divide); função a ser criada, divide_tuples -> recebe t_tuple A e o número a qual os valores da tupla serão divididos e retorna a tupla dividia (t_tuple).
//  	prototipo t_tuple	divide_tuple(t_tuple tupleA, double divide_n);
		TEST_ASSERT_EQUAL_DOUBLE((x1 / divide_n), result.x);
		TEST_ASSERT_EQUAL_DOUBLE((y1 / divide_n), result.y);
		TEST_ASSERT_EQUAL_DOUBLE((z1 / divide_n), result.z);
		TEST_ASSERT_EQUAL_DOUBLE((w1 / divide_n), result.w);
		i++;
	}

}

void	test_multiplication_tuples(void)
{
	double	x1, y1, z1, w1;
	double	multiplication_n;
	t_tuple	tupleA;
	t_tuple	result;
	int 	i;

	i = 0;
	result = create_tuple(4, 6, 4, 2); // valores aleatorios pra teste.
	while (i < MAX_INTERATIONS)
	{
		x1 = rand_double();
		y1 = rand_double();
		z1 = rand_double();
		w1 = rand_double();
		tupleA = create_tuple(x1, y1, z1, w1);
		multiplication_n = rand_double();
//		result = multiplication_tuple(tupleA, multi); função a ser criada, multiplication_tuples -> recebe t_tuple A e o número a qual os valores da tupla serão multiplicados e retorna a tupla multiplicada (t_tuple).
//  	prototipo -> t_tuple	multiplication_tuple(t_tuple tupleA, double multi_n);
		TEST_ASSERT_EQUAL_DOUBLE((x1 * multiplication_n), result.x);
		TEST_ASSERT_EQUAL_DOUBLE((y1 * multiplication_n), result.y);
		TEST_ASSERT_EQUAL_DOUBLE((z1 * multiplication_n), result.z);
		TEST_ASSERT_EQUAL_DOUBLE((w1 * multiplication_n), result.w);
		i++;
	}

}

void test_operation_tuple(void)
{
	RUN_TEST(is_tuple_value_correct);
	RUN_TEST(test_add_tuples);
	RUN_TEST(test_sub_tuples);
	RUN_TEST(test_div_tuples);
	RUN_TEST(test_multiplication_tuples);
}
