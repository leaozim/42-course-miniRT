#include "minirt.h"

static int	set_sphere_transformation(t_shape *sphere)
{
	t_matrix	transform;
	t_matrix	sc;
	t_matrix	final;

	transform = translation(
			sphere->sphere.coord.x,
			sphere->sphere.coord.y,
			sphere->sphere.coord.z);
	sc = scaling(
			sphere->sphere.diameter,
			sphere->sphere.diameter,
			sphere->sphere.diameter);
	final = multiply_matrix(transform, sc);
	set_transform(sphere, final);
	return (0);
}

static t_sphere	init_create_sphere(char **tokens)
{
	t_sphere	sp;

	sp.coord = (t_point)(create_parameter(tokens[1], create_point));
	sp.diameter = ft_atof(tokens[2]) / 2;
	sp.color = create_parameter_color(tokens[3]);
	return (sp);
}

void	create_sphere_node(char **tokens, t_scene *scene)
{
	t_shape	*shape;

	shape = create_sphere();
	shape->sphere = init_create_sphere(tokens);
	set_sphere_transformation(shape);
	set_color_material(shape->sphere.color, shape);
	ft_lstadd_front(&scene->shapes, ft_lstnew(shape));
	ft_free_array(tokens);
}
