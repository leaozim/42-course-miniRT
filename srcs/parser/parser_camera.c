#include "minirt.h"

t_tuple	create_tuple(double x, double y, double z, double w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

t_point	create_point(double x, double y, double z)
{
	return (create_tuple(x, y, z, POINT_W));
}

t_vector	create_vector(double x, double y, double z)
{
	return (create_tuple(x, y, z, VECTOR_W));
}

t_tuple	create_parameter(char *tokens, t_tuple (*f)(double, double, double))
{
	char	**parameter;
	double	x;
	double	y;
	double	z;

	parameter = ft_split(tokens, ',');
	x = ft_atof(parameter[0]);
	y = ft_atof(parameter[1]);
	z = ft_atof(parameter[2]);
	free(parameter);
	return(f(x, y, z));
}

void	fill_camera(char **tokens,  t_scene *scene)
{
	scene->camera = (t_camera *)ft_calloc(1, sizeof(t_camera));
	scene->camera->field_of_view = ft_atof(tokens[3]);
	scene->camera->point_of_view = (t_point)(create_parameter(tokens[1], create_point));
	scene->camera->vector = (t_vector)(create_parameter(tokens[2], create_vector));
}

int	check_id_c(char **tokens, t_scene *scene)
{
	(void)scene;
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
	fill_camera(tokens, scene);
	printf("%lf\n", scene->camera->point_of_view.z);
	printf("%f\n", scene->camera->field_of_view);
	printf("%lf\n", scene->camera->vector.z);
	return (OK);
}
