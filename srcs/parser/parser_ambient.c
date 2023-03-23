#include "minirt.h"

void	create_ambient(char **tokens, t_scene *scene)
{
	scene->ambient = (t_ambient *)ft_calloc(1, sizeof(t_ambient));
	scene->ambient->ratio = ft_atof(tokens[1]);
	scene->ambient->color = create_parameter_color(tokens[2]);
	ft_free_array(tokens);
}

int	check_id_a(char **tokens)
{
	if (ft_array_size(tokens) != 3)
		return(error_msg(ERROR_MANY_ARGC_A), ERROR);
	else if (!ft_isfloat(tokens[1]))
		return (error_msg(ERROR_NUMBER_FLOAT_A), ERROR);
	if (ft_isrange(ft_atof(tokens[1]), 0, 1))
		return (error_msg(ERROR_RANGE_A), ERROR);
	if (check_color(tokens[2]))
		return (ERROR);
	ft_free_array(tokens);
	return (OK);
}
