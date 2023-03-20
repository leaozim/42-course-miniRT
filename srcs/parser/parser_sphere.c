# include "minirt.h"

int	check_id_sp(char **tokens)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg("To many or few arguments for sphere!"), ERROR);
	if (is_invalid_file_data(tokens))
		return (error_msg("File data are invaded!"), ERROR);
	if (check_orientation(tokens[2]))
		return (error_msg("Camera orientation is invalid!"), ERROR);
	return (OK);
}