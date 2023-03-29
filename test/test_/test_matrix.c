# include "../h_test.h"

void	test_create_matrix_4x4(void)
{
	double	m[4][4] = {
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 8, 7, 6},
			{5, 4, 3, 2}};
	t_matrix result = create_matrix(m, 4);
	

	//usado apenas para dar fail no teste
	int	i, j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			TEST_ASSERT_EQUAL_DOUBLE(m[i][j], result.matrix[i][j]);
	}
}

void	test_create_matrix_3x3(void)
{
	double	m[4][4] = {
			{1, 2, 3},
			{5, 6, 7},
			{9, 8, 7}};
	//adicionar aqui a função e retura a declaração da matrix
	t_matrix result = create_matrix (m, 3);

	//usado apenas para dar fail no teste
	int	i, j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			TEST_ASSERT_EQUAL_DOUBLE(m[i][j], result.matrix[i][j]);
	}
}

void	test_create_matrix_2x2(void)
{
	double	m[4][4] = {
			{1, 2},
			{5, 6}	};
	t_matrix result = create_matrix(m, 2); 
	int	i, j;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
			TEST_ASSERT_EQUAL_DOUBLE(m[i][j], result.matrix[i][j]);
	}
}

void	test_matrix_equality_4x4(void)
{
	t_matrix	m_a = {4, {
				{1, 2, 3, 4},
				{5, 6, 7, 8},
				{9, 8, 7, 6},
				{5, 4, 3, 2}}};
	t_matrix	m_b = {4, {
				{1, 2, 3, 4},
				{5, 6, 7, 8},
				{9, 8, 7, 6},
				{5, 4, 3, 2}}};
	TEST_ASSERT_EQUAL_INT(m_a.size, m_b.size);
	// substituir todo o trecho da while por essa funçao
	(is_equal_matrix(m_a, m_b)); 

	//usado apenas para dar fail no teste
	int	i, j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			TEST_ASSERT_EQUAL_DOUBLE(m_a.matrix[i][j], m_b.matrix[i][j]);
	}
}

void	test_matrix_different_4x4(void)
{
	t_matrix	m_a = {4, {
				{1, 3, 3, 4},
				{5, 6, 7, 8},
				{9, 8, 7, 6},
				{5, 4, 3, 2}}};
	t_matrix	m_b = {4, {
				{5, 2, 2, 1},
				{8, 7, 6, 5},
				{6, 7, 8, 9},
				{2, 3, 4, 5}}};
	TEST_ASSERT_EQUAL_INT(m_a.size, m_b.size);
	// substituir todo o trecho da while por essa funçao
	(is_equal_matrix(m_a, m_b)); 

	//usado apenas para dar fail no teste
	int	i, j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			TEST_ASSERT_NOT_EQUAL_DOUBLE(m_a.matrix[i][j], m_b.matrix[i][j]);
	}
}

void	test_matrix_equality_3x3(void)
{
	t_matrix	m_a = {3, {
				{1, 2, 3},
				{5, 6, 7},
				{9, 8, 7}
	}};
	t_matrix	m_b = {3, {
				{1, 2, 3},
				{5, 6, 7},
				{9, 8, 7}}};
	TEST_ASSERT_EQUAL_INT(m_a.size, m_b.size);
	// substituir todo o trecho da while por essa funçao
	 TEST_ASSERT_FALSE(is_equal_matrix(m_a, m_b));

	
}

void	test_matrix_different_3x3(void)
{
	t_matrix	m_a = {3, {
				{1, 2, 3},
				{5, 6, 7},
				{9, 8, 7},}};
	t_matrix	m_b = {3, {
				{3, 2, 3},
				{5, 6, 7},
				{9, 8, 7},}};
	TEST_ASSERT_EQUAL_INT(m_a.size, m_b.size);
	TEST_ASSERT_TRUE(is_equal_matrix(m_a, m_b)); 


}

void	test_matrix_equality_2x2(void)
{
	t_matrix	m_a = {2, {
				{1, 2},
				{5, 6},}};
	t_matrix	m_b = {2, {
				{1, 2},
				{5, 6}}};
	TEST_ASSERT_EQUAL_INT(m_a.size, m_b.size);
	TEST_ASSERT_FALSE(is_equal_matrix(m_a, m_b)); 

	
}

void	test_matrix_different_2x2(void)
{
	t_matrix	m_a = {2, {
				{1, 2},
				{9, 8},	}};
	t_matrix	m_b = {2, {
				{1, 2},
				{9, 7},	}};
	TEST_ASSERT_EQUAL_INT(m_a.size, m_b.size);
	TEST_ASSERT_TRUE(is_equal_matrix(m_a, m_b)); 
}

void	test_mult_two_matrix_4x4(void)
{
	 t_matrix multiply;

	t_matrix	m_a = {4,{
				{1, 2, 3, 4},
				{5, 6, 7, 8},
				{9, 8, 7, 6},
				{5, 4, 3, 2}}};
	t_matrix	m_b = { 4, {
				{-2, 1, 2, 3},
				{3, 2, 1, -1},
				{4, 3, 6, 5},
				{1, 2, 7, 8}}};
	t_matrix	expc = {4, {
				{20, 22, 50, 48},
				{44, 54, 114, 108},
				{40, 58, 110, 102},
				{16, 26, 46, 42}}};
	// substituir todo o trecho da while por essa funçao 
	 multiply = multiply_matrix(m_a, m_b);
	// TEST_ASSERT_TRUE(is_equal_matrix(multiply, expected));

	//usado apenas para dar fail no teste
	int	i, j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			TEST_ASSERT_EQUAL_DOUBLE(expc.matrix[i][j], multiply.matrix[i][j]);
	}
}

