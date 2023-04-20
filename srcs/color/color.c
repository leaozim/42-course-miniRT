#include "minirt.h"

double	normalize_color(double color)
{
	return (color / 255.0);
}

static int	new_color(double color)
{
	int	new_color;

	new_color = (int)(color * 255);
	if (new_color > 255)
		return (255);
	if (new_color < 0)
		return (0);
	return (new_color);
}

int	merge_colors(double r, double g, double b)
{
	return (new_color(r) << 16 | new_color(g) << 8 | new_color(b));
}

t_color	create_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.mixed = merge_colors(r, g, b);
	return (color);
}

t_color	set_color(double r, double g, double b)
{
	return (create_color(normalize_color(r), normalize_color(g), \
	normalize_color(b)));
}

void	set_color_material(char *token, t_shape *shape)
{
	shape->material.color = create_parameter_color(token);
}
