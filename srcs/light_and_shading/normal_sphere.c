#include "minirt.h"

static t_vector	set_normal_cylinder(t_shape *shape, t_point w_p)
{
	double	distance;

	distance = (w_p.x * w_p.x) + (w_p.z * w_p.z);
	if (distance < 1 && w_p.y >= shape->cylinder.max - EPSILON)
		return (create_vector(0, 1, 0));
	else if (distance < 1 && w_p.y <= shape->cylinder.min + EPSILON)
		return (create_vector(0, -1, 0));
	return (create_vector(w_p.x, 0, w_p.z));
}

static t_vector	set_normal_object(t_shape *shape, t_point o_p)
{
	t_vector	object_normal;

	if (shape->type == SPHERE)
		object_normal = sub_tuples(o_p, create_point(0, 0, 0));
	else if (shape->type == PLANE)
		object_normal = create_vector(0, 1, 0);
	else if (shape->type == CYLINDER)
		object_normal = set_normal_cylinder(shape, o_p);
	return (object_normal);
}

t_vector	normal_at(t_shape *shape, t_point world_point)
{
	t_vector	world_normal;
	t_vector	object_normal;
	t_point		object_point;

	object_point = multiply_matrix_tuple(shape->inverse, world_point);
	object_normal = set_normal_object(shape, object_point);
	world_normal = multiply_matrix_tuple(shape->transpose, object_normal);
	world_normal.w = 0;
	world_normal = normalize(world_normal);
	return (world_normal);
}
