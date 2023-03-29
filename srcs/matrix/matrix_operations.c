#include "minirt.h"

int	is_equal_matrix(t_matrix a, t_matrix b)
{
	size_t	row;
	size_t	col;

	if (a.size != b.size)
		return (ERROR);
	row = 0;
	while (row < a.size)
	{
		col = 0;
		while (col < a.size)
		{
			if (is_equal_double(a.matrix[row][col], b.matrix[row][col]))
				return (ERROR);
			col++;
		}
		row++;
	}
	return (OK);
}

t_matrix	multiply_matrix(t_matrix a, t_matrix b)
{
	size_t		i;
	size_t		j;
	size_t		k;
	double		sum;
	t_matrix	result;

	if (a.size != b.size)
		return (error_msg("ERROR: matrix size mismatch\n"), a);
	result.size = a.size;
	i = -1;
	while (++i < a.size)
	{
		j = -1;
		while (++j < a.size)
		{
			sum = 0;
			k = -1;
			while (++k < a.size)
				sum += a.matrix[i][k] * b.matrix[k][j];
			result.matrix[i][j] = sum;
		}
	}
	return (result);
}

t_tuple	multiply_matrix_tuple(t_matrix m, t_tuple t)
{
	size_t	row;
	double	aux[MTRX_MAX];

	if (m.size != MTRX_MAX)
		return (create_tuple(0, 0, 0, 0));
	row = 0;
	while (row < MTRX_MAX)
	{
		aux[row] = \
			(m.matrix[row][0] * t.x) + \
			(m.matrix[row][1] * t.y) + \
			(m.matrix[row][2] * t.z) + \
			(m.matrix[row][3] * t.w);
		++row;
	}
	return (create_tuple(aux[0], aux[1], aux[2], aux[3]));
}

t_matrix	transposed_matrix(t_matrix matrix)
{
	size_t		i;
	size_t		j;
	t_matrix	transposed;

	transposed.size = matrix.size;
	i = 0;
	while (i < matrix.size)
	{
		j = 0;
		while (j < matrix.size)
		{
			transposed.matrix[j][i] = matrix.matrix[i][j];
			j++;
		}
		i++;
	}
	return (transposed);
}

double	determinant_2x2(t_matrix m)
{
	return (
		(m.matrix[0][0] * m.matrix[1][1]) - \
		(m.matrix[0][1] * m.matrix[1][0])
	);
}
