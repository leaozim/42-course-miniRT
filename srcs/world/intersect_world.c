#include "minirt.h"

void	intersect_world(t_world *world, t_ray ray, t_intersections **intersect)
{
	t_intersections	*shapes;
	t_shape			*object;
	t_ray			transformed;

	shapes = world->shapes;
	while (shapes)
	{
		object = (t_shape *)shapes->content;
		transformed = transform(ray, object->inverse);
		if (object->type == SPHERE)
			intersect_sphere(object, transformed, intersect);
		if (object->type == PLANE)
		{
			intersect_plane(object, transformed, intersect);
		}
		if (object->type == AMBIENT)
		{
			intersect_cylinder(object, transformed, intersect);
		}
		shapes = shapes->next;
	}
}
