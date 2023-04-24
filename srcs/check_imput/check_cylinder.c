#include "minirt.h"

int	check_id_cy(char **tokens)
{
	if (ft_array_size(tokens) != 6)
		return (error_msg(ERROR_MANY_ARGC_CY), ft_free_array(tokens), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg(ERROR_COOR_CY), ft_free_array(tokens), ERROR);
	if (check_orientation(tokens[2]))
		return (ft_free_array(tokens), ERROR);
	if (!ft_isfloat(tokens[3]) || !ft_isfloat(tokens[4]))
		return (error_msg(ERROR_FLOAT_CY), ft_free_array(tokens), ERROR);
	if (check_color(tokens[5]))
		return (ft_free_array(tokens), ERROR);
	ft_free_array(tokens);
	return (OK);
}
