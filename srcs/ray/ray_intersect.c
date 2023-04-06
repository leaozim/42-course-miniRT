#include "minirt.h"

t_intersection	*create_intersection(double t, t_shape *shapes)
{
	t_intersection	*intersect;

	intersect = ft_calloc(1, sizeof(t_intersection));
	intersect->shapes = shapes;
	intersect->t = t;
	return (intersect);
}

void	ft_lsadd_sorted(t_intersections **head, t_intersections *new_node)
{
	t_intersection	*intersect;
	t_intersections	*aux;
	t_intersection	*aux_next;
	t_intersection	*intersect_head;

	intersect = (t_intersection *)new_node->content;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	intersect_head = (t_intersection *)(*head)->content;
	if (intersect->t < intersect_head->t)
	{
		new_node->next = *head;
		*head = new_node;
	}
	aux = (*head);
	if ((*head)->next != NULL)
		aux_next = (t_intersection *)(*head)->next->content;
	while (aux->next && aux_next->t <= intersect->t)
		aux =  aux->next;
	new_node->next = aux->next;
	aux->next = new_node;
}

t_xs	intersect_sphere(t_shape *sphere, t_ray ray, t_intersections **intersect)
{
	t_tuple		sphere_to_ray;
	t_bhaskara	bhask;
	t_xs		xs;

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
	
	ft_lsadd_sorted(intersect, ft_lstnew(create_intersection(xs.t1, sphere)));
	if (!is_equal_double(xs.t1, xs.t2))	
		ft_lsadd_sorted(intersect, ft_lstnew(create_intersection(xs.t2, sphere)));
	return (xs);
}
