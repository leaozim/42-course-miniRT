#include "minirt.h"

t_ray	set_ray(t_point origin, t_vector direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

void	set_transform(t_shape *shapes, t_matrix transform)
{
	shapes->transform = transform;
	shapes->inverse = inverse_matrix(transform);
	shapes->transpose = transposed_matrix(shapes->inverse);
}

t_ray	transform(t_ray ray, t_matrix matrix)
{
	t_ray		transformed_ray;
	t_point		origin;
	t_vector	direction;

	origin = multiply_matrix_tuple(matrix, ray.origin);
	direction = multiply_matrix_tuple(matrix, ray.direction);
	transformed_ray = set_ray(origin, direction);
	return (transformed_ray);
}
