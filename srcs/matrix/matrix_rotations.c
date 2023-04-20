#include "minirt.h"

t_matrix	rotation_x(double radians)
{
	t_matrix	rotation;

	rotation = create_identity_matrix();
	rotation.matrix[1][1] = cos(radians);
	rotation.matrix[1][2] = -sin(radians);
	rotation.matrix[2][1] = sin(radians);
	rotation.matrix[2][2] = cos(radians);
	return (rotation);
}

t_matrix	rotation_y(double radians)
{
	t_matrix	rotation;

	rotation = create_identity_matrix();
	rotation.matrix[0][0] = cos(radians);
	rotation.matrix[0][2] = sin(radians);
	rotation.matrix[2][0] = -sin(radians);
	rotation.matrix[2][2] = cos(radians);
	return (rotation);
}

t_matrix	rotation_z(double radians)
{
	t_matrix	rotation;

	rotation = create_identity_matrix();
	rotation.matrix[0][0] = cos(radians);
	rotation.matrix[0][1] = -sin(radians);
	rotation.matrix[1][0] = sin(radians);
	rotation.matrix[1][1] = cos(radians);
	return (rotation);
}

t_matrix	total_rotation_matrix(t_vector vector)
{
	double		x;
	double		z;
	double		ratio;
	t_matrix	aux[2];
	t_matrix	rotate;

	ratio = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	if (is_equal_double(0.0, ratio))
		z = M_PI_2;
	else
		z = acos(vector.y / ratio);
	x = acos(ratio);
	aux[0] = rotation_z(z);
	aux[1] = rotation_x(x);
	rotate = multiply_matrix(aux[0], aux[1]);
	return (rotate);
}