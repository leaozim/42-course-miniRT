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

void	print_matrix(t_matrix m)
{
	size_t	i, j;

	for (i = 0; i < m.size; i++)
	{
		for (j = 0; j < m.size; j++)
		{
			printf("{ %5.1f } ", m.matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}


int	main(int argc, char *argv[])
{
	t_scene		scene;
	t_world		*world;
	t_cam		camera;
	t_canvas	canvas;
	void		*win;

	(void)world;
	(void)camera;
	if (check_argc(argc) || check_file(argv[1]) == ERROR)
		return (EXIT_FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	read_file(argv[1], &scene);
	world = setup_world(&scene);
	camera = setup_camera(&scene);
	canvas = render(camera, world);
	win = mlx_new_window(canvas.mlx, 1337, 800, "miniRT");
	mlx_put_image_to_window(canvas.mlx, win, canvas.image,	0, 0);
	destroy_minirt(&scene);
	mlx_loop(canvas.mlx);
	return (0);
}
