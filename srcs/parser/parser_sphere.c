#include "minirt.h"

t_sphere	create_sphere(char **tokens)
{
	t_sphere	sp;

	sp.coord = (t_point)(create_parameter(tokens[1], create_point));
	sp.diameter = ft_atof(tokens[2]);
	sp.color = (t_color)(create_parameter(tokens[3], set_color));
	return (sp);
}

void	create_sphere_node(char **tokens, t_scene *scene)
{
	t_shape *shape;
	// t_shape	*current_shape;
	// t_list	*shape_list;

	shape = ft_calloc(1, sizeof(t_shape));
	shape->sphere = create_sphere(tokens);
	shape->type = SPHERE;
	ft_lstadd_front(&scene->shapes, ft_lstnew(shape));
	ft_free_array(tokens);
	// shape_list = scene->shapes;
	// current_shape = (t_shape *)shape_list->content;
	// printf("%lf\n", current_shape->sphere.color.R * 255);
	// printf("%f\n", current_shape->sphere.color.G * 255);
	// printf("%lf\n", current_shape->sphere.diameter);
	// ft_lstclear(&scene->shapes, free);
}

int	check_id_sp(char **tokens)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg("To many or few arguments for sphere!"), ERROR);
	if (is_invalid_file_data(tokens))
		return (error_msg("File data are invaded!"), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg("Sphere orientation are invalid!"), ERROR);
	if (!ft_isfloat(tokens[2]))
		return (error_msg("Parameter for sphere needs to be a Float"), ERROR);
	if (check_color(tokens[3]))
		return (ERROR);
	ft_free_array(tokens);
	return (OK);
}
