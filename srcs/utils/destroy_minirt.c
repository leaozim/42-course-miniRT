#include "minirt.h"

void	destroy_t_shapes(void *shapes)
{
	t_shape	*scenelst;

	scenelst = (t_shape *)shapes;
	free(scenelst);
}

void	destroy_minirt(t_scene *scene)
{
	ft_lstclear(&scene->shapes, free);
}
