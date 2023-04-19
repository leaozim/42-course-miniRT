#include "minirt.h"

t_cam	init_cam(double hsize, double vsize, double fov)
{
	double	half_view;
	double	aspect;
	t_cam	camera;

	half_view = tan(fov / 2);
	aspect = hsize / vsize;
	camera.half_width = half_view;
	camera.half_height = half_view / aspect;
	if (aspect < 1)
	{
		camera.half_width = half_view * aspect;
		camera.half_height = half_view;
	}
	camera.pixel_size = (camera.half_width * 2) / hsize;
	camera.hsize = hsize;
	camera.vsize = vsize;
	camera.fov = fov;
	camera.transform = create_identity_matrix();
	camera.inverse = create_identity_matrix();
	return (camera);
}
