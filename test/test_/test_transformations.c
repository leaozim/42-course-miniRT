# include "../h_test.h"

void	test_mult_translation_matrix(void)
{
	t_matrix	transform;
	t_point		resul;
	t_point		p;

	transform = translation(5, -3, 2);
	p = create_point(-3, 4, 5);
	resul = multiply_matrix_tuple(transform, p);
	TEST_ASSERT_EQUAL_DOUBLE(2, resul.x);
	TEST_ASSERT_EQUAL_DOUBLE(1, resul.y);
	TEST_ASSERT_EQUAL_DOUBLE(7, resul.z);
	TEST_ASSERT_EQUAL_DOUBLE(1, resul.w);
}

void	test_mult_inverse_translation_matrix(void)
{
	t_matrix	transform;
	t_matrix	inver_matrix;
	t_point		resul;
	t_point		p;

	transform = translation(5, -3, 2);
	inver_matrix = inverse_matrix(transform);
	p = create_point(-3, 4, 5);
	resul = multiply_matrix_tuple(inver_matrix, p);
	TEST_ASSERT_EQUAL_DOUBLE(-8, resul.x);
	TEST_ASSERT_EQUAL_DOUBLE(7, resul.y);
	TEST_ASSERT_EQUAL_DOUBLE(3, resul.z);
	TEST_ASSERT_EQUAL_DOUBLE(1, resul.w);
}

void	test_translation_not_effect_vectors(void)
{
	t_matrix	transform;
	t_vector		resul;
	t_vector		vec;

	transform = translation(5, -3, 2);
	vec = create_vector(-3, 4, 5);
	resul = multiply_matrix_tuple(transform, vec);
	TEST_ASSERT_EQUAL_DOUBLE(-3, resul.x);
	TEST_ASSERT_EQUAL_DOUBLE(4, resul.y);
	TEST_ASSERT_EQUAL_DOUBLE(5, resul.z);
	TEST_ASSERT_EQUAL_DOUBLE(0, resul.w);
}

void	test_scaling_matrix_applied_point(void)
{
	t_matrix	transform;
	t_point		resul;
	t_point		p;

	transform = scaling(2, 3, 4);
	p = create_point(-4, 6, 8);
	resul = multiply_matrix_tuple(transform, p);
	TEST_ASSERT_EQUAL_DOUBLE(-8, resul.x);
	TEST_ASSERT_EQUAL_DOUBLE(18, resul.y);
	TEST_ASSERT_EQUAL_DOUBLE(32, resul.z);
	TEST_ASSERT_EQUAL_DOUBLE(1, resul.w);
}

void	test_scaling_matrix_applied_vector(void)
{
	t_matrix	transform;
	t_vector		resul;
	t_vector		v;

	transform = scaling(2, 3, 4);
	v = create_vector(-4, 6, 8);
	resul = multiply_matrix_tuple(transform, v);
	TEST_ASSERT_EQUAL_DOUBLE(-8, resul.x);
	TEST_ASSERT_EQUAL_DOUBLE(18, resul.y);
	TEST_ASSERT_EQUAL_DOUBLE(32, resul.z);
	TEST_ASSERT_EQUAL_DOUBLE(0, resul.w);
}

void	mult_inverse_scaling_matrix(void)
{
	t_matrix	transform;
	t_matrix	inver_matrix;
	t_vector		resul;
	t_vector		v;

	transform = scaling(2, 3, 4);
	inver_matrix = inverse_matrix(transform);
	v = create_vector(-4, 6, 8);
	resul = multiply_matrix_tuple(inver_matrix, v);
	TEST_ASSERT_EQUAL_DOUBLE(-2, resul.x);
	TEST_ASSERT_EQUAL_DOUBLE(2, resul.y);
	TEST_ASSERT_EQUAL_DOUBLE(2, resul.z);
	TEST_ASSERT_EQUAL_DOUBLE(0, resul.w);
}

void	test_reflection_scaling_negative_value(void)
{
	t_matrix	transform;
	t_point		resul;
	t_point		p;

	transform = scaling(-1, 1, 1);
	p = create_point(2, 3, 4);
	resul = multiply_matrix_tuple(transform, p);
	TEST_ASSERT_EQUAL_DOUBLE(-2, resul.x);
	TEST_ASSERT_EQUAL_DOUBLE(3, resul.y);
	TEST_ASSERT_EQUAL_DOUBLE(4, resul.z);
	TEST_ASSERT_EQUAL_DOUBLE(1, resul.w);
}

void    test_individual_transformations(void)
{
	t_point		p;
	t_matrix	rotation;
	t_matrix	scal;
	t_matrix	trans;
	t_point		result;

	p = create_point(1, 0, 1);
	rotation = rotation_x(M_PI / 2);
	scal = scaling(5, 5, 5);
	trans = translation(10, 5, 7);
	result = multiply_matrix_tuple(rotation, p);
	result = multiply_matrix_tuple(scal, result);
	result = multiply_matrix_tuple(trans, result);
	TEST_ASSERT_EQUAL_DOUBLE(15, result.x);
	TEST_ASSERT_EQUAL_DOUBLE(0, result.y);
	TEST_ASSERT_EQUAL_DOUBLE(7, result.z);
	TEST_ASSERT_EQUAL_DOUBLE(1, result.w);
}

void    test_chained_transformations(void)
{
	t_point		p;
	t_matrix	rotation;
	t_matrix	scal;
	t_matrix	trans;
	t_matrix	transformation;
	t_matrix	aux;
	t_point		result;

	p = create_point(1, 0, 1);
	rotation = rotation_x(M_PI / 2);
	scal = scaling(5, 5, 5);
	trans = translation(10, 5, 7);
	aux = multiply_matrix(trans, scal);
	transformation = multiply_matrix(aux, rotation);
	result = multiply_matrix_tuple(transformation, p);
	TEST_ASSERT_EQUAL_DOUBLE(15, result.x);
	TEST_ASSERT_EQUAL_DOUBLE(0, result.y);
	TEST_ASSERT_EQUAL_DOUBLE(7, result.z);
	TEST_ASSERT_EQUAL_DOUBLE(1, result.w);
}

void	test_transformations_matrix(void)
{
	RUN_TEST(test_mult_translation_matrix);
	RUN_TEST(test_mult_inverse_translation_matrix);
	RUN_TEST(test_translation_not_effect_vectors);
	RUN_TEST(test_scaling_matrix_applied_vector);
	RUN_TEST(test_scaling_matrix_applied_point);
	RUN_TEST(mult_inverse_scaling_matrix);
	RUN_TEST(test_reflection_scaling_negative_value);
	RUN_TEST(test_individual_transformations);
	RUN_TEST(test_chained_transformations);
}