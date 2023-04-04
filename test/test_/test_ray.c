# include "../h_test.h"

void	translating_ray(void)
{
	t_point		point;
	t_vector	vec;

	point = create_point(1, 2, 3);
	vec = create_vector(0, 1, 0);
	(void)point;
	(void)vec;


	// teste:
	// r ← ray(point, vec);
	// m ← translation(3, 4, 5);
	// r2 ← transform(r, m);
	
	// TEST_ASSERT_TRUE(is_equal_tuple( r2.origin, point(4, 6, 8)));
	// TEST_ASSERT_TRUE(is_equal_tuple( r2.direction, vector(0, 1, 0)));

		TEST_ASSERT_EQUAL_DOUBLE(4.2, 2.1); // remover
}

void	scaling_ray(void)
{
	t_point		point;
	t_vector	vec;
	t_matrix	m;

	point = create_point(1, 2, 3);
	vec = create_vector(0, 1, 0);
	(void)point;
	(void)vec;
	(void)m;

	// teste:
	// r ← ray(point, vec);
	m =	scaling(2, 3, 4);
	// r2 ← transform(r, m);
	
	// TEST_ASSERT_TRUE(is_equal_tuple( r2.origin, point(2, 6, 12)));
	// TEST_ASSERT_TRUE(is_equal_tuple( r2.direction, vector(0, 3, 0)));

	TEST_ASSERT_EQUAL_DOUBLE(1.3, 3.7); // remover
}

void	sphere_default_transform(void)
{
	t_scene		scene;
	t_shape		shape;
	t_sphere	*sphere;

	scene = create_sphere_test();
	sphere = &shape.sphere;
	sphere =  (t_sphere *)scene.shapes->content;
	shape.sphere = *sphere;

	// t ← translation(2, 3, 4);
	// set_transform(shape.sphere, t);
	// shape.transform = t
	TEST_ASSERT_EQUAL_DOUBLE(3.7, 7.3); // remover
}

void	intersecting_scaled_sphere(void)
{
	t_point		point;
	t_vector	vec;
	t_scene		scene;

	point = create_point(0, 0, -5);
	vec = create_vector(0, 0, 1);
	scene = create_sphere_test();
	(void)point;
	(void)vec;
	(void)scene;

	// set_transform(s, scaling(2, 2, 2));
	// xs ← intersect(s, r);
	// xs.count = 2;
	// xs[0].t = 3;
	// xs[1].t = 7
	TEST_ASSERT_EQUAL_DOUBLE(1.0, 2.0); // remover
}

void	 intersecting_translated_sphere(void)
{
	t_point		point;
	t_vector	vec;
	t_scene		scene;

	point = create_point(0, 0, -5);
	vec = create_vector(0, 0, 1);
	scene = create_sphere_test();
	(void)point;
	(void)vec;
	(void)scene;

	// set_transform(s, translation(5, 0, 0));
	// xs ← intersect(s, r)
	// xs.count = 0;
	TEST_ASSERT_EQUAL_DOUBLE(2.0, 1.0); // remover
}

void	test_ray(void)
{
	RUN_TEST(translating_ray);
	RUN_TEST(scaling_ray);
	RUN_TEST(sphere_default_transform);
	RUN_TEST(intersecting_scaled_sphere);
	RUN_TEST(intersecting_translated_sphere);
}