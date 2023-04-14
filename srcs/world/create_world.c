#include "minirt.h"

t_world	*create_world(void)
{
	t_world	*world;

	world = (t_world *)malloc(sizeof(t_world));
	if (!world)
		return (NULL);
	world->light_point = NULL;
	world->shapes = NULL;
	return(world);
}

t_world	*default_world(void)
{
	t_world	*world;
	t_shape	*sphere1;
	t_shape	*sphere2;

	world = create_world();
	world->light_point = ft_lstnew(create_point_light(create_point(-10, 10, -10), create_color(1, 1, 1)));
	sphere1 = create_sphere();
	sphere1->material.color = create_color(0.8, 1.0, 0.6);
	sphere1->material.diffuse = 0.7;
	sphere1->material.specular = 0.2;
	ft_lstadd_back(&world->shapes, ft_lstnew(sphere1));
	sphere2 = create_sphere();
	set_transform(sphere2, scaling(0.5, 0.5, 0.5));
	ft_lstadd_back(&world->shapes, ft_lstnew(sphere2));
	return (world);
}
