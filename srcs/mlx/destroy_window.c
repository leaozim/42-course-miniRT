#include "minirt.h"

int	close_window(t_canvas *canvas)
{
	mlx_destroy_window(canvas->mlx, canvas->window);
	mlx_destroy_image(canvas->mlx, canvas->image);
	mlx_destroy_display(canvas->mlx);
	free(canvas->mlx);
	exit(0);
	return (0);
}

int	keyboard_events(int key, t_canvas *canvas)
{
	if (key == ESC)
		close_window(canvas);
	return (0);
}
