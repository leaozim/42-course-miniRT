#include "minirt.h"

t_world	*create_world(void)
{
	t_world	*world;

	world = (t_world *)malloc(sizeof(t_world));
	if (!world)
		return (NULL);
	world->light_point = NULL;
	world->shapes = NULL;
	return (world);
}
