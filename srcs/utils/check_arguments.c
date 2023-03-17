# include "minirt.h"

int	check_argc(int argc)
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
	int	len_file;
	int fd;

	len_file = ft_strlen(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error: ", 2), perror(file), ERROR);
	if (ft_strcmp(&file[len_file - 3], ".rt") || len_file == 3) 
		return (error_msg("the scene needs to be in *.rt format"), ERROR);
	return (OK);
}
