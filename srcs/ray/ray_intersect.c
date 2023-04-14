#include "minirt.h"

t_intersection	*create_intersection(double t, t_shape *shapes)
{
	t_intersection	*intersect;

	intersect = ft_calloc(1, sizeof(t_intersection));
	intersect->shapes = shapes;
	intersect->t = t;
	return (intersect);
}

void	add_sorted(t_intersections **head, t_intersections *new_node)
{
	t_sorted	s;

	s.intersect = (t_intersection *)new_node->content;
	if (*head == NULL)
		*head = new_node;
	else
	{
		s.intersect_head = (t_intersection *)(*head)->content;
		if (s.intersect->t < s.intersect_head->t)
		{
			new_node->next = *head;
			*head = new_node;
			return ;
		}
		s.aux = (*head);
		while (s.aux->next && ((t_intersection *)(s.aux->next->content))->t \
		<= s.intersect->t)
		{
			s.aux = s.aux->next;
			if (s.aux)
				s.intersect_head = (t_intersection *)(s.aux->content);
		}
		new_node->next = s.aux->next;
		s.aux->next = new_node;
	}
}

t_xs	intersect_sphere(t_shape *sphere, t_ray ray, t_intersections **intersec)
{
	t_tuple		sphere_to_ray;
	t_bhaskara	bhask;
	t_xs		xs;

	xs.count = 0;
	sphere_to_ray = sub_tuples(ray.origin, create_point(0, 0, 0));
	bhask.a = dot_product(ray.direction, ray.direction);
	bhask.b = dot_product(ray.direction, sphere_to_ray) * 2;
	bhask.c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	bhask.delta = (bhask.b * bhask.b) - (4 * bhask.a * bhask.c);
	if (bhask.delta < 0)
		return (xs);
	xs.count = 2;
	xs.t1 = ((-bhask.b - sqrt(bhask.delta)) / (2 * bhask.a));
	xs.t2 = ((-bhask.b + sqrt(bhask.delta)) / (2 * bhask.a));
	add_sorted(intersec, ft_lstnew(create_intersection(xs.t1, sphere)));
	if (!is_equal_double(xs.t1, xs.t2))
		add_sorted(intersec, ft_lstnew(create_intersection(xs.t2, sphere)));
	return (xs);
}
