#include "../../includes/minirt.h"

int check_argc(int argc)
{
	if (argc == 2)
		return (OK);
	if (argc < 2)
		return(error_msg("Need to add scene file!"), ERROR);
	else
		return(error_msg("Too many arguments!"), ERROR);
}

int	check_file(char *file)
{
	int len_file;

	len_file = ft_strlen(file);
	if (ft_strcmp(&file[len_file - 3], ".rt") || len_file == 3) 
		return (error_msg("the scene needs to be in *.rt format"), ERROR);
	return (OK);
}