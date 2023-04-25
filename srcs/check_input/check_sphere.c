#include "minirt.h"

int	check_id_sp(char **tokens)
{
	double	diameter;

	if (ft_array_size(tokens) != 4)
		return (error_msg(ERROR_MANY_ARGC_SP), ft_free_array(tokens), ERROR);
	diameter = ft_atof(tokens[2]);
	if (check_coordinates(tokens[1]))
		return (error_msg(ERROR_ORI_SP), ft_free_array(tokens), ERROR);
	if (!ft_isfloat(tokens[2]) || diameter <= 0 || diameter > 1000)
		return (error_msg(ERROR_FLOAT_SP), ft_free_array(tokens), ERROR);
	if (check_color(tokens[3]))
		return (ft_free_array(tokens), ERROR);
	ft_free_array(tokens);
	return (OK);
}
