#include "minirt.h"

t_intersection	*create_intersection(double t, t_shape *shapes)
{
	t_intersection	*intersect;

	intersect = ft_calloc(1, sizeof(t_intersection));
	intersect->shapes = shapes;
	intersect->t = t;
	return (intersect);
}

void	create_intersect_node(t_intersection *xs, t_intersection_node *list)
{
	ft_lstadd_back(&list->intersections, ft_lstnew(xs));		
}

void	create_intersect_sphere_node(t_xs *list_xs, t_intersection_node *list)
{
	ft_lstadd_back(&list->xs, ft_lstnew(list_xs));		
}

t_xs	intersect_sphere(t_sphere sphere, t_ray ray, t_intersection_node *list)
{
    t_tuple        	sphere_to_ray;
    t_bhaskara    	bhask;
    t_xs        	xs;

    (void)sphere;
    xs.count = 0;
    sphere_to_ray = sub_tuples(ray.origin, create_point(0, 0, 0));
    bhask.a = dot_product(ray.direction, ray.direction);
    bhask.b = dot_product(ray.direction, sphere_to_ray) * 2;
    bhask.c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
    bhask.delta = pow(bhask.b, 2) - (4 * bhask.a * bhask.c);
    if (bhask.delta < 0)
        return (xs);
    xs.count = 2;
    xs.t1 = ((-bhask.b - sqrt(bhask.delta)) / (2 * bhask.a));
    xs.t2 = ((-bhask.b + sqrt(bhask.delta)) / (2 * bhask.a));
	create_intersect_sphere_node(&xs, list);
    return (xs);
}
