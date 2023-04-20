#include "minirt.h"

void	set_shape_material(t_shape *shape, t_scene *s)
{
	if (!s->ambient)
		return (error_msg("SHAPE MISSING INFO"));
	shape->material.ambient = \
	multiply_color_scalar(s->ambient->color, s->ambient->ratio);
}

int	set_orientation_vector(char *token, t_shape *s)
{
	s->orientation = (t_vector)(create_parameter(token, create_vector));
	return (0);
}