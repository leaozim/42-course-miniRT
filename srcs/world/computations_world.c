#include "minirt.h"

t_comps	prepare_computation(t_intersection *i, t_ray ray)
{
	t_comps		comps;
	t_vector	vec;

	comps.t = i->t;
	comps.shape = i->shapes;
	comps.point = get_position(ray, comps.t);
	comps.camera = neg_tuple(ray.direction);
	comps.normal = normal_at(comps.shape, comps.point);
	if (dot_product(comps.normal, comps.camera) < 0)
	{
		vec = comps.normal;
		comps.normal = neg_tuple(comps.normal);
	}
	vec = multiply_tupla_scalar(comps.normal, EPSILON);
	comps.over_point = adding_tuples(comps.point, vec);
	return (comps);
}