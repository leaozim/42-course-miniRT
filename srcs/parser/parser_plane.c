#include "minirt.h"

t_matrix	get_rotation_matrix(t_vector vector)
{
	double		x;
	double		z;
	double		ratio;
	t_matrix	mz;
	t_matrix	mx;

	ratio = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	if (is_equal_double(0.0, ratio))
		z = M_PI_2;
	else
		z = acos(vector.y / ratio);
	x = acos(ratio);
	mz = rotation_z(z);
	mx = rotation_x(x);
	return (multiply_matrix(mz, mx));
}

static int	set_plane_transformation(t_shape *obj)
{
	t_matrix	translat;
	t_matrix	rotation;
	t_matrix	transform;

	translat = translation(
			obj->plane.coord.x,
			obj->plane.coord.y,
			obj->plane.coord.z);
	rotation = get_rotation_matrix(obj->plane.vector);
	transform = multiply_matrix(translat, rotation);
	set_transform(obj, transform);
	return (0);
}

t_plane	init_create_plane(char **tokens)
{
	t_plane	pl;

	pl.coord = (t_point)(create_parameter(tokens[1], create_point));
	pl.vector = (t_vector)(create_parameter(tokens[2], create_vector));
	pl.color = create_parameter_color(tokens[3]);
	return (pl);
}

void	create_plane_node(char **tokens, t_scene *scene)
{
	t_shape	*shape;

	shape = create_plane();
	shape = ft_calloc(1, sizeof(t_shape));
	shape->plane = init_create_plane(tokens);
	shape->type = PLANE;
	shape->material.specular = 0.2;
	set_color_material(tokens[3], shape);
	set_plane_transformation(shape);
	ft_lstadd_front(&scene->shapes, ft_lstnew(shape));
	ft_free_array(tokens);
}

int	check_id_pl(char **tokens)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg(ERROR_MANY_ARGC_PL), ft_free_array(tokens), ERROR);
	else if (check_coordinates(tokens[1]))
		return (error_msg(ERROR_COOR_PL), ft_free_array(tokens), ERROR);
	else if (check_orientation(tokens[2]))
		return (ft_free_array(tokens), ERROR);
	if (check_color(tokens[3]))
		return (ft_free_array(tokens), ERROR);
	ft_free_array(tokens);
	return (OK);
}
