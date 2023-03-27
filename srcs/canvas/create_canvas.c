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

void	write_pixel(void *mlx_ptr, int width, int height, t_color color)
{
	t_canvas	canvas;
	int			x;
	int			y;
	int 		i;

	canvas = create_canvas(mlx_ptr);
	x = 0;
    while (x < width)
	{
		y = 0;
		while (y < height)
		{
			i = 4 * (x + y * width);
			canvas.address[i] = (char)(color.b * 255);
            canvas.address[i + 1] = (char)(color.g * 255);
            canvas.address[i + 2] = (char)(color.r * 255);
            canvas.address[i + 3] = (char)0;
            ++y;
        }
        ++x;
    }
	mlx_put_image_to_window(mlx_ptr, canvas.window, canvas.image, height, width);
    mlx_loop(mlx_ptr);
}
