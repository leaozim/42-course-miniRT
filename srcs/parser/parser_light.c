#include "minirt.h"

int parser_light(char **tokens, t_scene *scene)
{
	(void)scene;
	if (ft_array_size(tokens) != 3)
		return (error_msg("To many or few arguments for Light!"), ERROR);
	else if (check_coordinates(tokens[1]))
		return (error_msg("Light orientation are invalid!"), ERROR);
	else if (ft_isrange(ft_atoi(tokens[2]), 0, 1))
		return (error_msg("Light brightness is invalid! [0.0,1.0]"), ERROR);
	return (0);
}
