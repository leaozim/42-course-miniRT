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
