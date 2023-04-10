#include "minirt.h"

static double	check_hit_value(double hit, double t)
{
	if (t <= 0 + EPSILON)
		return (hit);
	if (hit <= t && hit > 0)
		return (hit);
	return (t);
}

t_intersection	*hit(t_intersections **list)
{
	t_intersection	*hit_intersect;
	t_intersection	*intersect_head;
	t_intersections	*aux;
	double			hit;

	intersect_head = (t_intersection *)(*list)->content;
	hit = -1;
	hit_intersect = NULL;
	aux = (*list);
	while (aux)
	{
		hit =  check_hit_value(hit, intersect_head->t);
		if (hit == intersect_head->t)
			hit_intersect = intersect_head;
		aux = aux->next;
		if (aux)
			intersect_head = (t_intersection *)(aux)->content;
	}
	if (hit_intersect->t < 0)
		return (NULL);
	return (hit_intersect);
}