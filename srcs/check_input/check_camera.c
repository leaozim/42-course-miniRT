#include "minirt.h"

int	check_id_c(char **tokens, t_bool	*is_duplicated)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg(ERROR_MANY_ARGC_C), ft_free_array(tokens), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg(ERROR_COOR_C), ft_free_array(tokens), ERROR);
	if (check_orientation(tokens[2]))
		return (ft_free_array(tokens), ERROR);
	if (is_normalized(tokens[2]))
		return (ft_free_array(tokens), ERROR);
	if (ft_isrange(ft_atoi(tokens[3]), 0, 180))
		return (error_msg(ERROR_FOV), ERROR);
	ft_free_array(tokens);
	is_duplicated[CAMERA] = TRUE;
	return (OK);
}
