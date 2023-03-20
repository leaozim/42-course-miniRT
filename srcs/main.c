#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (check_argc(argc) || check_file(argv[1]))
		return (ERROR);
	ft_bzero(&scene, sizeof(t_scene));
	read_file(argv[1], &scene);
	return (0);
}
