#include "minirt.h"

t_plane	create_plane(char **tokens)
{
	t_plane	pl;

	pl.coord = (t_point)(create_parameter(tokens[1], create_point));
	pl.vector = (t_vector)(create_parameter(tokens[2], create_point));
	pl.color = create_parameter_color(tokens[3]);
	return (pl);
}

void	create_plane_node(char **tokens, t_scene *scene)
{
	t_shape *plane;
	plane = ft_calloc(1, sizeof(t_shape));
	plane->plane = create_plane(tokens);
	plane->type = PLANE;
	ft_lstadd_front(&scene->shapes, ft_lstnew(plane));
	ft_free_array(tokens);

	t_shape	*current_shape;
	t_list	*shape_list;

	shape_list = scene->shapes;
	current_shape = (t_shape *)shape_list->content;
}

int check_id_p(char **tokens)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg(ERROR_MANY_ARGC_PL), ERROR);
	else if (check_coordinates(tokens[1]))
		return (error_msg(ERROR_COOR_PL), ERROR);
	else if (check_orientation(tokens[2]))
		return (ERROR);
	if (check_color(tokens[3]))
		return (error_msg(ERROR_INVALID_RGB), ERROR);
	return (OK);
}
