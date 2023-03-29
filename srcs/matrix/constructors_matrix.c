#include "minirt.h"

t_matrix	submatrix(t_matrix matrix, size_t row, size_t column)
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
			if (j == column)
				continue ;
			new_matrix.matrix[new_c][new_r] = matrix.matrix[i][j];
			new_r++;
		}
		new_c++;
	}
	return (new_matrix);
}

double	minor(t_matrix matrix, size_t row, size_t column)
{
	t_matrix new_matrix;

	new_matrix = submatrix(matrix, row, column);
	determinante(matrix);
}

double	determinant_2x2(t_matrix m)
{
	return (
		(m.matrix[0][0] * m.matrix[1][1]) - \
		(m.matrix[0][1] * m.matrix[1][0])
	);
} 

// double	cofator(t_matrix matrix, size_t row, size_t column)
// {

// }

// t_matrix	inverse_matrix(t_matrix m)
// {

// }

double	determinant(t_matrix m)
{
	size_t	column;
	double	deter;

	if (m.size == 2)
		return (determinant2x2(m));
	deter = 0;
	column = 0;
	while (column < m.size)
	{
		deter += m.matrix[0][column] * cofactor(m, 0, column);
		++column;
	}
	return (deter);
}
