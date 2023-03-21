
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
	free(parameter);
	return(f(x, y, z));
}
