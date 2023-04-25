#include "minirt.h"

int	check_id_pl(char **tokens)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg(ERROR_MANY_ARGC_PL), ft_free_array(tokens), ERROR);
	else if (check_coordinates(tokens[1]))
		return (error_msg(ERROR_COOR_PL), ft_free_array(tokens), ERROR);
	else if (check_orientation(tokens[2]))
		return (ft_free_array(tokens), ERROR);
	if (check_color(tokens[3]))
		return (ft_free_array(tokens), ERROR);
	ft_free_array(tokens);
	return (OK);
}
