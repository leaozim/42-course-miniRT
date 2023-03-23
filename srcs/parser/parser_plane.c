#include "minirt.h"

t_plane	create_plane(char **tokens)
{
	t_plane	pl;

	pl.coord = (t_point)(create_parameter(tokens[1], create_point));
	pl.vector = (t_vector)(create_parameter(tokens[2], create_vector));
	pl.color = create_parameter_color(tokens[3]);
	return (pl);
}

void	create_plane_node(char **tokens, t_scene *scene)
{
	t_shape *plane;
	plane = ft_calloc(1, sizeof(t_shape));
	plane->plane = create_plane(tokens);
	plane->type = PLANE;
	ft_lstadd_back(&scene->shapes, ft_lstnew(plane));
	ft_free_array(tokens);
}

int check_id_pl(char **tokens)
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
