#include "minirt.h"

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

double	determinant_2x2(t_matrix m)
{
	return (
		(m.matrix[0][0] * m.matrix[1][1]) - \
		(m.matrix[0][1] * m.matrix[1][0])
	);
} 

double	cofactor(t_matrix matrix, size_t row, size_t col)
{
	double	mi;

	mi = minor(matrix, row, col);
	if ((row + col) % 2 == 0)
		return (mi);
	return (-mi);

}

double	determinant(t_matrix m)
{
	size_t	col;
	double	deter;

	if (m.size == 2)
		return (determinant_2x2(m));
	deter = 0;
	col = 0;
	while (col < m.size)
	{
		deter += m.matrix[0][col] * cofactor(m, 0, col);
		++col;
	}
	return (deter);
}

double	minor(t_matrix matrix, size_t row, size_t col)
{
	t_matrix	new_matrix;
	double		minor;

	new_matrix = submatrix(matrix, row, col);
	minor = determinant(new_matrix);
	return (minor);
}

double	is_invertible(t_matrix matrix)
{
	return (determinant(matrix));
}

t_matrix	inverse_matrix(t_matrix matrix)
{
	size_t			row;
	size_t			col;
	t_matrix		inver_m;

	if (!is_invertible(matrix))
		return (matrix);
	row = -1; 
	while (++row < matrix.size)
	{
		col = -1;
		while (col < matrix.size)
			inver_m.matrix[col][row] = cofactor(matrix, row, col) / determinant(matrix);
	}
	inver_m.size = matrix.size;
	return (inver_m);
}
