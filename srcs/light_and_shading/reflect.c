#include "minirt.h"

t_vector	reflect(t_vector in, t_vector normal)
{
	t_vector	mult;
	t_vector	result;

	mult = multiply_tupla_scalar(normal, dot_product(in, normal));
	mult = multiply_tupla_scalar(mult, 2);
	result = sub_tuples(in, mult);
	return (result);
}
