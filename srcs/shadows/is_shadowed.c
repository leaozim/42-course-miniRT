#include "minirt.h"

static	t_bool	is_true_or_false(t_list *list, double distance)
{
	t_intersection	*h;

	h = hit(list);
	if (h && ((t_intersection *)list->content)->t < distance)
		return (ft_lstclear(&list, free), TRUE);
	ft_lstclear(&list, free);
	return (FALSE);
}

t_bool	is_shadowed(t_world *world, t_point p)
{
	t_intersections	*list;
	double			distance;
	t_vector		direction;
	t_vector		v;
	t_ray			ray;

	list = NULL;
	v = sub_tuples(((t_light_pnt *)world->light_point->content)->position, p);
	distance = magnitude(v);
	direction = normalize(v);
	ray = create_ray(p, direction);
	intersect_world(world, ray, &list);
	return (is_true_or_false(list, distance));
}
