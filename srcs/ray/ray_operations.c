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
	t_pos_attr	pos_attr;
	t_lighting	light_attr;
	t_color		aux[2];
	t_color		color;

	color = create_color(0, 0, 0);
	pos_attr = create_pos_attr(comps.eyev, comps.normalv, comps.over_point);
	while (light_list)
	{
		aux[0] = color;
		light_attr = set_lighting(light_list->content, pos_attr,\
		comps.shape->material);
		light_attr.light_normal = is_shadowed(world, comps.over_point,\
		light_list->content);
		light_attr.shape = comps.shape;
		aux[1] = create_lighting(light_attr);
		color = adding_color(aux[0], aux[1]);
		light_list = light_list->next;
	}
	return (color);
}
