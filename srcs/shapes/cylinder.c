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

static t_bhaskara	bhaskaras_formula(t_ray ray)
{
	t_bhaskara	bhask;

	bhask.a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	bhask.b = 2 * ray.origin.x * ray.direction.x;
	bhask.b += 2 * ray.origin.z * ray.direction.z;
	bhask.c = (pow(ray.origin.x, 2) + pow(ray.origin.z, 2)) - 1;
	bhask.delta = (bhask.b * bhask.b) - (4 * bhask.a * bhask.c);
	return (bhask);
}

static t_bool	check_cap(t_ray ray, double time)
{
	double	x;
	double	z;

	x = ray.origin.x + (time * ray.direction.x);
	z = ray.origin.z + (time * ray.direction.z);
	return (((x * x) + (z * z)) <= 1);
}

static void	intersect_caps(t_shape *cyl, t_ray ray, t_intersections **intersec)
{
	double	time;

	if (cyl->cylinder.closed == FALSE
		|| is_equal_double(ray.direction.y, 0.0))
		return ;
	time = (cyl->cylinder.min - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, time))
		add_sorted(intersec, ft_lstnew(create_intersection(time, cyl)));
	time = (cyl->cylinder.max - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, time))
		add_sorted(intersec, ft_lstnew(create_intersection(time, cyl)));
}

void	intersect_cylinder(t_shape *cyl, t_ray ray, t_intersections **intersec)
{
	t_bhaskara	bhask;
	t_xs		xs;
	double		y0;
	double		y1;

	intersect_caps(cyl, ray, intersec);
	bhask = bhaskaras_formula(ray);
	if (bhask.delta < 0 || is_equal_double(bhask.a, 0.0))
		return ;
	xs.t1 = (-bhask.b - sqrt(bhask.delta)) / (2 * bhask.a);
	xs.t2 = (-bhask.b + sqrt(bhask.delta)) / (2 * bhask.a);
	y0 = ray.origin.y + (xs.t1 * ray.direction.y);
	y1 = ray.origin.y + (xs.t2 * ray.direction.y);
	if (cyl->cylinder.min < y0 && y0 < cyl->cylinder.max)
		add_sorted(intersec, ft_lstnew(create_intersection(xs.t1, cyl)));
	if (!is_equal_double(xs.t1, xs.t2))
		if (cyl->cylinder.min < y1 && y1 < cyl->cylinder.max)
			add_sorted(intersec, ft_lstnew(create_intersection(xs.t2, cyl)));
}
