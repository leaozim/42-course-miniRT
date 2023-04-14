#include "minirt.h"

t_comps	prepare_computation(t_intersection *i, t_ray ray)
{
	t_comps		comps;
	t_vector	vec;

	comps.t = i->t;
	comps.shape = i->shapes;
	comps.point = get_position(ray, comps.t);
	comps.eyev = neg_tuple(ray.direction);
	comps.normalv = normal_at(comps.shape, comps.point);
	if (dot_product(comps.normalv, comps.eyev) < 0)
	{
		vec = comps.normalv;
		comps.normalv = neg_tuple(comps.normalv);
	}
	vec = multiply_tupla_scalar(comps.normalv, EPSILON);
	comps.over_point = adding_tuples(comps.point, vec);
	return (comps);
}