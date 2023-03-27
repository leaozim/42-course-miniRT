#include "minirt.h"

t_tuple	neg_tuple(t_tuple tuple)
{
	t_tuple	new_tuple;

	new_tuple.x = tuple.x * -1;
	new_tuple.y = tuple.y * -1;
	new_tuple.z = tuple.z * -1;
	new_tuple.w = tuple.w * -1;
	return (new_tuple);
}

t_tuple	multiply_tupla(t_tuple tuple, double multiplier)
{
	t_tuple	new_tuple;

	new_tuple.x = tuple.x * multiplier;
	new_tuple.y = tuple.y * multiplier;
	new_tuple.z = tuple.z * multiplier;
	new_tuple.w = tuple.w * multiplier;
	return (new_tuple);
}

t_vector	normalize(t_vector *vector)
{
	t_vector	new_vector;

	new_vector.x = vector->x / magnitude(vector);
	new_vector.y = vector->y / magnitude(vector);
	new_vector.z = vector->z / magnitude(vector);
	new_vector.w = vector->w / magnitude(vector);
	return (new_vector);
}

double	dot_product(t_vector vec1, t_vector vec2)
{
	return ((vec1.x * vec2.x) + \
			(vec1.y * vec2.y) + \
			(vec1.z * vec2.z) + \
			(vec1.w * vec2.w));
}
