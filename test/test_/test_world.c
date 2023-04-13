// # include "../h_test.h"

// void	creating_world(void)
// {
// //	w <- world();
// //	w contains no objects
// //	w has no light source
	
// 	TEST_ASSERT_EQUAL_DOUBLE(0, 1);
// }


// void	intersect_world(void)
// {
// 	t_ray	r1;

// 	// w ← default_world();
// 	r1 = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
// 	// xs ← intersect_world(w, r);
// 	// xs.count = 4;
// 	// xs[0].t = 4;
// 	// xs[1].t = 4.5;
// 	// xs[2].t = 5.5;
// 	// xs[3].t = 6;
// 	TEST_ASSERT_EQUAL_DOUBLE(21, 42);
// }

// void	precomputing(void)
// {
// 	t_ray			r1;
// 	t_shape			*sphere;
// 	t_intersection	*i;

// 	r1 = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
// 	sphere = create_sphere();
// 	i = create_intersection(4, sphere);
// 	// comps ← prepare_computations(i, r);
// 	// comps.t = i.t;
// 	// comps.object = i.object;
// 	// comps.point = point(0, 0, -1);
// 	// comps.eyev = vector(0, 0, -1);
// 	// comps.normalv = vector(0, 0, -1);
// 	destroy_shape(sphere);
// 	TEST_ASSERT_EQUAL_DOUBLE(13, 37);
// }

// void	hit_intersection_outside(void)
// {
// 	t_ray			r1;
// 	t_shape			*sphere;
// 	t_intersection	*i;

// 	r1 = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
// 	sphere = create_sphere();
// 	i = create_intersection(4, sphere);
// 	// comps ← prepare_computations(i, r);
// 	// comps.inside = false;
// 	destroy_shape(sphere);
// 	TEST_ASSERT_EQUAL_DOUBLE(10, 80);
	

// }

// void	hit_intersection_inside(void)
// {
// 	t_ray			r1;
// 	t_shape			*sphere;
// 	t_intersection	*i;

// 	r1 = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
// 	sphere = create_sphere();
// 	i = create_intersection(1, sphere);
// 	// comps.point = point(0, 0, 1);
// 	// comps.inside = true;
// 	// comps.normalv = create_vector(0, 0, -1)
// 	destroy_shape(sphere);
// 	TEST_ASSERT_EQUAL_DOUBLE(10, 70);	
// }

// void	test_world(void)
// {
// 	RUN_TEST(creating_world);
// 	RUN_TEST(intersect_world);
// 	RUN_TEST(precomputing);
// 	RUN_TEST(hit_intersection_outside);
// 	RUN_TEST(hit_intersection_inside);

// }