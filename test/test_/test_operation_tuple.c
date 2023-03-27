# include "../h_test.h"

void	is_tuple_value_correct(void)
{
	double	x, y, z, w;
	int		i;
	t_tuple	tuple;

	i = 0;
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

void	is_vector_value_correct(void)
{
	double		x, y, z;
	int			i;
	t_vector	vector;

	i = 0;
	while (i < MAX_INTERATIONS)
	{
		x = rand_double();
		y = rand_double();
		z = rand_double();
		vector = create_vector(x, y, z);
		TEST_ASSERT_EQUAL_DOUBLE(x, vector.x);
		TEST_ASSERT_EQUAL_DOUBLE(y, vector.y);
		TEST_ASSERT_EQUAL_DOUBLE(z, vector.z);
		TEST_ASSERT_EQUAL_DOUBLE(VECTOR_W, vector.w);
		i++;
	}
}

void	is_point_value_correct(void)
{
	double		x, y, z;
	int			i;
	t_point		point;

	i = 0;
	while (i < MAX_INTERATIONS)
	{
		x = rand_double();
		y = rand_double();
		z = rand_double();
		point = create_point(x, y, z);
		TEST_ASSERT_EQUAL_DOUBLE(x, point.x);
		TEST_ASSERT_EQUAL_DOUBLE(y, point.y);
		TEST_ASSERT_EQUAL_DOUBLE(z, point.z);
		TEST_ASSERT_EQUAL_DOUBLE(POINT_W, point.w);
		i++;
	}
}

void	negating_tuples_correct(void)
{
	double		x, y, z, w;
	int			i;
	t_tuple		tuple, tuple_neg;

	i = 0;
	while (i < MAX_INTERATIONS)
	{
		x = rand_double();
		y = rand_double();
		z = rand_double();
		w = rand_double();
		tuple = create_tuple(x, y, z, w);
		tuple_neg = neg_tuple(tuple);
		TEST_ASSERT_EQUAL_DOUBLE(-x, tuple_neg.x);
		TEST_ASSERT_EQUAL_DOUBLE(-y, tuple_neg.y);
		TEST_ASSERT_EQUAL_DOUBLE(-z, tuple_neg.z);
		TEST_ASSERT_EQUAL_DOUBLE(-w, tuple_neg.w);
		i++;
	}
}

void	multiply_tupla_correct(void)
{
	double		x, y, z, w, multiplier;
	int			i;
	t_tuple		tuple, result;

	i = 0;
	while (i < MAX_INTERATIONS)
	{
		x = rand_double();
		y = rand_double();
		z = rand_double();
		w = rand_double();
		multiplier = rand_double();
		tuple = create_tuple(x, y, z, w);
		result = multiply_tupla(tuple, multiplier);
		TEST_ASSERT_EQUAL_DOUBLE(x * multiplier, result.x);
		TEST_ASSERT_EQUAL_DOUBLE(y * multiplier, result.y);
		TEST_ASSERT_EQUAL_DOUBLE(z * multiplier, result.z);
		TEST_ASSERT_EQUAL_DOUBLE(w * multiplier, result.w);
		i++;
	}
}

void	normalization_correct(void)
{
	double		x, y, z, w;
	int			i;
	t_vector	vec, norm;

	i = 0;
	while (i < MAX_INTERATIONS)
	{
		x = rand_double();
		y = rand_double();
		z = rand_double();
		w = rand_double();
		vec = create_vector(x, y, z);
		norm = normalize(vec);
		TEST_ASSERT_EQUAL_DOUBLE(1.0, magnitude(norm));
		i++;
	}
}

void	dot_product_correct(void)
{
	double		x1, y1, z1, x2, y2, z2, result;
	int			i;
	t_vector	vector1, vector2;


	i = 0;
	while (i < MAX_INTERATIONS)
	{
		x1 = rand_double();
		y1 = rand_double();
		z1 = rand_double();
		x2 = rand_double();
		y2 = rand_double();
		z2 = rand_double();
		vector1 = create_vector(x1, y1, z1);
		vector2 = create_vector(x2, y2, z2);
		result = dot_product(vector1, vector2);
		TEST_ASSERT_EQUAL_DOUBLE((vector1.x * vector2.x) + \
								(vector1.y * vector2.y) + \
								(vector1.z * vector2.z) + \
								(vector1.w * vector2.w), result);
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

void	test_magnitude(void)
{
	double		x, y, z;
	t_vector	vector;
	double		result;
	int			i;

	i = 0;
	result = rand_double(); // valores aleatorios pra teste.
	while (i < MAX_INTERATIONS)
	{
		x = rand_double();
		y = rand_double();
		z = rand_double();
		vector = create_vector(x, y, z);
//		result = magnitude(t_vector vector)
		TEST_ASSERT_EQUAL_DOUBLE((sqrt((x*x) + (y*y) + (z*z))), result);
	i++;
	}
}

void	test_cross_product(void)
{
	double		x1, y1, z1;
	double		x2, y2, z2;
	t_vector	vectorA;
	t_vector	vectorB;
	t_vector	result;
	int 		i;

	i = 0;
	result = create_tuple(4, 4, 4, 4); // valores aleatorios pra teste.
	while (i < MAX_INTERATIONS)
	{
		x1 = rand_double();
		y1 = rand_double();
		z1 = rand_double();
		vectorA =  create_vector(x1, y1, z1);
		x2 = rand_double();
		y2 = rand_double();
		z2 = rand_double();
		vectorB = create_vector(x2, y2, z2);
//		result = cross_product(vectorA, vectorB); função a ser criada, cross_product -> recebe t_vector A e t_vector B e retorna o produto vetorial dos dois vetores t_vector.
//  	prototipo t_vector	cross_product(t_vector vectorA, t_vector vectorB);
		TEST_ASSERT_EQUAL_DOUBLE((y1 * z2 - z1 * y2), result.x);
		TEST_ASSERT_EQUAL_DOUBLE((z1 * x2 - x1 * z2), result.y);
		TEST_ASSERT_EQUAL_DOUBLE((x1 * y2 - y1 * x2), result.z);
		i++;
	}

}

void test_operation_tuple(void)
{
	RUN_TEST(is_tuple_value_correct);
	RUN_TEST(is_vector_value_correct);
	RUN_TEST(is_point_value_correct);
	RUN_TEST(negating_tuples_correct);
	RUN_TEST(multiply_tupla_correct);
	RUN_TEST(normalization_correct);
	RUN_TEST(dot_product_correct);
	RUN_TEST(test_add_tuples);
	RUN_TEST(test_sub_tuples);
	RUN_TEST(test_div_tuples);
	RUN_TEST(test_magnitude);
	RUN_TEST(test_cross_product);
}
