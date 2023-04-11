#include "minirt.h"

t_canvas	create_canvas(void *mlx_ptr, int width, int height)
{
	t_canvas	canvas;

	canvas.window = mlx_new_window(mlx_ptr, width, height, "miniRT");
	canvas.image = mlx_new_image(mlx_ptr, width, height);
	canvas.address = mlx_get_data_addr(canvas.image, &canvas.bits_per_pixel, \
		&canvas.size_line, &canvas.endianness);
	return (canvas);
}

void	write_pixel(t_canvas c, int x, int y, t_color rgb)
{
	int	i;

	i = 0;
	c.address[i] = (char)(rgb.b * 255);
	c.address[i + 1] = (char)(rgb.g * 255);
	c.address[i + 2] = (char)(rgb.r * 255);
	c.address[i + 3] = (char)0;
	mlx_put_image_to_window(c.mlx, c.window, c.image, y, x);
	mlx_loop(c.mlx);
}
