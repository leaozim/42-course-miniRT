#include "minirt.h"

t_tuple	adding_tuples(t_tuple a, t_tuple b)
{
	t_tuple	new_tuple;

	new_tuple = create_tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
	return (new_tuple);
}

t_tuple	sub_tuples(t_tuple a, t_tuple b)
{
	t_tuple	new_tuple;

	new_tuple = create_tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
	return (new_tuple);
}

t_tuple	div_tuples(t_tuple t, double div)
{
	t_tuple	new_tuple;

	new_tuple = create_tuple(t.x / div, t.y / div, t.z / div, t.w / div);
	return (new_tuple);
}

double	magnitude(t_vector vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vector	cross_product(t_vector vec1, t_vector vec2)
{
	t_vector	new_vector;

	new_vector = create_vector(vec1.y * vec2.z - vec1.z * vec2.y, \
								vec1.z * vec2.x - vec1.x * vec2.z, \
								vec1.x * vec2.y - vec1.y * vec2.x);
	return (new_vector);
}