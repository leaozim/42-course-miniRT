#include "minirt.h"

int	is_equal_matrix(t_matrix a, t_matrix b)
{
	size_t	row;
	size_t	col;

	if (a.size != b.size)
		return (FALSE);
	row = 0;
	while (row < a.size)
	{
		col = 0;
		while (col < a.size)
		{
			if (!is_equal_double(a.matrix[row][col], b.matrix[row][col]))
				return (FALSE);
			col++;
		}
		row++;
	}
	return (TRUE);
}
