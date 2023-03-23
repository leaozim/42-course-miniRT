#include "minirt.h"

void	create_camera(char **tokens, t_scene *scene)
{
	scene->camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	scene->camera->point_of_view = \
	(t_point)(create_parameter(tokens[1], create_point));
	scene->camera->vector = \
	(t_vector)(create_parameter(tokens[2], create_vector));
	scene->camera->field_of_view = ft_atof(tokens[3]);
	ft_free_array(tokens);
}

int	check_id_c(char **tokens)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg(ERROR_MANY_ARGC_C), ft_free_array(tokens), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg(ERROR_COOR_C), ft_free_array(tokens), ERROR);
	if (check_orientation(tokens[2]))
		return (ft_free_array(tokens), error_msg(ERROR_ORI_C), ERROR);
	if (ft_isrange(ft_atoi(tokens[3]), 0, 180))
		return (error_msg(ERROR_FOV), ERROR);
	ft_free_array(tokens);
	return (OK);
}
