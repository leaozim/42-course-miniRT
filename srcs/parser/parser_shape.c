#include "minirt.h"

void	set_shape_material(t_shape *shape, t_scene *s)
{
	if (!s->ambient)
		return (error_msg("SHAPE MISSING INFO"));
	shape->material.ambient = \
	multiply_color_scalar(s->ambient->color, s->ambient->ratio);
}
