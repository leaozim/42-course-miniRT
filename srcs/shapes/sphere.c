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

void	intersect_sphere(t_shape *sphere, t_ray ray, t_intersections **intersec)
{
	t_tuple		sphere_to_ray;
	t_bhaskara	bhask;
	t_xs		xs;

	sphere_to_ray = sub_tuples(ray.origin, create_point(0, 0, 0));
	bhask.a = dot_product(ray.direction, ray.direction);
	bhask.b = dot_product(ray.direction, sphere_to_ray) * 2;
	bhask.c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	bhask.delta = (bhask.b * bhask.b) - (4 * bhask.a * bhask.c);
	if (bhask.delta < 0)
		return ;
	xs.t1 = ((-bhask.b - sqrt(bhask.delta)) / (2 * bhask.a));
	xs.t2 = ((-bhask.b + sqrt(bhask.delta)) / (2 * bhask.a));
	add_sorted(intersec, ft_lstnew(create_intersection(xs.t1, sphere)));
	if (!is_equal_double(xs.t1, xs.t2))
		add_sorted(intersec, ft_lstnew(create_intersection(xs.t2, sphere)));
}
