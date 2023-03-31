#include "minirt.h"

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

t_matrix	translation(double x, double y, double z)
{
	t_matrix	translation;

	translation = create_identity_matrix();
	translation.matrix[0][3] = x;
	translation.matrix[1][3] = y;
	translation.matrix[2][3] = z;
	return (translation);
}

t_matrix	scaling(double x, double y, double z)
{
	t_matrix	scaling;

	scaling = create_identity_matrix();
	scaling.matrix[0][0] = x;
	scaling.matrix[1][1] = y;
	scaling.matrix[2][2] = z;
	return (scaling);
}