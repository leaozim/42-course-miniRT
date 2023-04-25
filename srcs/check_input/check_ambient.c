#include "minirt.h"

int	check_id_a(char **tokens, t_bool *required_obj)
{
	if (ft_array_size(tokens) != 3)
		return (error_msg(ERROR_MANY_ARGC_A), ft_free_array(tokens), ERROR);
	else if (!ft_isfloat(tokens[1]))
		return (error_msg(ERROR_NUMBER_FLOAT_A), ft_free_array(tokens), ERROR);
	if (ft_isrange(ft_atof(tokens[1]), 0, 1))
		return (error_msg(ERROR_RANGE_A), ft_free_array(tokens), ERROR);
	if (check_color(tokens[2]))
		return (ft_free_array(tokens), ERROR);
	ft_free_array(tokens);
	required_obj[AMBIENT] = TRUE;
	return (OK);
}
