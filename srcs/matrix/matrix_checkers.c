#include "minirt.h"

static double	determinant_2x2(t_matrix m)
{
	return (
		(m.matrix[0][0] * m.matrix[1][1]) - \
		(m.matrix[0][1] * m.matrix[1][0])
	);
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

double	cofactor(t_matrix matrix, size_t row, size_t col)
{
	double	mi;

	mi = minor(matrix, row, col);
	if ((row + col) % 2 == 0)
		return (mi);
	return (-mi);
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
