#include "minirt.h"

int check_id_p(char **tokens)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg(ERROR_MANY_ARGC_PL), ERROR);
	else if (check_coordinates(tokens[1]))
		return (error_msg(ERROR_COOR_PL), ERROR);
	else if (check_orientation(tokens[2]))
		return (ERROR);
	if (check_color(tokens[3]))
		return (error_msg(ERROR_INVALID_RGB), ERROR);
	return (OK);
}