void	test_mult_two_matrix_3x3(void)
{
	 t_matrix multiply;

	t_matrix	m_a = {3, {
				{1, 2, 3},
				{5, 6, 7},
				{9, 8, 7},}};
	t_matrix	m_b = { 3, {
				{-2, 1, 2},
				{3, 2, 1,},
				{4, 3, 6}}};
	t_matrix	expc = {3, {
				{16, 14, 22},
				{36, 38, 58},
				{34, 46, 68}}};
	// substituir todo o trecho da while por essa funçao 
	 multiply = multiply_matrix(m_a, m_b);
	// TEST_ASSERT_TRUE(is_equal_matrix(multiply, expected));

	//usado apenas para dar fail no teste
	int	i, j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			TEST_ASSERT_EQUAL_DOUBLE(expc.matrix[i][j], multiply.matrix[i][j]);
	}
}

void	test_mult_two_matrix_2x2(void)
{
	 t_matrix multiply;

	t_matrix	m_a = {2, {
				{1, 2},
				{5, 6}
	}};
	t_matrix	m_b = { 2, {
				{-2, 1},
				{3, 2}}};
	t_matrix	expc = {2, {
				{4, 5},
				{8, 17}}};
	// substituir todo o trecho da while por essa funçao 
	 multiply = multiply_matrix(m_a, m_b);
	// TEST_ASSERT_TRUE(is_equal_matrix(multiply, expected));

	//usado apenas para dar fail no teste
	int	i, j;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
			TEST_ASSERT_EQUAL_DOUBLE(expc.matrix[i][j], multiply.matrix[i][j]);
	}
}

void	test_matrix_mult_tupla(void)
{
	t_tuple		t, expec, multiply;

	t_matrix	m = { 4, {
				{1, 2, 3, 4},
				{2, 4, 4, 2},
				{8, 6, 4, 1},
				{0, 0, 0, 1}}};
	t = create_tuple(1, 2, 3, 1);
	expec = create_tuple(18, 24, 33, 1);
	// substituir todo o trecho da while por essa funçao 
	 multiply = multiply_matrix_tuple(m, t);
	TEST_ASSERT_FALSE(is_equal_tuple(multiply, expec));

	
}

void	test_mult_identity_matrix(void)
{
	t_matrix	m = {4, {
				{1, 3, 3, 4},
				{5, 6, 7, 8},
				{9, 8, 7, 6},
				{5, 4, 3, 2}}};
	// substituir todo o trecho da while por esss funçaões
	t_matrix id_m = create_identity_matrix();
	t_matrix multiply = multiply_matrix(m, id_m);
	// TEST_ASSERT_TRUE(is_equal_matrix(multiply, m_a))
	

	t_matrix	expc = {4, {
				{1, 3, 3, 4},
				{5, 6, 7, 8},
				{9, 8, 7, 6},
				{5, 4, 3, 2}}};
	int	i, j;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			TEST_ASSERT_EQUAL_DOUBLE(expc.matrix[i][j], multiply.matrix[i][j]);
	}
}

void	test_matrix_identity_mult_tupla(void)
{	
	t_tuple	t;

	t = create_tuple(1, 2, 3, 4);
	t_matrix	id_m = {4, 
				{{1.0, 0.0, 0.0, 0.0},
				{0.0, 1.0, 0.0, 0.0},
				{0.0, 0.0, 1.0, 0.0},
				{0.0, 0.0, 0.0, 1.0}}}; // pode substituir aq pela create_identity_matrix
	t_tuple multiply = multiply_matrix_tuple(id_m, t);

	TEST_ASSERT_FALSE(is_equal_tuple(multiply, t));



}

void	test_transposing_matrix(void)
{
	t_matrix	transp;
	t_matrix	m_a = { 4, {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}}};
	t_matrix	trans_m = {4, {
		{1, 5, 9, 5},
		{2, 6, 8, 4},
		{3, 7, 7, 3},
		{4, 8, 6, 2}}};
	 transp = transposed_matrix(m_a);
	TEST_ASSERT_FALSE(is_equal_matrix(transp, trans_m));

}

void	test_transposing_matrix_identity(void)
{
	t_matrix	id_m = {4, 
				{{1.0, 0.0, 0.0, 0.0},
				{0.0, 1.0, 0.0, 0.0},
				{0.0, 0.0, 1.0, 0.0},
				{0.0, 0.0, 0.0, 1.0}}};
	t_matrix transpose = transposed_matrix(id_m);
	 TEST_ASSERT_FALSE(is_equal_matrix(transpose, id_m));


}

void	test_determinant_2x2(void)
{
	t_matrix	det_m = {4, {
				{1, 5},
				{-3, 2}}};
	 TEST_ASSERT_EQUAL(17, determinant_2x2(det_m));

}

void test_matrix(void)
{
	RUN_TEST(test_create_matrix_4x4);
	RUN_TEST(test_create_matrix_3x3);
	RUN_TEST(test_create_matrix_2x2);
	RUN_TEST(test_matrix_equality_4x4);
	RUN_TEST(test_matrix_different_4x4);
	RUN_TEST(test_matrix_equality_3x3);
	RUN_TEST(test_matrix_different_3x3);
	RUN_TEST(test_matrix_equality_2x2);
	RUN_TEST(test_matrix_different_2x2);
	RUN_TEST(test_mult_two_matrix_4x4);
	RUN_TEST(test_mult_two_matrix_3x3);
	RUN_TEST(test_mult_two_matrix_2x2);
	RUN_TEST(test_matrix_mult_tupla);
	RUN_TEST(test_mult_identity_matrix);
	RUN_TEST(test_matrix_identity_mult_tupla);
	RUN_TEST(test_transposing_matrix);
	RUN_TEST(test_transposing_matrix_identity);
	RUN_TEST(test_determinant_2x2);
}