#include "minirt.h"

int	check_id_c(char **tokens)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg("To many or few arguments for camera!"), ERROR);
	if (is_invalid_file_data(tokens))
		return (error_msg("File data are invaded!"), ERROR);
	if (check_coordinates(tokens[1]))
		return (error_msg("Camera coordinates are invaded!"), ERROR);
	if (check_orientation(tokens[2]))
		return (ERROR);
	if (ft_isrange(ft_atoi(tokens[3]), 0, 180))
		return (error_msg("FOV is invalid!"), ERROR);
	return (OK);
}
