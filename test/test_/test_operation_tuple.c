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
	(void)tuple_neg;
	while (i < MAX_INTERATIONS)
	{
		x = rand_double();
		y = rand_double();
		z = rand_double();
		w = rand_double();
		tuple = create_tuple(x, y, z, w);
		// tuple_neg = t_tupla neg_tupla(t_tupla tupla);
		// TEST_ASSERT_EQUAL_DOUBLE(-x, tuple_neg.x);
		TEST_ASSERT_EQUAL_DOUBLE(-x, tuple.x);
		TEST_ASSERT_EQUAL_DOUBLE(-y, tuple.y);
		TEST_ASSERT_EQUAL_DOUBLE(-z, tuple.z);
		TEST_ASSERT_EQUAL_DOUBLE(-w, tuple.w);
		i++;
	}
}

void	multiply_tupla_correct(void)
{
	double		x, y, z, w, multiplier, result;
	int			i;
	t_tuple		tuple;

	(void)result;
	i = 0;
	while (i < MAX_INTERATIONS)
	{
		x = rand_double();
		y = rand_double();
		z = rand_double();
		w = rand_double();
		multiplier = rand_double();
		tuple = create_tuple(x, y, z, w);
		// result = t_tupla multiply_tupla(t_tupla tupla, multiplier);
		// TEST_ASSERT_EQUAL_DOUBLE(x * multiplier, result.x);
		TEST_ASSERT_EQUAL_DOUBLE(x * multiplier, tuple.x);
		TEST_ASSERT_EQUAL_DOUBLE(y * multiplier, tuple.y);
		TEST_ASSERT_EQUAL_DOUBLE(z * multiplier, tuple.z);
		TEST_ASSERT_EQUAL_DOUBLE(w * multiplier, tuple.w);
		i++;
	}
}

void	normalization_correct(void)
{
	double		x, y, z;
	int			i;
	t_vector	vector, norm;

	(void)norm;
	i = 0;
	while (i < MAX_INTERATIONS)
	{
		x = rand_double();
		y = rand_double();
		z = rand_double();
		vector = create_vector(x, y, z);
		// norm = t_vector normalize(t_vector *vector);
		// TEST_ASSERT_EQUAL_DOUBLE(1.0, magnitude(norm));
		TEST_ASSERT_EQUAL_DOUBLE(1.0, vector.x);
		TEST_ASSERT_EQUAL_DOUBLE(1.0, vector.y);
		TEST_ASSERT_EQUAL_DOUBLE(1.0, vector.z);
		i++;
	}
}

void	dot_product_correct(void)
{
	double		x1, y1, z1, x2, y2, z2;
	int			i;
	t_vector	vector1, vector2;

	(void)vector1;
	(void)vector2;
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
		// 	double dot_product(t_vector *vector1, t_vector *vector2);
		// 	TEST_ASSERT_EQUAL_DOUBLE((vector1.x * vector2.x) + 
									// (vector1.y * vector2.y) + 
									// (vector1.z * vector2.z) + 
									// (vector1.w * vector2.w), 
									// dot_product(vector1, vector2));
		TEST_ASSERT_EQUAL_DOUBLE((vector1.x * vector2.x) + \
								(vector1.y * vector2.y) + \
								(vector1.z * vector2.z) + \
								(vector1.w * vector2.w), 2.0);
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
	sum = create_tuple(4, 4, 4, 4);
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
		sum = adding_tuples(tupleA, tupleB);
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
	sub = create_tuple(4, 4, 4, 4);
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
		sub = sub_tuples(tupleA, tupleB);
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
	result = create_tuple(4, 4, 4, 4);
	while (i < MAX_INTERATIONS)
	{
		x1 = rand_double();
		y1 = rand_double();
		z1 = rand_double();
		w1 = rand_double();
		tupleA = create_tuple(x1, y1, z1, w1);
		divide_n = rand_double();
		result = div_tuples(tupleA, divide_n);
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
	result = rand_double();
	while (i < MAX_INTERATIONS)
	{
		x = rand_double();
		y = rand_double();
		z = rand_double();
		vector = create_vector(x, y, z);
		result = magnitude(vector);
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
	result = create_tuple(4, 4, 4, 4);
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
		result = cross_product(vectorA, vectorB);
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
