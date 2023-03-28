# include "../h_test.h"

void    test_pixel(void)
{
    t_canvas	canvas;
    int			x, y, i;
	double		r, g, b;
	t_color		color;	

	i = 0;
	x = 800;
	y = 800;
	while (i < MAX_INTERATIONS)
    {
		r = rand_rgb();
		g = rand_rgb();
		b = rand_rgb();
		color = create_color(r, g, b);
		void	*mlx = mlx_init();
		canvas =  create_canvas(mlx, x, y);
		write_pixel(mlx, 50, 50, color, canvas);
		TEST_ASSERT_EQUAL_DOUBLE(r, color.r);
		TEST_ASSERT_EQUAL_DOUBLE(g, color.g);
		TEST_ASSERT_EQUAL_DOUBLE(b, color.b);
		i++;
	}
	
}

void    test_canvas(void)
{
	RUN_TEST(test_pixel);
}