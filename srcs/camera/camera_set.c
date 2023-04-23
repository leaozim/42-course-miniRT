#include "minirt.h"

static t_cam	set_camera_transform(t_cam camera, t_matrix transform)
{
	camera.transform = transform;
	camera.inverse = inverse_matrix(transform);
	return (camera);
}

static t_cam	set_camera(t_cam cam, t_camera *camera)
{
	t_matrix	transformation;
	t_vector	aux;
	t_vector	up;

	if (is_equal_double(1, fabs(camera->vector.y)))
		up = create_vector(1, 0, 0);
	else
	{
		aux = cross_product((t_tuple){0, 1, 0, 0}, camera->vector);
		up = cross_product(camera->vector, aux);
	}
	transformation = view_transformation(camera->point_of_view, \
	camera->vector, up);
	cam = set_camera_transform(cam, transformation);
	return (cam);
}

t_cam	setup_camera(t_scene *s)
{
	t_cam	camera;

	camera = init_cam(WIDTH, HEIGHT, radians(s->camera->field_of_view));
	return (set_camera(camera, s->camera));
}
