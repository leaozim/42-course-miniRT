#include "minirt.h"

t_tuple	create_parameter(char *tokens, t_tuple (*f)(double, double, double))
{
	char	**parameter;
	double	x;
	double	y;
	double	z;

	parameter = ft_split(tokens, ',');
	x = ft_atof(parameter[0]);
	y = ft_atof(parameter[1]);
	z = ft_atof(parameter[2]);
	ft_free_array(parameter);
	return (f(x, y, z));
}

t_color	create_parameter_color(char *tokens)
{
	char	**parameter;
	double	r;
	double	g;
	double	b;

	parameter = ft_split(tokens, ',');
	r = ft_atof(parameter[0]);
	g = ft_atof(parameter[1]);
	b = ft_atof(parameter[2]);
	ft_free_array(parameter);
	return (set_color(r, g, b));
}
