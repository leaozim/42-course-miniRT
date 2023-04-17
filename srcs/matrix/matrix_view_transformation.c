#include "minirt.h"

static t_matrix	create_orientation(
	t_vector left, t_vector true_up, t_vector to)
{
	double	orientation[MTRX_MAX][MTRX_MAX] = {
	{left.x, left.y, left.z, 0},
	{true_up.x, true_up.y, true_up.z, 0},
	{-to.x, -to.y, -to.z, 0},
	{0, 0, 0, 1}
	};
	return (create_matrix(orientation, MTRX_MAX));
}

static t_matrix	create_transformation(
	t_vector left, t_vector true_up, t_vector to, t_point from)
{
	t_matrix	orientation;
	t_matrix	view_transformation;
	t_matrix	translated;

	orientation = create_orientation(left, true_up, to);
	translated = translation(-from.x, -from.y, -from.z);
	view_transformation = multiply_matrix(orientation, translated);
	return (view_transformation);
}

t_matrix	view_transformation(t_point from,  t_point to, t_vector up)
{
	t_vector	left;
	t_vector	normalized_up;
	t_vector	true_up;

	normalized_up = normalize(up);
	left = cross_product(to, normalized_up);
	true_up	= cross_product(left, to);
	return (create_transformation(left, true_up, to, from));
}