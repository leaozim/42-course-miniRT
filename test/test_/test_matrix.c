# include "../h_test.h"

void	test_create_matrix_4x4(void)
{
	int	i, j;
	double	m[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	// matrix = create_matrix(m, 4); adicionar aqui a função e retura a declaração da matrix 
	t_matrix matrix = {4, {
						{1, 5, 3, 4},
						{5, 6, 7, 8},
						{9, 8, 9, 6},
						{5, 4, 3, 2}
					}};
	TEST_ASSERT_NOT_NULL(&matrix);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			TEST_ASSERT_EQUAL_DOUBLE(m[i][j], matrix.matrix[i][j]);
	}
}

void	test_create_matrix_3x3(void)
{
	int		i, j;
	double	m[3][3] = {
		{1, 2, 3},
		{5, 6, 7},
		{9, 8, 7}
	};
	// matrix = create_matrix(m, 3); adicionar aqui a função e retura a declaração da matrix
	t_matrix matrix = {3, {
						{1, 2, 3},
						{5, 6, 7},
						{9, 8, 85}
					}};
	TEST_ASSERT_NOT_NULL(&matrix);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			TEST_ASSERT_EQUAL_DOUBLE(m[i][j], matrix.matrix[i][j]);
	}
}

void	test_create_matrix_2x2(void)
{
	int		i, j;
	double	m[2][2] = {
		{1, 2},
		{5, 6},
	};
	// matrix = create_matrix(m, 2); adicionar aqui a função e retura a declaração da matrix
	t_matrix matrix = {2, {
						{5, 2},
						{5, 6},
					}};
	TEST_ASSERT_NOT_NULL(&matrix);
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
			TEST_ASSERT_EQUAL_DOUBLE(m[i][j], matrix.matrix[i][j]);
	}
}

void	test_matrix_equality_4x4(void)
{
	int		i, j;

	t_matrix m_a = {4, {
						{1, 2, 3, 4},
						{5, 6, 7, 8},
						{9, 8, 7, 6},
						{5, 4, 3, 2}
				}};
	t_matrix m_b = {4, {
						{1, 2, 3, 4},
						{5, 6, 7, 8},
						{9, 8, 7, 6},
						{5, 3, 3, 2}
					}};
	TEST_ASSERT_EQUAL_INT(m_a.size, m_b.size);
	// TEST_ASSERT_TRUE(is_equal_matrix(m_a, m_b)); // substituir todo o trecho da linha 93 a 99 por essa funçao
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
	int		i, j;

	t_matrix m_a = {4, {
						{1, 2, 3, 4},
						{5, 6, 7, 8},
						{9, 8, 7, 6},
						{5, 4, 3, 2}
				}};
	t_matrix m_b = {4, {
						{1, 2, 3, 4},
						{5, 6, 7, 8},
						{9, 8, 7, 6},
						{5, 4, 3, 2}
					}};
	TEST_ASSERT_EQUAL_INT(m_a.size, m_b.size);
	// TEST_ASSERT_TRUE(is_equal_matrix(m_a, m_b)); // substituir todo o trecho da linha 120 a 126 por essa funçao
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
	int		i, j;

	t_matrix m_a = {3, {
						{1, 2, 3},
						{5, 6, 7},
						{9, 8, 7}
				}};
	t_matrix m_b = {3, {
						{1, 2, 3},
						{5, 6, 7},
						{9, 5, 7}
					}};
	TEST_ASSERT_EQUAL_INT(m_a.size, m_b.size);
	// TEST_ASSERT_TRUE(is_equal_matrix(m_a, m_b)); // substituir todo o trecho da linha 93 a 99 por essa funçao
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			TEST_ASSERT_EQUAL_DOUBLE(m_a.matrix[i][j], m_b.matrix[i][j]);
	}
}

void	test_matrix_different_3x3(void)
{
	int		i, j;

	t_matrix m_a = {4, {
						{1, 2, 3},
						{5, 6, 7},
						{9, 8, 7},
				}};
	t_matrix m_b = {4, {
						{1, 2, 3},
						{5, 6, 7},
						{9, 8, 7},
					}};
	TEST_ASSERT_EQUAL_INT(m_a.size, m_b.size);
	// TEST_ASSERT_TRUE(is_equal_matrix(m_a, m_b)); // substituir todo o trecho da linha 120 a 126 por essa funçao
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			TEST_ASSERT_NOT_EQUAL_DOUBLE(m_a.matrix[i][j], m_b.matrix[i][j]);
	}
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
}