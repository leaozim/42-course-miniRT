#include "minirt.h"

t_matrix	create_matrix(double m[MTRX_MAX][MTRX_MAX], size_t size)
{
	t_matrix	matrix;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	matrix.size = size;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i < size && j < 4)
				matrix.matrix[i][j] = m[i][j];
			else
				matrix.matrix[i][j] = 0.0;
			j++;
		}
		i++;
	}
	return (matrix);
}

t_matrix	create_identity_matrix(void)
{
	t_matrix	identity_matrix;
	size_t		row;
	size_t		col;

	row = 0;
	col = 0;
	identity_matrix.size = 4;
	while (row < identity_matrix.size && col < identity_matrix.size)
	{
		if (row == col)
			identity_matrix.matrix[row][col] = 1;
		else
			identity_matrix.matrix[row][col] = 0;
		if (col == identity_matrix.size - 1)
		{
			col = 0;
			row++;
		}
		else
			col++;
	}
	return (identity_matrix);
}

t_matrix	submatrix(t_matrix matrix, size_t row, size_t col)
{
	t_matrix	new_matrix;
	size_t		i;
	size_t		j;
	size_t		new_c;
	size_t		new_r;

	i = -1;
	new_c = 0;
	new_matrix.size = matrix.size - 1;
	while (++i < matrix.size)
	{
		if (i == row)
			continue ;
		j = -1;
		new_r = 0;
		while (++j < matrix.size)
		{
			if (j == col)
				continue ;
			new_matrix.matrix[new_c][new_r] = matrix.matrix[i][j];
			new_r++;
		}
		new_c++;
	}
	return (new_matrix);
}
