#include "minirt.h"

t_cam	set_camera_transform(t_cam camera, t_matrix transform)
{
	camera.transform = transform;
	camera.inverse = inverse_matrix(transform);
	return (camera);
}