#include "minirt.h"

t_intersection	*hit(t_intersections *list)
{
	t_intersection	*intersect_head;
	t_intersections	*aux;

	if(!list) 
		return (NULL);
	intersect_head = (t_intersection *)list->content;
	aux = list;
	while (aux)
	{
		if (intersect_head->t - EPSILON > 0.0)
			return (intersect_head);
		aux = aux->next;
		if (aux)
			intersect_head = (t_intersection *)aux->content;
	}
	return (NULL);
}
