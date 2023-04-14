#include "minirt.h"

t_bool	get_shadowed(t_world *world, t_ray ray, double distance)
{
	t_intersections	*xs;
	t_intersection	*h;
	t_bool			shadow;

	xs = NULL;
	intersect_world(world, ray, &xs);
	h = hit(xs);
	shadow = (h && h->t < distance);
	ft_lstclear(&xs, free);
	return (shadow);
}

t_bool	is_shadowed(t_world *world, t_point point, t_light_pnt *light_p)
{
	t_tuple		aux;
	double		distance;
	t_vector	direction;
	t_ray		ray;

	aux = sub_tuples(light_p->position, point);
	distance = magnitude(aux);
	direction = normalize(aux);
	ray = create_ray(point, direction);
	return (get_shadowed(world, ray, distance));
}