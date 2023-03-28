#include "minirt.h"

void	destroy_mlx(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_image(mlx_ptr, img_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
