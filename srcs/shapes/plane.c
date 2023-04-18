#include <minirt.h>

t_shape	*create_plane(void)
{
	t_shape	*shape;

	shape = create_shape();
	shape->type = PLANE;
	shape->material.specular = 0.05;
	shape->plane.vector = (t_vector){0, 1, 0, 0};
	return (shape);
}

void	intersect_plane(t_shape *plane, t_ray ray, t_intersections **intersec)
{
	double	time;

	if (fabs(ray.direction.y) < EPSILON|| is_equal_double(0.0, ray.direction.y))
		return ;
	time = -ray.origin.y / ray.direction.y;
	add_sorted(intersec, ft_lstnew(create_intersection(time, plane)));
}
