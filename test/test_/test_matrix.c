# include "../h_test.h"

void	test_create_matrix_4x4(void)
{
	int	i, j;
	double	m[4][4] = {
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 8, 7, 6},
			{5, 4, 3, 2}};
	t_matrix result = create_matrix(m, 4);
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
	int	i, j;
	double	m[4][4] = {
			{1, 2, 3},
			{5, 6, 7},
			{9, 8, 7}};
	t_matrix result = create_matrix (m, 3);
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
	int	i, j;
	double	m[4][4] = {
			{1, 2},
			{5, 6}	};
	t_matrix result = create_matrix(m, 2); 
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
	TEST_ASSERT_TRUE(is_equal_matrix(m_a, m_b)); 
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
	TEST_ASSERT_FALSE(is_equal_matrix(m_a, m_b)); 
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
	TEST_ASSERT_TRUE(is_equal_matrix(m_a, m_b));
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
				{9, 1, 7},}};
	TEST_ASSERT_FALSE(is_equal_matrix(m_a, m_b)); 
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
	TEST_ASSERT_TRUE(is_equal_matrix(m_a, m_b)); 
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
	TEST_ASSERT_FALSE(is_equal_matrix(m_a, m_b)); 
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
	 multiply = multiply_matrix(m_a, m_b);
	TEST_ASSERT_TRUE(is_equal_matrix(multiply, expc));
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
	multiply = multiply_matrix(m_a, m_b);
	TEST_ASSERT_TRUE(is_equal_matrix(multiply, expc));
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
	 multiply = multiply_matrix(m_a, m_b);
	TEST_ASSERT_TRUE(is_equal_matrix(multiply, expc));
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
	multiply = multiply_matrix_tuple(m, t);
	TEST_ASSERT_TRUE(is_equal_tuple(multiply, expec));
}

void	test_mult_identity_matrix(void)
{
	t_matrix	m = {4, {
				{1, 3, 3, 4},
				{5, 6, 7, 8},
				{9, 8, 7, 6},
				{5, 4, 3, 2}}};
	t_matrix id_m = create_identity_matrix();
	t_matrix multiply = multiply_matrix(m, id_m);
	TEST_ASSERT_TRUE(is_equal_matrix(multiply, m));
}

void	test_matrix_identity_mult_tupla(void)
{	
	t_tuple	t;

	t = create_tuple(1, 2, 3, 4);
	t_matrix	id_m = {4, 
				{{1.0, 0.0, 0.0, 0.0},
				{0.0, 1.0, 0.0, 0.0},
				{0.0, 0.0, 1.0, 0.0},
				{0.0, 0.0, 0.0, 1.0}}};
	t_tuple multiply = multiply_matrix_tuple(id_m, t);
	TEST_ASSERT_TRUE(is_equal_tuple(multiply, t));
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
	TEST_ASSERT_TRUE(is_equal_matrix(transp, trans_m));

}

void	test_transposing_matrix_identity(void)
{
	t_matrix	id_m = {4, 
				{{1.0, 0.0, 0.0, 0.0},
				{0.0, 1.0, 0.0, 0.0},
				{0.0, 0.0, 1.0, 0.0},
				{0.0, 0.0, 0.0, 1.0}}};
	t_matrix transpose = transposed_matrix(id_m);
	TEST_ASSERT_TRUE(is_equal_matrix(transpose, id_m));
}

void	test_determinant_2x2(void)
{
	t_matrix	det_m = {2, {
				{1, 5},
				{-3, 2}}};
	 TEST_ASSERT_EQUAL(17, determinant(det_m));
}

void	test_submatrix_3x3(void)
{
	t_matrix matrix = {3,{
						{1, 5, 0},
						{-3, 2, 7},
						{0, 6, -3}}};
	t_matrix expec ={2,{
						{-3, 2},
						{0, 6}}};	
	t_matrix sub = submatrix(matrix, 0, 2);
	TEST_ASSERT_TRUE(is_equal_matrix(sub, expec));
}

void	test_submatrix_4x4(void)
{
	t_matrix matrix = {4,{
						{-6, 1, 1, 6},
						{-8, 5, 8, 6},
						{-1, 0, 8, 2},
						{-7, 1, -1, 1}}};
	t_matrix expec ={3,{
						{-6, 1, 6},
						{-8, 8, 6},
						{-7, -1, 1}}};	
	t_matrix sub = submatrix(matrix, 2, 1);
	TEST_ASSERT_TRUE(is_equal_matrix(sub, expec));
}

