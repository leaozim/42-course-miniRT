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
