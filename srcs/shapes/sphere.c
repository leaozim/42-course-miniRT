#include "minirt.h"

t_shape	*create_sphere(void)
{
	t_shape	*shape;

	shape = create_shape();
	shape->type = SPHERE;
	shape->sphere.coord = create_point(0, 0, 0);
	shape->sphere.diameter = 1.0;
	shape->sphere.color = set_color(255, 182, 100);
	return (shape);
}
