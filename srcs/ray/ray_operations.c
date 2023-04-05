#include "minirt.h"

t_ray	transform_ray(t_ray ray, t_matrix matrix)
{
	t_ray	new_ray;

	new_ray.origin = multiply_matrix_tuple(matrix, ray.origin);
	new_ray.direction = multiply_matrix_tuple(matrix, ray.direction);
	return (new_ray);
}

t_point	get_position(t_ray r, double time)
{
	return(adding_tuples(multiply_tupla_scalar(r.direction, time), r.origin));
}