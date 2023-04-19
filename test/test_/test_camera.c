#include "../h_test.h"

void	test_create_cam(void)
{
	t_matrix	id;
	t_cam	camera;

	id = create_identity_matrix();
	camera = init_cam(160, 120, radians(180 / 2));
	TEST_ASSERT_EQUAL(160, camera.hsize);
	TEST_ASSERT_EQUAL(120, camera.vsize);
	TEST_ASSERT_EQUAL(radians(180 / 2), camera.fov);
	TEST_ASSERT_TRUE(is_equal_matrix(id, camera.transform));
}

void	test_pixel_size_horizontal_cam(void)
{
	t_cam	camera;

	camera = init_cam(200, 125, radians(180 / 2));
	TEST_ASSERT_EQUAL_DOUBLE(0.01, camera.pixel_size);
}

void	test_pixel_size_vertical_cam(void)
{
	t_cam	camera;

	camera = init_cam(125, 200, radians(180 / 2));
	TEST_ASSERT_EQUAL_DOUBLE(0.01, camera.pixel_size);
}

void	test_ray_center_canvas(void)
{
	t_cam	camera;
	t_ray	ray;

	camera = init_cam(201, 101, radians(180 / 2));
	ray = ray_for_pixel(camera, 100, 50);
	TEST_ASSERT_TRUE(is_equal_tuple((t_point){0, 0, 0, 1}, ray.origin));
	TEST_ASSERT_TRUE(is_equal_tuple((t_vector){0, 0, -1, 0}, ray.direction));
}

void	test_ray_corner_canvas(void)
{
	t_cam	camera;
	t_ray	ray;

	camera = init_cam(201, 101, radians(180 / 2));
	ray = ray_for_pixel(camera, 0, 0);
	TEST_ASSERT_TRUE(is_equal_tuple((t_point){0, 0, 0, 1}, ray.origin));
	TEST_ASSERT_TRUE(is_equal_tuple((t_vector){0.66519, 0.33259, -0.66851, 0}, ray.direction));
}

void	test_ray_transformed(void)
{
	t_cam	camera;
	t_ray	ray;
	t_matrix	rotate_y, trans;

	camera = init_cam(201, 101, radians(180 / 2));
	rotate_y = rotation_y(radians(180 / 4));
	trans = translation(0, -2, 5);
	camera = set_camera_transform(camera, multiply_matrix(rotate_y, trans));
	ray = ray_for_pixel(camera, 100, 50);
	TEST_ASSERT_TRUE(is_equal_tuple((t_point){0, 2, -5, 1}, ray.origin));
	TEST_ASSERT_TRUE(is_equal_tuple((t_vector){sqrt(2)/2, 0, -sqrt(2)/2, 0}, ray.direction));
}

void	test_print_three_spheres(void)
{
	t_shape		*floor, *lwall, *rwall, *middle, *right, *left;
	t_matrix	aux1, aux2, aux3, aux4;
	t_world		*world;
	t_cam		camera;
	t_canvas	canvas;
	void		*win;

	floor = create_sphere();
	set_transform(floor, scaling(10, 0.01, 10));
	floor->material.color = formatted_color(floor->material.color, 1, 0.9, 0.9);
	floor->material.specular = 0;

	lwall = create_sphere();
	aux1 = translation(0, 0, 5);
	aux2 = rotation_y(-radians(180 / 4));
	aux3 = multiply_matrix(aux1, aux2);

	aux1 = rotation_x(radians(180 / 2));
	aux2 = scaling(10, 0.01, 10);
	aux4 = multiply_matrix(aux3, aux1);

	aux1 = multiply_matrix(aux4, aux2);
	set_transform(lwall, aux1);
	lwall->material.color = formatted_color(lwall->material.color, 1, 0.9, 0.9);
	lwall->material.specular = 0;

	rwall = create_sphere();
	aux1 = translation(0, 0, 5);
	aux2 = rotation_y(radians(180 / 4));
	aux3 = multiply_matrix(aux1, aux2);

	aux1 = rotation_x(radians(180 / 2));
	aux2 = scaling(10, 0.01, 10);
	aux4 = multiply_matrix(aux3, aux1);
	set_transform(rwall, multiply_matrix(aux4, aux2));
	rwall->material.color = formatted_color(rwall->material.color, 1, 0.9, 0.9);
	rwall->material.specular = 0;

	middle = create_sphere();
	set_transform(middle, translation(-0.5, 1, 0.5));
	middle->material.color = formatted_color(middle->material.color, 0.1, 1, 0.5);
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;

	right = create_sphere();
	aux1 = translation(1.5, 0.5, -0.5);
	set_transform(right, multiply_matrix(aux1, scaling(0.5, 0.5, 0.5)));
	right->material.color = formatted_color(right->material.color, 0.5, 1, 0.1);
	right->material.diffuse = 0.7;
	right->material.specular = 0.3;

	left = create_sphere();
	aux1 = translation(-1.5, 0.33, -0.75);
	set_transform(left, multiply_matrix(aux1, scaling(0.33, 0.33, 0.33)));
	left->material.color = formatted_color(left->material.color, 1, 0.8, 0.1);
	left->material.diffuse = 0.7;
	left->material.specular = 0.3;

	world = create_world();
	world->light_point = ft_lstnew(create_point_light(
		create_point(-10, 10, -10),
		create_color(1, 1, 1)));
	ft_lstadd_front(&world->shapes, ft_lstnew(floor));
	ft_lstadd_front(&world->shapes, ft_lstnew(lwall));
	ft_lstadd_front(&world->shapes, ft_lstnew(rwall));
	ft_lstadd_front(&world->shapes, ft_lstnew(middle));
	ft_lstadd_front(&world->shapes, ft_lstnew(right));
	ft_lstadd_front(&world->shapes, ft_lstnew(left));

	camera = init_cam(1280, 900, radians(180 / 3));
	camera = set_camera_transform(camera, view_transformation(
		create_point(0, 1.5, -5),
		create_point(0, 1, 0),
		create_vector(0, 1 , 0)));
	
	canvas = render(camera, world);
	win = mlx_new_window(canvas.mlx, 
	(int)round(camera.hsize),
	(int)round(camera.vsize),
	"test");
	mlx_put_image_to_window(canvas.mlx, win, canvas.image, 0, 0);
	mlx_loop(canvas.mlx);



}

void	test_camera(void)
{
	RUN_TEST(test_create_cam);
	RUN_TEST(test_pixel_size_horizontal_cam);
	RUN_TEST(test_pixel_size_vertical_cam);
	RUN_TEST(test_ray_center_canvas);
	RUN_TEST(test_ray_corner_canvas);
	RUN_TEST(test_ray_transformed);
	//RUN_TEST(test_print_three_spheres);

}