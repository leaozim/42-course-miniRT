#include "minirt.h"

t_matrix	create_matrix(double m[4][4], size_t size)
{
	size_t		i;
	size_t		j;
	t_matrix	matrix;

	i = 0;
	j = 0;
	matrix.size = size;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			matrix.matrix[i][j] = m[i][j];
			j++;
		}
		i++;
	}
	return (matrix);
}
