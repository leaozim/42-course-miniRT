#include "minirt.h"

int	check_argc(int argc)
{
	if (argc == 2)
		return (OK);
	if (argc < 2)
		return (error_msg(ERROR_NOT_FILE), ERROR);
	else
		return (error_msg(ERROR_MANY_ARGC), ERROR);
}

int	is_equal_double(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (TRUE);
	return (FALSE);
}

double	radians(double degree)
{
	return ((degree / 180) * M_PI);
}

t_bool	is_equal_vectors(t_vector a, t_vector b)
{
	return (
		is_equal_double(a.x, b.x)
		&& is_equal_double(a.y, b.y)
		&& is_equal_double(a.z, b.z)
		&& is_equal_double(a.w, b.w)
	);
}
