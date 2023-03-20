#include "minirt.h"

int	main(int argc, char *argv[])
{
	if (check_argc(argc) || check_file(argv[1]))
		return (EXIT_FAILURE);
	if (read_file(argv[1]) == ERROR)
		return (EXIT_FAILURE);
	return (0);
}
