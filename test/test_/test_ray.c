# include "../h_test.h"

void	test_create_and_querying_ray(void)
{
	t_point		orig;
	t_vector	direc;
	// t_ray		r;

	orig = create_point(1,2,3);
	direc = create_vector(4, 5, 6);
	// r = create_ray(orig, direc); adicionar a função aqui e retirar a linha a baixo
	t_ray r = {{2,2,3,1}, {5,6,7,0}};
	TEST_ASSERT_TRUE(is_equal_tuple(orig, r.origin));
	TEST_ASSERT_TRUE(is_equal_tuple(direc, r.direction));
}

void	test_computing_point_distance(void)
{
	// t_ray	r;
	t_point	e1, e2, e3, e4;
	t_point	p1, p2, p3, p4;

	// r = create_ray(create_point(2, 3, 4), create_vector(1, 0, 0)); // apagar da linha 28 a 31 e substituir pelas chamadas das fuções
	// p1 = get_position(r, 0);
	// p2 = get_position(r, 1);
	// p3 = get_position(r, -1);
	// p4 = get_position(r, 2.5);
	p1 = create_point(2, 3, 4);
	p2 = create_point(2, 3, 4);
	p3 = create_point(2, 3, 4);
	p4 = create_point(2, 3, 4);
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

void	test_ray_sphere(void)
{
	RUN_TEST(test_create_and_querying_ray);
	RUN_TEST(test_computing_point_distance);
	RUN_TEST(test_ray_intersects_sphere_two_points);
	RUN_TEST(test_ray_intersects_sphere_tangent);
	RUN_TEST(test_ray_misses_sphere);
	RUN_TEST(test_ray_originates_inside_sphere);
	RUN_TEST(test_sphere_is_behind_ray);
	RUN_TEST(test_intersection_encapsulates_t_object);
}