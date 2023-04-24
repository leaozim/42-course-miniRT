#include "minirt.h"

t_ray	transform_ray(t_ray ray, t_matrix matrix)
{
	t_ray	new_ray;

	new_ray.origin = multiply_matrix_tuple(matrix, ray.origin);
	new_ray.direction = multiply_matrix_tuple(matrix, ray.direction);
	return (new_ray);
}

t_point	get_position(t_ray ray, double time)
{
	t_point	mult;
	t_point	position;

	mult = multiply_tupla_scalar(ray.direction, time);
	position = adding_tuples(mult, ray.origin);
	return (position);
}

t_color	shade_hit(t_world *world, t_comps comps, t_list *light_list)
{
	t_lighting	light_attr;
	t_color		aux[2];
	t_color		color;

	color = create_color(0, 0, 0);
	light_attr = init_lighting();
	free(light_attr.light_p);
	light_attr.eyev = comps.eyev;
	light_attr.normalv = comps.normalv;
	light_attr.point = comps.point;
	while (light_list)
	{
		aux[0] = color;
		light_attr.light_p = light_list->content;
		light_attr.m = comps.shape->material;
		light_attr.in_shadow = \
		is_shadowed(world, comps.point, light_list->content);
		light_attr.shape = comps.shape;
		aux[1] = create_lighting(light_attr);
		color = adding_color(aux[0], aux[1]);
		light_list = light_list->next;
	}
	return (color);
}

t_color	color_at(t_world *world, t_ray ray)
{
	t_intersections	*xs;
	t_intersection	*get_hit;
	t_comps			comps;
	t_color			color;

	xs = NULL;
	intersect_world(world, ray, &xs);
	get_hit = hit(xs);
	if (!get_hit)
	{
		ft_lstclear(&xs, free);
		return (create_color(0, 0, 0));
	}
	comps = prepare_computation(get_hit, ray);
	color = shade_hit(world, comps, world->light_point);
	ft_lstclear(&xs, free);
	return (color);
}
