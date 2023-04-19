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
