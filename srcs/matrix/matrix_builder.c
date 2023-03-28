#include "minirt.h"

t_matrix	create_matrix(double m[4][4], size_t size)
{
	int			i;
	int			j;
	t_matrix	matrix;

	i = 0;
	j = 0;
	matrix.size = size;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix.matrix[i][j] = m[i][j];
			j++;
		}
		i++;
	}
	return (matrix);
}
