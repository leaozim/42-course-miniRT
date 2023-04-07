#include "minirt.h"

t_ray	transform_ray(t_ray ray, t_matrix matrix)
{
	t_ray	new_ray;

	new_ray.origin = multiply_matrix_tuple(matrix, ray.origin);
	new_ray.direction = multiply_matrix_tuple(matrix, ray.direction);
	return (new_ray);
}

t_point	get_position(t_ray ray, double time)
{
	t_point	mult;
	t_point	position;

	mult = multiply_tupla_scalar(ray.direction, time);
	position = adding_tuples(mult, ray.origin);
	return (position);
}