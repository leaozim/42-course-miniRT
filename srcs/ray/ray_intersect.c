#include "minirt.h"

t_xs	intersect_sphere(t_sphere sphere, t_ray ray)
{
	t_tuple		sphere_to_ray;
	t_bhaskara	bhask;
	t_xs		xs;

	(void)sphere;
	xs.count = 0;
	sphere_to_ray = sub_tuples(ray.origin, create_point(0, 0, 0));
	bhask.a = dot_product(ray.direction, ray.direction);
	bhask.b = dot_product(ray.direction, sphere_to_ray) * 2;
	bhask.c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	bhask.delta = ((bhask.b * bhask.b) - (4 * bhask.a * bhask.c));
	if (bhask.delta < 0)
		return  (xs);
	xs.count = 2;
	xs.t1 = ((-bhask.b - sqrt(bhask.delta)) / (2 * bhask.a));
	xs.t2 = ((-bhask.b + sqrt(bhask.delta)) / (2 * bhask.a));
	// ft_lstadd_back(xs_list, ft_lstnew(&xs));
	return (xs);
}
