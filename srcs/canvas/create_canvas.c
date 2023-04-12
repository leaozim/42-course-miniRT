#include "minirt.h"
#include <mlx.h>

t_canvas	create_canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.mlx = mlx_init();
	canvas.image = mlx_new_image(canvas.mlx, width, height);
	canvas.address = mlx_get_data_addr(canvas.image, &canvas.bits_per_pixel, \
		&canvas.size_line, &canvas.endianness);
	return (canvas);
}

void	write_pixel(t_canvas canvas, int x, int y, int color)
{
	char	*pixel;
	int		index;

	pixel = canvas.address;
	pixel += (y * canvas.size_line) + (x * (canvas.bits_per_pixel / 8));
	index = canvas.bits_per_pixel - 8;
	while (index >= 0)
	{
		if (canvas.endianness == 0)
			*pixel++ = (color >> (canvas.bits_per_pixel - 8 - index)) & 0xFF;
		else
			*pixel++ = (color >> index) & 0xFF;
		index -= 8;
	}
}
