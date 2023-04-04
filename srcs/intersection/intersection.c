#include "minirt.h"

t_intersection	*create_intersection(double t, t_shape *shapes)
{
	t_intersection	*intersect;

	intersect->shapes = shapes;
	intersect->t = t;
	return (intersect);
}

void	create_intersect_node(double t, t_shape *shapes)
{
	t_intersection	*intersect;

	intersect = ft_calloc(1, sizeof(t_intersection));
	intersect = create_intersection(t, shapes);
	ft_lstadd_back(&shapes->intersect, ft_lstnew(intersect));
}

