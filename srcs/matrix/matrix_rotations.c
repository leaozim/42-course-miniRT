#include "minirt.h"

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
