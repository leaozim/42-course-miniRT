#include "minirt.h"

t_light_pnt	*create_light(char **tokens, t_light_pnt *light_p)
{
	t_color	aux;

	light_p->position = (t_point)(create_parameter(tokens[1], create_point));
	light_p->brightness = ft_atof(tokens[2]);
	aux = create_parameter_color(tokens[3]);
	light_p->intensity = multiply_color_scalar(aux, light_p->brightness);
	return (light_p);
}

void	create_light_node(char **tokens, t_scene *scene)
{
	t_light_pnt	*light_p;
	t_point 	position;
	t_color 	intensity;

	light_p = create_point_light(position, intensity);
	light_p = create_light(tokens, light_p);
	ft_lstadd_front(&scene->lights, ft_lstnew(light_p));
	ft_free_array(tokens);
}

int	check_id_l(char **tokens, t_bool *is_duplicated)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg(ERROR_MANY_ARGC_L), ft_free_array(tokens), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg(ERROR_COOR_L), ft_free_array(tokens), ERROR);
	if (ft_isrange(ft_atof(tokens[2]), 0, 1))
		return (error_msg(ERROR_BRIGHTNESS), ft_free_array(tokens), ERROR);
	if (check_color(tokens[3]))
		return (ft_free_array(tokens), ERROR);
	ft_free_array(tokens);
	is_duplicated[LIGHT] = TRUE;
	return (OK);
}
