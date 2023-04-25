#include "minirt.h"

static t_matrix	create_orientation(t_vector left, t_vector true_up, t_vector to)
{
	t_matrix	orientation;

	orientation = create_identity_matrix();
	orientation.matrix[0][0] = left.x;
	orientation.matrix[0][1] = left.y;
	orientation.matrix[0][2] = left.z;
	orientation.matrix[1][0] = true_up.x;
	orientation.matrix[1][1] = true_up.y;
	orientation.matrix[1][2] = true_up.z;
	orientation.matrix[2][0] = -to.x;
	orientation.matrix[2][1] = -to.y;
	orientation.matrix[2][2] = -to.z;
	return (orientation);
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

t_matrix	view_transformation(t_point from, t_point to, t_vector up)
{
	t_vector	left;
	t_vector	normalized_up;
	t_vector	true_up;

	normalized_up = normalize(up);
	left = cross_product(to, normalized_up);
	true_up = cross_product(left, to);
	return (create_transformation(left, true_up, to, from));
}
