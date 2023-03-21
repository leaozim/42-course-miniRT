#include "minirt.h"

// void	fill_camera(char **tokens,  t_scene *scene)
// {
// 	scene->cylinder = (t_camera *)ft_calloc(1, sizeof(t_camera));
// 	scene->camera->field_of_view = ft_atof(tokens[3]);
// 	scene->camera->point_of_view = (t_point)(create_parameter(tokens[1], create_point));
// 	scene->camera->vector = (t_vector)(create_parameter(tokens[2], create_vector));
// }

int	check_id_cy(char **tokens, t_scene *scene)
{
	(void)scene;
	if (ft_array_size(tokens) != 6)
		return (error_msg("To many or few arguments for cylinder!"), ERROR);
	if (is_invalid_file_data(tokens))
		return (error_msg("File data are invaded!"), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg("Cylinder coordinates are invaded!"), ERROR);
	if (check_orientation(tokens[2]))
		return (ERROR);
	if (!ft_isfloat(tokens[3]) || !ft_isfloat(tokens[4]))
		return (error_msg("Parameter needs to be a Float"), ERROR);
	// fill_cylinder(tokens, scene);
	// if (check_color(tokens[5], scene))
	// 	return (ERROR);
	return (OK);
}
