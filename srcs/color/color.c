#include "minirt.h"

double	normalize_color(double color)
{
	return (color / 255.0);
}

int	merge_colors(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

t_color	create_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.mixed = merge_colors((int)(r * 255), (int)(g * 255), \
	(int)(b * 255));
	return (color);
}

t_color	set_color(double r, double g, double b)
{
	return (create_color(normalize_color(r), normalize_color(g), \
	normalize_color(b)));
}
