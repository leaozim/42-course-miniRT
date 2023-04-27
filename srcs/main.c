#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_world		*world;
	t_canvas	canvas;
	t_scene		scene;
	t_cam		camera;

	if (check_argc(argc) || check_file(argv[1]) == ERROR)
		return (EXIT_FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	read_file(argv[1], &scene);
	world = setup_world(&scene);
	camera = setup_camera(&scene);
	canvas = render(camera, world);
	destroy_minirt(&scene, world);
	handle_hooks(&canvas);
	mlx_loop(canvas.mlx);
	return (0);
}
