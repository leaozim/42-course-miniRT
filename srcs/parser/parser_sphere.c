#include "minirt.h"

int	check_id_sp(char **tokens, t_scene *scene)
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
