#include "minirt.h"

t_ray	transform_ray(t_ray ray, t_matrix matrix)
{
	t_ray	new_ray;

	new_ray.origin = multiply_matrix_tuple(matrix, ray.origin);
	new_ray.direction = multiply_matrix_tuple(matrix, ray.direction);
	return (new_ray);
}
