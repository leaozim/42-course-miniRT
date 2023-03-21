#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (check_argc(argc) || check_file(argv[1]))
		return (EXIT_FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	if (read_file(argv[1], &scene) == ERROR)
		return (EXIT_FAILURE);
	return (0);
}
