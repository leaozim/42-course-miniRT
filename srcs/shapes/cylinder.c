#include <minirt.h>

t_shape	*create_cylinder(void)
{
	t_shape	*cylinder;

	cylinder = create_shape();
	if (!cylinder)
		return (NULL);
	cylinder->type = CYLINDER;
	cylinder->cylinder.closed = TRUE;
	cylinder->cylinder.diameter = 1.0;
	cylinder->cylinder.max = INFINITY;
	cylinder->cylinder.min = -INFINITY;
	return (cylinder);
}

void	intersect_cylinder(t_shape *cly, t_ray ray, t_intersections **intersec)
{
	t_bhaskara	bhask;
	t_xs		xs;

	bhask.a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	bhask.b = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z * ray.direction.z; 
	bhask.c = (pow(ray.origin.x, 2) + pow(ray.origin.z, 2)) - 1;
	bhask.delta = (bhask.b * bhask.b) - (4 * bhask.a * bhask.c);
	if (bhask.delta < 0 || is_equal_double(bhask.a, 0.0))
		return ;
	xs.t1 = (-bhask.b - sqrt(bhask.delta)) / (2 * bhask.a);
	xs.t2 = (-bhask.b + sqrt(bhask.delta)) / (2 * bhask.a);
	add_sorted(intersec, ft_lstnew(create_intersection(xs.t1, cly)));
	if (!is_equal_double(xs.t1, xs.t2))
		add_sorted(intersec, ft_lstnew(create_intersection(xs.t2, cly)));
}
