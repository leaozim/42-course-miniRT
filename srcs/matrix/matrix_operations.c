#include "minirt.h"

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

t_matrix	inverse_matrix(t_matrix mtx)
{
	size_t			row;
	size_t			col;
	t_matrix		inver;

	if (!is_invertible(mtx))
		return (mtx);
	row = -1;
	while (++row < mtx.size)
	{
		col = -1;
		while (col < mtx.size)
			inver.matrix[col][row] = cofactor(mtx, row, col) / determinant(mtx);
	}
	inver.size = mtx.size;
	return (inver);
}
