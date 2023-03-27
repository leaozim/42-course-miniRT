#include "minirt.h"

void	print_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_scene	scene;
	t_mlx	canvas;

	if (check_argc(argc) || check_file(argv[1]) == ERROR)
		return (EXIT_FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	read_file(argv[1], &scene);
	canvas.mlx = mlx_init();
	write_pixel(canvas.mlx, 500, 100, scene.ambient->color);
	destroy_minirt(&scene);	
	return (0);
}
