#include "minirt.h"

t_cylinder	init_create_cylinder(char **tokens)
{
	t_cylinder	cy;
	double		half;

	cy.coord = (t_point)(create_parameter(tokens[1], create_point));
	cy.vector = (t_vector)(create_parameter(tokens[2], create_vector));
	cy.diameter = ft_atof(tokens[3]) / 2.0;
	cy.height = ft_atof(tokens[4]);
	half = cy.height / 2.0;
	cy.max = half;
	cy.min = -half;
	cy.color = create_parameter_color(tokens[5]);
	return (cy);
}

static t_shape	*set_cylinder_transform(t_shape *cy)
{
	t_matrix	translat;
	t_matrix	sc;
	t_matrix	final;
	t_matrix	rotate;

	translat = translation(
			cy->cylinder.coord.x,
			cy->cylinder.coord.y,
			cy->cylinder.coord.z);
	rotate = get_rotation_matrix(cy->orientation);
	sc = scaling(cy->cylinder.diameter, 1, cy->cylinder.diameter);
	final = multiply_matrix_triple(translat, rotate, sc);
	set_transform(cy, final);
	return (cy);
}

void	create_cylinder_node(char **tokens, t_scene *scene)
{
	t_shape	*shape;

	shape = create_cylinder();
	shape->cylinder = init_create_cylinder(tokens);
	set_orientation_vector(tokens[2], shape);
	set_cylinder_transform(shape);
	set_color_material(shape->cylinder.color , shape);
	ft_lstadd_front(&scene->shapes, ft_lstnew(shape));
	ft_free_array(tokens);
}

int	check_id_cy(char **tokens)
{
	if (ft_array_size(tokens) != 6)
		return (error_msg(ERROR_MANY_ARGC_CY), ft_free_array(tokens), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg(ERROR_COOR_CY), ft_free_array(tokens), ERROR);
	if (check_orientation(tokens[2]))
		return (ft_free_array(tokens), ERROR);
	if (!ft_isfloat(tokens[3]) || !ft_isfloat(tokens[4]))
		return (error_msg(ERROR_FLOAT_CY), ft_free_array(tokens), ERROR);
	if (check_color(tokens[5]))
		return (ft_free_array(tokens), ERROR);
	ft_free_array(tokens);
	return (OK);
}
