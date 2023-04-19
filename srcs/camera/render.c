#include "minirt.h"

t_canvas	render(t_cam camera, t_world *world)
{
	size_t		x;
	size_t		y;
	t_canvas	canvas;
	t_ray		ray;
	t_color		color;

	canvas = create_canvas(camera.vsize, camera.hsize);
	y = 0;
	while (y < (camera.vsize - 1))
	{
		x = 0;
		while (x < (camera.hsize - 1))
		{
			ray = ray_for_pixel(camera, x, y);
			color = color_at(world, ray);
			write_pixel(canvas, x, y, color.mixed);
			x++;
		}
		y++;
	}
	return (canvas);
}
