#include "minirt.h"

// int	set_shape_linked_list_node(t_shape *shape)
// {
// 	t_list	*node;


// 	return (0);
// }

t_sphere	create_sphere(char **tokens,  t_shape *shape)
{
	t_point	coord;
	double	diameter;
	t_color	color;

	(void)shape;
	coord = (t_point)(create_parameter(tokens[1], create_point));
	diameter = ft_atof(tokens[2]);
	color = (t_color)(create_parameter(tokens[3], set_color));
	return ((t_sphere){coord, diameter, color});
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


	
	return (OK);
}


void	create_sphere_node(char **tokens, t_list *shapes)
{
	t_shape *shape;

	shape = ft_calloc(1, sizeof(t_shape));
	shape->sphere = create_sphere(tokens, shape);
	shape->type = SPHERE;
	// set_shape_linked_list_node(shape);
	ft_lstadd_front((void *)shape, shapes);
	printf("%lf\n", shape->sphere.color.r * 255);
	printf("%f\n", shape->sphere.color.g * 255);
	printf("%lf\n", shape->sphere.diameter);
}