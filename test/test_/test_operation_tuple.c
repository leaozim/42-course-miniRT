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

void test_operation_tuple(void)
{
	RUN_TEST(is_tuple_value_correct);
	RUN_TEST(is_vector_value_correct);
	RUN_TEST(is_point_value_correct);
	RUN_TEST(negating_tuples_correct);
	RUN_TEST(multiply_tupla_correct);
	RUN_TEST(normalization_correct);
	RUN_TEST(dot_product_correct);
}
