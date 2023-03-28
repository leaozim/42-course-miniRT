# include "../h_test.h"

void	test_create_matrix_4x4()
{
	int	i, j;
	double	m[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	// matrix = create_matrix(m, 4); adicionar aqui a função 
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

void	test_create_matrix_3x3()
{
	int		i, j;
	double	m[3][3] = {
		{1, 2, 3},
		{5, 6, 7},
		{9, 8, 7}
	};
	// matrix = create_matrix(m, 3); adicionar aqui a função 
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

void test_matrix(void)
{
	RUN_TEST(test_create_matrix_4x4);
	RUN_TEST(test_create_matrix_3x3);

}