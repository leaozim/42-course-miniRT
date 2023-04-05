# include "../h_test.h"

void	test_create_and_querying_ray(void)
{
	t_point		orig;
	t_vector	direc;
	t_ray		r;

	orig = create_point(1,2,3);
	direc = create_vector(4, 5, 6);
	r = create_ray(orig, direc); 
	TEST_ASSERT_TRUE(is_equal_tuple(orig, r.origin));
	TEST_ASSERT_TRUE(is_equal_tuple(direc, r.direction));
}

void	test_computing_point_distance(void)
{
	t_ray	r;
	t_point	e1, e2, e3, e4;
	t_point	p1, p2, p3, p4;

	r = create_ray(create_point(2, 3, 4), create_vector(1, 0, 0));
	p1 = get_position(r, 0);
	p2 = get_position(r, 1);
	p3 = get_position(r, -1);
	p4 = get_position(r, 2.5);
	e1 = create_point(2, 3, 4);
	e2 = create_point(3, 3, 4);
	e3 = create_point(1, 3, 4);
	e4 = create_point(4.5, 3, 4);
	TEST_ASSERT_TRUE(is_equal_tuple(p1, e1));
	TEST_ASSERT_TRUE(is_equal_tuple(p2, e2));
	TEST_ASSERT_TRUE(is_equal_tuple(p3, e3));
	TEST_ASSERT_TRUE(is_equal_tuple(p4, e4));
}

void	test_ray_intersects_sphere_two_points(void)
{
	// t_ray	r;
	// t_sphere	sphere;
	// t_intersect xs;

	// r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	// sphere = create_sphere();
	// xs = intersect(sphere, r)
	// TEST_ASSERT_EQUAL(2, list_size(xs));
	// TEST_ASSERT_EQUAL_DOUBLE(4.0, xs->time);
	// TEST_ASSERT_EQUAL_DOUBLE(6.0, xs->next->time);
	TEST_ASSERT_EQUAL_DOUBLE(2.0, 1.5);

}

void	test_ray_intersects_sphere_tangent(void)
{
	// t_ray	r;
	// t_sphere	sphere;
	// t_intersect xs;

	// r = create_ray(create_point(0, 1, -5), create_vector(0, 0, 1));
	// sphere = create_sphere();
	// xs = intersect(sphere, r);
	// TEST_ASSERT_EQUAL(2, list_size(xs));
	// TEST_ASSERT_EQUAL_DOUBLE(5.0 xs->time);
	// TEST_ASSERT_EQUAL_DOUBLE(5.0, xs->next->time);
	TEST_ASSERT_EQUAL_DOUBLE(2.0, 1.5);

}

void	test_ray_misses_sphere(void)
{
	// t_ray	r;
	// t_sphere	sphere;
	// t_intersect xs;

	// r = create_ray(create_point(0, 2, -5), create_vector(0, 0, 1));
	// sphere = create_sphere();
	// xs = intersect(sphere, r);
	// TEST_ASSERT_EQUAL(0, list_size(xs));
	TEST_ASSERT_EQUAL_DOUBLE(2.0, 1.5);

}

void	test_ray_originates_inside_sphere(void)
{
	// t_ray	r;
	// t_sphere	sphere;
	// t_intersect xs;

	// r = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	// sphere = create_sphere();
	// xs = intersect(sphere, r);
	// TEST_ASSERT_EQUAL(2, list_size(xs));
	// TEST_ASSERT_EQUAL_DOUBLE(-1.0, xs->time);
	// TEST_ASSERT_EQUAL_DOUBLE(1.0, xs->next->time);
	TEST_ASSERT_EQUAL_DOUBLE(2.0, 1.5);

}

void	test_sphere_is_behind_ray(void)
{
		// t_ray	r;
	// t_sphere	sphere;
	// t_intersect xs;

	// r = create_ray(create_point(0, 0, 5), create_vector(0, 0, 1));
	// sphere = create_sphere();
	// xs = intersect(sphere, r);
	// TEST_ASSERT_EQUAL(2, list_size(xs));
	// TEST_ASSERT_EQUAL_DOUBLE(-6.0, xs->time);
	// TEST_ASSERT_EQUAL_DOUBLE(-4.0, xs->next->time);
	TEST_ASSERT_EQUAL_DOUBLE(2.0, 1.5);

}

void	test_intersection_encapsulates_t_object(void)
{
	// t_sphere	sphere;
	// t_intersect i;	

	// sphere = create_sphere();
	// i = create_intersection(sphere, r);
	// TEST_ASSERT_EQUAL_PTR(sphere, intersection->object);
	// TEST_ASSERT_EQUAL_DOUBLE(3.5, intersection->time);
	TEST_ASSERT_EQUAL_DOUBLE(2.0, 1.5);

}

// void	test_aggregating_intersections(void)
// {

// }


	
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
	RUN_TEST(test_create_and_querying_ray);
	RUN_TEST(test_computing_point_distance);
	RUN_TEST(test_ray_intersects_sphere_two_points);
	RUN_TEST(test_ray_intersects_sphere_tangent);
	RUN_TEST(test_ray_misses_sphere);
	RUN_TEST(test_ray_originates_inside_sphere);
	RUN_TEST(test_sphere_is_behind_ray);
	RUN_TEST(test_intersection_encapsulates_t_object);
	RUN_TEST(translating_ray);
	RUN_TEST(scaling_ray);
	RUN_TEST(sphere_default_transform);
	RUN_TEST(intersecting_scaled_sphere);
	RUN_TEST(intersecting_translated_sphere);
}