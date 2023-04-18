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

void	test_camera(void)
{
	RUN_TEST(test_create_cam);
	RUN_TEST(test_pixel_size_horizontal_cam);
	RUN_TEST(test_pixel_size_vertical_cam);
	RUN_TEST(test_ray_center_canvas);
	RUN_TEST(test_ray_corner_canvas);
	RUN_TEST(test_ray_transformed);
}