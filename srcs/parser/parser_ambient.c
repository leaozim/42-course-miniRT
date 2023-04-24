#include "minirt.h"

void	create_ambient(char **tokens, t_scene *scene)
{
	scene->ambient = (t_ambient *)ft_calloc(1, sizeof(t_ambient));
	scene->ambient->ratio = ft_atof(tokens[1]);
	scene->ambient->color = create_parameter_color(tokens[2]);
	ft_free_array(tokens);
}
