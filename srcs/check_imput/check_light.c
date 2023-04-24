#include "minirt.h"

int	check_id_l(char **tokens, t_bool *is_duplicated)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg(ERROR_MANY_ARGC_L), ft_free_array(tokens), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg(ERROR_COOR_L), ft_free_array(tokens), ERROR);
	if (ft_isrange(ft_atof(tokens[2]), 0, 1))
		return (error_msg(ERROR_BRIGHTNESS), ft_free_array(tokens), ERROR);
	if (check_color(tokens[3]))
		return (ft_free_array(tokens), ERROR);
	ft_free_array(tokens);
	is_duplicated[LIGHT] = TRUE;
	return (OK);
}
