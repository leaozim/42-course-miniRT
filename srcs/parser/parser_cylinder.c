#include "minirt.h"

t_cylinder	init_create_cylinder(char **tokens)
{
	t_cylinder	cy;

	cy.coord = (t_point)(create_parameter(tokens[1], create_point));
	cy.vector = (t_vector)(create_parameter(tokens[2], create_vector));
	cy.diameter = ft_atof(tokens[3]);
	cy.height = ft_atof(tokens[4]);
	cy.color = create_parameter_color(tokens[5]);
	return (cy);
}

void	create_cylinder_node(char **tokens, t_scene *scene)
{
	t_shape	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_shape));
	cylinder->cylinder = init_create_cylinder(tokens);
	cylinder->type = CYLINDER;
	ft_lstadd_front(&scene->shapes, ft_lstnew(cylinder));
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
