#include "minirt.h"

t_sphere	create_sphere(char **tokens)
{
	t_sphere	sp;

	sp.coord = (t_point)(create_parameter(tokens[1], create_point));
	sp.diameter = ft_atof(tokens[2]);
	sp.color = create_parameter_color(tokens[3]);
	return (sp);
}

void	create_sphere_node(char **tokens, t_scene *scene)
{
	t_shape	*shape;

	shape = ft_calloc(1, sizeof(t_shape));
	shape->sphere = create_sphere(tokens);
	shape->type = SPHERE;
	ft_lstadd_back(&scene->shapes, ft_lstnew(shape));
	ft_free_array(tokens);
}

int	check_id_sp(char **tokens)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg(ERROR_MANY_ARGC_SP), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg(ERROR_ORI_SP), ERROR);
	if (!ft_isfloat(tokens[2]))
		return (error_msg(ERROR_FLOAT_SP), ERROR);
	if (check_color(tokens[3]))
		return (ERROR);
	ft_free_array(tokens);
	return (OK);
}
