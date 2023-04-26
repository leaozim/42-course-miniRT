#include "minirt.h"

void	write_pixel_on_the_canvas(t_cam camera, t_canvas canvas, t_world *world)
{
	size_t		x;
	size_t		y;
	t_ray		ray;
	t_color		color;

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
}

t_canvas	render(t_cam camera, t_world *world)
{
	t_canvas	canvas;

	canvas = create_canvas(camera.vsize, camera.hsize);
	write_pixel_on_the_canvas(camera, canvas, world);
	canvas.window = mlx_new_window(canvas.mlx, WIDTH, HEIGHT, "miniRT");
	mlx_put_image_to_window(canvas.mlx, canvas.window, canvas.image, 0, 0);
	return (canvas);
}
