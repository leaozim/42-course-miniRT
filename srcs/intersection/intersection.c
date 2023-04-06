/*#include "minirt.h"

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
	ft_lstadd_back(&list->intersection, ft_lstnew(xs));
}
*/