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
