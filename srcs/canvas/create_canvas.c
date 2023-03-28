#include "minirt.h"

t_canvas	create_canvas(void *mlx_ptr)
{
	t_canvas	canvas;

	canvas.window = mlx_new_window(mlx_ptr, 1280, 900, "miniRT");
	canvas.image = mlx_new_image(mlx_ptr, 1280, 900);
	canvas.address =  mlx_get_data_addr(canvas.image, &canvas.bits_per_pixel,\
		&canvas.size_line, &canvas.endianness);
	return (canvas);
}

void	write_pixel(void *mlx, int width, int height, t_color rgb, t_canvas c)
{
	int 		i;

	i = 0;
	c.address[i] = (char)(rgb.b * 255);
	c.address[i + 1] = (char)(rgb.g * 255);
	c.address[i + 2] = (char)(rgb.r * 255);
	c.address[i + 3] = (char)0;
	
	mlx_put_image_to_window(mlx, c.window, c.image, height, width);
	mlx_loop(mlx);
}
