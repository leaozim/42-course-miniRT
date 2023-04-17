#include "minirt.h"

void	destroy_world(t_world *w)
{
	ft_lstclear(&w->shapes, free);
	ft_lstclear(&w->light_point, free);
	free(w);
}
