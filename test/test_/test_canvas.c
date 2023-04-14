/* # include "../h_test.h"

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
		color = set_color(r, g, b);
		canvas =  create_canvas(x, y);
		write_pixel(canvas, 50, 50, color.mixed);
		TEST_ASSERT_EQUAL_DOUBLE(r, color.r);
		TEST_ASSERT_EQUAL_DOUBLE(g, color.g);
		TEST_ASSERT_EQUAL_DOUBLE(b, color.b);
		i++;
	}
}

void	drawing_sphere(void)
{
	double			wall_size = 7.0;
	double			world_x = 500;
	double			world_y = 500;
	double			world_z = 10;
	int				canvas_pixels = 500;
	double			pixel_size = wall_size / canvas_pixels;
	double			half = wall_size / 2;
	t_canvas		canvas = create_canvas(canvas_pixels, canvas_pixels);
	t_shape			*sphere = create_sphere();
	t_point			origin = create_point(0, 0, -5);
	t_color			rgb = create_color(0.3, 0, 0);
	void			*win = mlx_new_window(canvas.mlx, world_x, world_y, "test");
	t_intersections	*list = NULL;
	t_point			position;
	t_ray			r;
	int				x, y;

	y = 0;
	while (y < canvas_pixels - 1)
	{
		x = 0;
		world_y = half - pixel_size * y;
		while (x < canvas_pixels - 1)
		{
			world_x = -half + pixel_size * x;
			position = create_point(world_x, world_y, world_z);
			r = create_ray(origin, normalize(sub_tuples(position, origin)));
			intersect_sphere(sphere, r, &list);
			if (hit(list))
				write_pixel(canvas, x, y, rgb.mixed);
			ft_lstclear(&list, free);
			x++;
		}
		y++;
	}
	destroy_shape(sphere);
	mlx_put_image_to_window(canvas.mlx, win, canvas.image, 0, 0);
	mlx_loop(canvas.mlx);
}

void	drawing_sphere_light_shading(void)
{
	double			wall_size = 7.0;
	double			world_x = 500;
	double			world_y = 500;
	double			world_z = 10;
	int				canvas_pixels = 500;
	double			pixel_size = wall_size / canvas_pixels;
	double			half = wall_size / 2;
	t_canvas		canvas = create_canvas(canvas_pixels, canvas_pixels);
	t_shape			*sphere = create_sphere();
	t_point			origin = create_point(0, 0, -5);
	t_color			color;
	void			*win = mlx_new_window(canvas.mlx, world_x, world_y, "test");
	t_intersections	*list = NULL;
	t_point			position;
	t_ray			r;
	int				x, y;
	t_lighting		args;

	args = init_lighting();
	args.light_p = create_point_light(create_point(-10, 10, -10), create_color(1, 1, 1));
	args.m.color = create_color(1, 0.2, 1);
	y = 0;
	while (y < canvas_pixels - 1)
	{
		x = 0;
		world_y = half - pixel_size * y;
		while (x < canvas_pixels - 1)
		{
			world_x = -half + pixel_size * x;
			position = create_point(world_x, world_y, world_z);
			r = create_ray(origin, normalize(sub_tuples(position, origin)));
			intersect_sphere(sphere, r, &list);
			if (hit(list))
			{
				args.point = get_position(r, ((t_intersection *)list->content)->t);
				args.normalv = normal_at(((t_intersection *)list->content)->shapes, args.point);
				args.eyev = neg_tuple(r.direction);
				color = create_lighting(args);
				write_pixel(canvas, x, y, color.mixed);
			}
			ft_lstclear(&list, free);
			x++;
		}
		y++;
	}
	destroy_shape(sphere);
	mlx_put_image_to_window(canvas.mlx, win, canvas.image, 0, 0);
	mlx_loop(canvas.mlx);
}

void    test_canvas(void)
{
	//RUN_TEST(test_pixel);
	// RUN_TEST(drawing_sphere);
	//RUN_TEST(drawing_sphere_light_shading);
}
*/