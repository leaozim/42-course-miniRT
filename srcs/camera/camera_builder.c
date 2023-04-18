#include "minirt.h"

t_cam	init_cam(double hsize, double vsize, double fov)
{
	t_cam	camera;

	camera.hsize = hsize;
	camera.vsize = vsize;
	camera.fov = fov;
	camera.transform = create_identity_matrix();
	return (camera);
}
