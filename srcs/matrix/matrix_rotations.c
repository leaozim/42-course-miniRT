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

t_matrix	shearing_matrix(t_shearing she)
{
	t_matrix	shearing;

	shearing = create_identity_matrix();
	shearing.matrix[0][1] = she.x_y;
	shearing.matrix[0][2] = she.x_z;
	shearing.matrix[1][0] = she.y_x;
	shearing.matrix[1][2] = she.y_z;
	shearing.matrix[2][0] = she.z_x;
	shearing.matrix[2][1] = she.z_y;
	return (shearing);
}
