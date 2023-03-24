#include "minirt.h"

t_tuple adding_tuples(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	new_tupla;

	new_tupla.x = tuple1.x + tuple2.x;
	new_tupla.y = tuple1.y + tuple2.y;
	new_tupla.z = tuple1.z + tuple2.z;
	new_tupla.w = tuple1.w + tuple2.w;
	return (new_tupla);
}

t_tuple subtract_tuples(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	new_tupla;

	new_tupla.x = tuple1.x - tuple2.x;
	new_tupla.y = tuple1.y - tuple2.y;
	new_tupla.z = tuple1.z - tuple2.z;
	new_tupla.w = tuple1.w - tuple2.w;
	return (new_tupla);
}

t_tuple division_tuples(t_tuple tuple, t_tuple divider)
{
	t_tuple	new_tupla;

	new_tupla.x = tuple.x / divider.x;
	new_tupla.y = tuple.y / divider.y;
	new_tupla.z = tuple.z / divider.z;
	new_tupla.w = tuple.w / divider.w;
	return (new_tupla);
}

double magnitude(t_vector vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vector	cross_product(t_vector vec1, t_vector vec2)
{
	t_vector	new_vector;
	
	new_vector.x = vec1.y * vec2.z - vec1.z * vec2.y;
	new_vector.y = vec1.z * vec2.x - vec1.x * vec2.z;
	new_vector.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (new_vector);
}
