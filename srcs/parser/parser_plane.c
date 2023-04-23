#include "minirt.h"

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

static t_plane	init_create_plane(char **tokens)
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
	shape->plane = init_create_plane(tokens);
	set_color_material(shape->plane.color, shape);
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
