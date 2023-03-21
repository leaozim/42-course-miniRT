#include "minirt.h"

int	check_id_a(char **tokens, t_scene *scene)
{
	if (is_invalid_file_data(tokens))
		return (error_msg("File data is invalid"), ERROR);
	scene->ambient = (t_ambient *)ft_calloc(1, sizeof(t_ambient));
	if (!ft_isfloat(tokens[1]))
		return (error_msg("Parameter needs to be a Float"), ERROR);
	scene->ambient->ratio = ft_atof(tokens[1]);
	if (ft_isrange(scene->ambient->ratio, 0, 1))
		return (error_msg("Incorrect range of numbers"), ERROR);
	check_color(tokens[2], scene);
	return (0);
}
