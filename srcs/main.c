# include "../includes/minirt.h"

int	main(int argc, char *argv[])
{
	if (check_argc(argc) || check_file(argv[1]))
		return (ERROR);
	read_file(argv[1]);
	return (0);
}
 