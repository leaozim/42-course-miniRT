#include "minirt.h"

void	handle_hooks(t_canvas *c)
{
	mlx_hook(c->window, KEY_PRESS, 1L << 0, &keyboard_events, c);
	mlx_hook(c->window, DESTROY_NOTIFY, NO_EVENT_MASK, &close_window, c);
}