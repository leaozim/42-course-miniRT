#include "minirt.h"

int	check_id_cy(char **tokens, t_scene *scene)
{
	if (ft_array_size(tokens) != 6)
		return (error_msg("To many or few arguments for cylinder!"), ERROR);
	if (is_invalid_file_data(tokens))
		return (error_msg("File data are invaded!"), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg("Cylinder coordinates are invaded!"), ERROR);
	if (check_orientation(tokens[2]))
		return (ERROR);
	if (!ft_isfloat(tokens[3]) || !ft_isfloat(tokens[4]))
		return (error_msg("Parameter needs to be a Float"), ERROR);
	if (check_color(tokens[5]))
		return (ERROR);
	return (OK);
}
