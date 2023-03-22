#include "minirt.h"

int	parser_ambient(char **tokens, t_scene *scene)
{
	if (is_invalid_file_data(tokens))
		return (error_msg("File data is invalid"), ERROR);
	else if (!ft_isfloat(tokens[1]))
		return (error_msg("Parameter in ambient needs to be a Float"), ERROR);
	if (ft_isrange(scene->ambient->ratio, 0, 1))
		return (error_msg("Incorrect range of numbers"), ERROR);
	return (0);
}
