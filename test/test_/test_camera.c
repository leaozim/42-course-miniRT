#include "../h_test.h"

void	test_create_cam(void)
{
	t_matrix	id;
	t_cam	camera;

	id = create_identity_matrix();
	camera = init_cam(160, 120, radians(90));
	TEST_ASSERT_EQUAL(160, camera.hsize);
	TEST_ASSERT_EQUAL(120, camera.vsize);
	TEST_ASSERT_EQUAL(radians(180 / 2), camera.fov);
	TEST_ASSERT_TRUE(is_equal_matrix(id, camera.transform));
}

void	test_camera(void)
{
	RUN_TEST(test_create_cam);
}