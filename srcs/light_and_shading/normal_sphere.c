#include "minirt.h"

t_vector	normal_at(t_shape *shape, t_point world_point)
{
	t_vector	world_normal;
	t_vector	object_normal;
	t_point		object_point;
	t_matrix	inverse;
	t_matrix	transp_trans;

	inverse = inverse_matrix(shape->transform);
	transp_trans = transposed_matrix(inverse);
	object_point = multiply_matrix_tuple(inverse, world_point);
	if (shape->type == SPHERE)
		object_normal = sub_tuples(object_point, create_point(0, 0, 0));
	else if (shape->type == PLANE)
		object_normal = create_vector(0, 1, 0);
	else if (shape->type == CYLINDER)
		object_normal = create_vector(world_point.x, 0, world_point.z);
	world_normal = multiply_matrix_tuple(transp_trans, object_normal);
	world_normal.w = 0;
	world_normal = normalize(world_normal);
	return (world_normal);
}
