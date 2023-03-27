#include "minirt.h"

void	create_canvas(void *mlx_ptr, int width, int height)
{
	void *window = mlx_new_window(mlx_ptr, width, height, "miniRT");
	void *image = mlx_new_image(mlx_ptr, width, height);
	mlx_put_image_to_window(mlx_ptr, window, image, 0, 0);
	mlx_loop(mlx_ptr);
}