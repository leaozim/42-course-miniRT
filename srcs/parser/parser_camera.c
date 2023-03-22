#include "minirt.h"

void	fill_camera(char **tokens,  t_scene *scene)
{
	scene->camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	scene->camera->field_of_view = ft_atof(tokens[3]);
	scene->camera->point_of_view = (t_point)(create_parameter(tokens[1], create_point));
	scene->camera->vector = (t_vector)(create_parameter(tokens[2], create_vector));
}

int	check_id_c(char **tokens)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg("To many or few arguments for camera!"), ERROR);
	if (is_invalid_file_data(tokens))
		return (error_msg("File data are invaded!"), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg("Camera coordinates are invaded!"), ERROR);
	if (check_orientation(tokens[2]))
		return (ERROR);
	if (ft_isrange(ft_atoi(tokens[3]), 0, 180))
		return (error_msg("FOV is invalid!"), ERROR);
	ft_free_array(tokens);
	return (OK);
}
