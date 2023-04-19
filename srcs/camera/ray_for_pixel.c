#include "minirt.h"

static t_ray	_ray_for_pixel(t_cam camera, double _world_x, double _world_y)
{
	t_tuple		aux_p;
	t_point		pixel;
	t_point		origin;
	t_vector	direction;

	aux_p = create_point(_world_x, _world_y, -1);
	pixel = multiply_matrix_tuple(camera.inverse, aux_p);
	aux_p = create_point(0, 0, 0);
	origin = multiply_matrix_tuple(camera.inverse, aux_p);
	aux_p = sub_tuples(pixel, origin);
	direction = normalize(aux_p);
	return (create_ray(origin, direction));
}


t_ray	ray_for_pixel(t_cam cam, double px, double py)
{
	double xoffset;
	double yoffset;
	double world_x;
	double world_y;

	xoffset = (px + 0.5) * cam.pixel_size;
	yoffset = (py + 0.5) * cam.pixel_size;
	world_x = cam.half_width - xoffset;
	world_y = cam.half_height - yoffset;
	return(_ray_for_pixel(cam, world_x, world_y));
}