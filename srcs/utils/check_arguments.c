#include "minirt.h"

int	check_argc(int argc)
{
	if (argc == 2)
		return (OK);
	if (argc < 2)
		return (error_msg("Need to add scene file!"), ERROR);
	else
		return (error_msg("Too many arguments!"), ERROR);
}
