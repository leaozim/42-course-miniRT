#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_scene		scene;
	t_world		*world;
	t_cam		camera;
	t_canvas	canvas;

	if (check_argc(argc) || check_file(argv[1]) == ERROR)
		return (EXIT_FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	read_file(argv[1], &scene);
	world = setup_world(&scene);
	camera = setup_camera(&scene);
	canvas = render(camera, world);
	handle_hooks(&canvas);
	mlx_loop(canvas.mlx);
	destroy_minirt(&scene);
	return (0);
}
