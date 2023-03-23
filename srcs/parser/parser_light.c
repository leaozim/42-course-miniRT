#include "minirt.h"

t_light	*create_light(char **tokens, t_light *light)
{
	light->coord = (t_point)(create_parameter(tokens[1], create_point));
	light->brightness = ft_atof(tokens[2]);
	return (light);
}

void	create_light_node(char **tokens, t_scene *scene)
{
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	light = create_light(tokens, light);
	ft_lstadd_back(&scene->lights, ft_lstnew(light));
	ft_free_array(tokens);
}

int check_id_l(char **tokens)
{

	if (ft_array_size(tokens) != 3)
		return (error_msg("To many or few arguments for Light!"), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg("Light orientation are invalid!"), ERROR);
	if (ft_isrange(ft_atof(tokens[2]), 0, 1))
		return (error_msg("Invalid brightness"), ERROR);
	ft_free_array(tokens);
	return (OK);
}
