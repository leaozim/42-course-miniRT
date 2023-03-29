#include "minirt.h"

t_matrix	create_matrix(double m[][4], size_t size)
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
			row++;
			col = 0;
		}
		else
			col++;
	}
	return (identity_matrix);
}