void	test_minor_3x3(void)
{
	t_matrix matrix = {3,{
						{3, 5, 0},
						{2, -1, -7},
						{6, -1, 5}}};
	double expec = 25;	
	double min = minor(matrix, 1, 0);
	TEST_ASSERT_EQUAL_DOUBLE(min, expec);
}

void	test_cofactor_3x3(void)
{
	t_matrix matrix = {3,{
						{3, 5, 0},
						{2, -1, -7},
						{6, -1, 5}}};
	double expec = -12;	
	double cof = cofactor(matrix, 0, 0);
	TEST_ASSERT_EQUAL_DOUBLE(cof, expec);
	expec = -25;
	cof = cofactor(matrix, 1, 0);
	TEST_ASSERT_EQUAL_DOUBLE(cof, expec);
}

void	test_determinant_3x3(void)
{
	t_matrix matrix = {3,{
						{1, 2, 6},
						{-5, 8, -4},
						{2, 6, 4}}};
	double expec = -196;	
	double det = determinant(matrix);
	TEST_ASSERT_EQUAL_DOUBLE(det, expec);
}

void	test_determinant_4x4(void)
{
	t_matrix matrix = {4,{
						{-2, -8, 3, 5},
						{-3, 1, 7, 3},
						{1, 2, -9, 6},
						{-6, 7, 7, -9}}};
	double expec = -4071;	
	double det = determinant(matrix);
	TEST_ASSERT_EQUAL_DOUBLE(det, expec);
}

void	test_invertible(void)
{
	t_matrix matrix = {4,{
						{-4, 2, -2, -3},
						{9, 6, 2, 6},
						{0, -5, 1, -5},
						{0, 0, 0, 0}}};
	double expec = 0;
	double inv = is_invertible(matrix);
	TEST_ASSERT_EQUAL_DOUBLE(inv, expec);	
}

void	test_inverse(void)
{
	t_matrix matrix = {4,{
						{-5, 2, 6, -8},
						{1, -5, 1, 8},
						{7, 7, -6, -7},
						{1, -3, 7, 4}}};
	t_matrix reverse_expec = {4,{
						{0.21805, 0.45113, 0.24060, -0.04511},
						{-0.80827, -1.45677, -0.44361, 0.52068},
						{-0.07895, -0.22368, -0.05263, 0.19737},
						{-0.52256, -0.81391, -0.30075, 0.30639}}};
	t_matrix reverse = inverse_matrix(matrix);
	double expec = 532;	
	double det = determinant(matrix);
	TEST_ASSERT_EQUAL_DOUBLE(det, expec);
	expec = -160;
	double cof = cofactor(matrix, 2, 3);
	TEST_ASSERT_EQUAL_DOUBLE(cof, expec);
	expec = 105;
	cof = cofactor(matrix, 3, 2);
	TEST_ASSERT_EQUAL_DOUBLE(cof, expec);
	TEST_ASSERT_TRUE(is_equal_matrix(reverse_expec, reverse));
}

void	test_mult_inverse(void)
{
	t_matrix a = {4,{
						{-3, -9, 7, 3},
						{3, -8, 2, -9},
						{-4, 4, 4, 1},
						{-6, 5, -1, 1}}};
	t_matrix b = {4,{
						{8, 2, 2, 2},
						{3, -1, 7, 0},
						{7, 0, 5, 4},
						{6, -2, 0, 5}}};
	t_matrix c = multiply_matrix(a, b);
	t_matrix result = multiply_matrix(c, inverse_matrix(b));
	TEST_ASSERT_TRUE(is_equal_matrix(result, a));
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
	RUN_TEST(test_submatrix_3x3);
	RUN_TEST(test_submatrix_4x4);
	RUN_TEST(test_minor_3x3);
	RUN_TEST(test_cofactor_3x3);
	RUN_TEST(test_determinant_3x3);
	RUN_TEST(test_determinant_4x4);
	RUN_TEST(test_invertible);
	RUN_TEST(test_inverse);
	RUN_TEST(test_mult_inverse);
}