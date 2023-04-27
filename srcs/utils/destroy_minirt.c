#include "minirt.h"

void	destroy_minirt(t_scene *scene, t_world *w)
{
	ft_lstclear(&scene->shapes, free);
	ft_lstclear(&scene->lights, free);
	free(scene->ambient);
	free(scene->camera);
	free(w);
}
