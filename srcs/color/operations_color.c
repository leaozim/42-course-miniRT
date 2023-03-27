#include "minirt.h"

t_color	adding_color(t_color a, t_color b)
{
	t_color	new_color;

	new_color = create_color(a.r + b.r, a.g + b.g, a.b + b.b);
	return (new_color);
}

t_color	sub_color(t_color a, t_color b)
{
	t_color	new_color;

	new_color = create_color(a.r - b.r, a.g - b.g, a.b - b.b);
	return (new_color);
}

t_color	multiply_color_scalar(t_color c, double mult)
{
	t_color	new_color;

	new_color = create_color(c.r * mult, c.g * mult, c.b * mult);
	return (new_color);
}

t_color	multiply_color(t_color a, t_color b)
{
	t_color	new_color;

	new_color = create_color(a.r * b.r, a.g * b.g, a.b * b.b);
	return (new_color);
}
