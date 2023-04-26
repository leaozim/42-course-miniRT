#include "minirt.h"

int	put_image_again(t_canvas *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
	return (0);
}

void	handle_hooks(t_canvas *c)
{
	mlx_expose_hook(c->window, put_image_again, c);
	mlx_hook(c->window, KEY_PRESS, 1L << 0, &keyboard_events, c);
	mlx_hook(c->window, DESTROY_NOTIFY, NO_EVENT_MASK, &close_window, c);
}
