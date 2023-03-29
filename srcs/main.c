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
	t_mlx		mlx;
	t_canvas	canvas;


	if (check_argc(argc) || check_file(argv[1]) == ERROR)
		return (EXIT_FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	read_file(argv[1], &scene);
	mlx.mlx = mlx_init();
	canvas = create_canvas(mlx.mlx, 1280, 900);
	write_pixel(mlx.mlx, 500, 100, scene.ambient->color, canvas);

	destroy_minirt(&scene);	
	return (0);
}
