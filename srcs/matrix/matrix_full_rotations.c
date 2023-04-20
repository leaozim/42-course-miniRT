#include "minirt.h"

static t_matrix	rotation_xy(t_vector orientation)
{
	t_matrix	r_x;
	t_matrix	r_y;
	t_matrix	rotation;

	r_x = rotation_x(M_PI / 2);
	r_y = rotation_y(atan(orientation.x / orientation.z));
	rotation = multiply_matrix(r_y, r_x);
	return (rotation);
}

static t_matrix	rotation_xz(t_vector orientation)
{
	t_matrix	r_x;
	t_matrix	r_z;
	t_matrix	rotation;

	r_x = rotation_x(atan(orientation.z / orientation.y));
	r_z = rotation_z(atan(-orientation.x / orientation.y));
	rotation = multiply_matrix(r_z, r_x);
	return (rotation);
}

t_matrix	get_rotation_matrix(t_vector orientation)
{
	if (is_equal_vectors(create_vector(0, 1, 0), orientation))
		return (create_identity_matrix());
	else if (is_equal_vectors(create_vector(0, -1, 0), orientation))
		return (rotation_x(M_PI));
	else if (is_equal_vectors(create_vector(1, 0, 0), orientation))
		return (rotation_z(-M_PI / 2));
	else if (is_equal_vectors(create_vector(-1, 0, 0), orientation))
		return (rotation_z(M_PI / 2));
	else if (is_equal_vectors(create_vector(0, 0, 1), orientation))
		return (rotation_x(M_PI / 2));
	else if (is_equal_vectors(create_vector(0, 0, -1), orientation))
		return (rotation_x(-M_PI / 2));
	if (is_equal_double(orientation.y, 0))
		return (rotation_xy(orientation));
	else
		return (rotation_xz(orientation));
}
