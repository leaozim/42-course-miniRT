# include "../h_test.h"

void	test_mult_translation_matrix(void)
{
	t_matrix	transform;
	t_point		resul;
	t_point		p;

	transform = create_identity_matrix(); // substituir essa linha, pela função a baixo
	// transform = translate_matrix(5, -3, 2);
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

	transform = create_identity_matrix(); // substituir essa linha, pela função a baixo
	// transform = translate_matrix(5, -3, 2);
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
	// t_matrix	transform;
	t_vector		resul;
	t_vector		vec;

	t_matrix transform = {4, {
				{-3, -9, 7, 3},
				{3, -8, 2, -9},
				{-4, 4, 4, 1},
				{-6, 5, -1, 1}}}; // substituir essa linha, pela função a baixo
	// transform = translate_matrix(5, -3, 2);
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

	transform = create_identity_matrix(); // substituir essa linha, pela função a baixo
	// transform = scaling(2, 3, 4);
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

	transform = create_identity_matrix(); // substituir essa linha, pela função a baixo
	// transform = scaling(2, 3, 4);
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

	transform = create_identity_matrix(); // substituir essa linha, pela função a baixo
	// transform = scaling(2, 3, 4);
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

	transform = create_identity_matrix(); // substituir essa linha, pela função a baixo
	// transform = scaling(-1, 1, 1);
	p = create_point(2, 3, 4);
	resul = multiply_matrix_tuple(transform, p);
	TEST_ASSERT_EQUAL_DOUBLE(-2, resul.x);
	TEST_ASSERT_EQUAL_DOUBLE(3, resul.y);
	TEST_ASSERT_EQUAL_DOUBLE(4, resul.z);
	TEST_ASSERT_EQUAL_DOUBLE(0, resul.w);
}

void	test_transformations_matrix(void)
{
	RUN_TEST(test_mult_translation_matrix);
	RUN_TEST(test_mult_inverse_translation_matrix);
	RUN_TEST(test_translation_not_effect_vectors);
	RUN_TEST(test_scaling_matrix_applied_vector);
	RUN_TEST(mult_inverse_scaling_matrix);
}