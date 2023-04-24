#include "minirt.h"

void	set_shape_material(t_shape *shape, t_scene *s)
{
	if (!s->ambient)
		return (error_msg("SHAPE MISSING INFO"), exit(0));
	shape->material.ambient = \
	multiply_color_scalar(s->ambient->color, s->ambient->ratio);
}

void	set_orientation_vector(t_vector vector, t_shape *shape)
{
	shape->orientation = vector;
}

void	set_color_material(t_color color, t_shape *shape)
{
	shape->material.color = color;
}
