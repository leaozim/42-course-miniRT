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
	t_ray			r;
	t_shape			*sphere;
	t_intersections	*list;
	t_intersection	*aux;


	list = NULL;
	r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	sphere = create_sphere();
	intersect_sphere(sphere, r, &list);
	aux = (t_intersection *)list->content;
	TEST_ASSERT_EQUAL(2, ft_lstsize(list));
	TEST_ASSERT_EQUAL_DOUBLE(4.0, aux->t);
	aux = (t_intersection *)list->next->content;
	TEST_ASSERT_EQUAL_DOUBLE(6.0, aux->t);
	destroy_shape(sphere);
	ft_lstclear(&list, free);
}

void	test_ray_intersects_sphere_tangent(void)
{
	t_ray				r;
	t_shape				*sphere;
	t_intersections		*list;
	t_intersection		*aux;

	list = NULL;
	r = create_ray(create_point(0, 1, -5), create_vector(0, 0, 1));
	sphere = create_sphere();
	intersect_sphere(sphere, r, &list);
	aux = (t_intersection *)list->content;
	TEST_ASSERT_EQUAL_DOUBLE(5.0, aux->t);
	destroy_shape(sphere);
	ft_lstclear(&list, free);
}

void	test_ray_misses_sphere(void)
{
	t_ray				r;
	t_shape				*sphere;
	t_intersections		*list;

	list = NULL;
	r = create_ray(create_point(0, 2, -5), create_vector(0, 0, 1));
	sphere = create_sphere();
	intersect_sphere(sphere, r, &list);
	TEST_ASSERT_EQUAL(0, ft_lstsize(list));
	destroy_shape(sphere);
	ft_lstclear(&list, free);
}

void	test_ray_originates_inside_sphere(void)
{
	t_ray				r;
	t_shape				*sphere;
	t_intersections		*list;
	t_intersection		*aux;

	list = NULL;
	r = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	sphere = create_sphere();
	intersect_sphere(sphere, r, &list);
	TEST_ASSERT_EQUAL(2, ft_lstsize(list));
	aux = (t_intersection *)list->content;
	TEST_ASSERT_EQUAL_DOUBLE(-1.0, aux->t);
	aux = (t_intersection *)list->next->content;
	TEST_ASSERT_EQUAL_DOUBLE(1.0, aux->t);
	destroy_shape(sphere);
	ft_lstclear(&list, free);
}

void	test_sphere_is_behind_ray(void)
{
	t_ray				r;
	t_shape				*sphere;
	t_intersections		*list;
	t_intersection		*aux;

	list = NULL;
	r = create_ray(create_point(0, 0, 5), create_vector(0, 0, 1));
	sphere = create_sphere();
	intersect_sphere(sphere, r, &list);
	TEST_ASSERT_EQUAL(2, ft_lstsize(list));
	aux = (t_intersection *)list->content;
	TEST_ASSERT_EQUAL_DOUBLE(-6.0, aux->t);
	aux = (t_intersection *)list->next->content;
	TEST_ASSERT_EQUAL_DOUBLE(-4.0, aux->t);
	destroy_shape(sphere);
	ft_lstclear(&list, free);
}

void	test_intersection_encapsulates_t_object(void)
{
	t_shape			*sphere;
	t_intersection	*i;

	sphere = create_sphere();
	i = create_intersection(3.5, sphere);
	TEST_ASSERT_EQUAL_INT(SPHERE, sphere->type);
	TEST_ASSERT_EQUAL_PTR (sphere, i->shapes);
	TEST_ASSERT_EQUAL_DOUBLE(3.5, i->t);
	destroy_shape(sphere);
	free(i);
}

void	intersect_sets_object_intersection(void)
{
	t_ray				r;
	t_shape				*sphere;
	t_intersections		*list;
	t_intersection		*aux;

	list = NULL;
	r = create_ray(create_point(0, 0, 5), create_vector(0, 0, 1));
	sphere = create_sphere();
	intersect_sphere(sphere, r, &list);
	aux = (t_intersection *)list->next->content;
	TEST_ASSERT_EQUAL_DOUBLE(SPHERE, aux->shapes->type);
	destroy_shape(sphere);
	ft_lstclear(&list, free);
}

void	test_aggregating_intersections(void)
{
	t_shape				*sphere;
	t_intersections		*list;
	t_intersection		*aux;

	list = NULL;
	sphere = create_sphere();
	add_sorted(&list, ft_lstnew(create_intersection(1, sphere)));
	add_sorted(&list, ft_lstnew(create_intersection(-12, sphere)));
	add_sorted(&list, ft_lstnew(create_intersection(-1, sphere)));
	add_sorted(&list, ft_lstnew(create_intersection(42, sphere)));
	TEST_ASSERT_EQUAL(4, ft_lstsize(list));
	aux = (t_intersection *)list->content;
	TEST_ASSERT_EQUAL_DOUBLE(-12, aux->t);
	aux = (t_intersection *)list->next->content;
	TEST_ASSERT_EQUAL_DOUBLE(-1, aux->t);
	aux = (t_intersection *)list->next->next->content;
	TEST_ASSERT_EQUAL_DOUBLE(1, aux->t);
	aux = (t_intersection *)list->next->next->next->content;
	TEST_ASSERT_EQUAL_DOUBLE(42, aux->t);
	destroy_shape(sphere);
	ft_lstclear(&list, free);
}
	
void	translating_ray(void)
{
	t_point		point;
	t_vector	vec;
	t_matrix	m;
	t_ray		ray;
	t_ray		r_transform;

	point = create_point(1, 2, 3);
	vec = create_vector(0, 1, 0);
	ray = create_ray(point, vec);
	m =	translation(3, 4, 5);
	r_transform = transform_ray(ray, m);
	TEST_ASSERT_TRUE(is_equal_tuple( r_transform.origin, create_point(4, 6, 8)));
	TEST_ASSERT_TRUE(is_equal_tuple( r_transform.direction, create_vector(0, 1, 0)));
}

void	scaling_ray(void)
{
	t_point		point;
	t_vector	vec;
	t_matrix	m;
	t_ray		ray;
	t_ray		r_transform;


	point = create_point(1, 2, 3);
	vec = create_vector(0, 1, 0);
	ray = create_ray(point, vec);
	m =	scaling(2, 3, 4);
	r_transform = transform_ray(ray, m);
	TEST_ASSERT_TRUE(is_equal_tuple(r_transform.origin, create_point(2, 6, 12)));
	TEST_ASSERT_TRUE(is_equal_tuple(r_transform.direction, create_vector(0, 3, 0)));
}

void	sphere_default_transform(void)
{
	t_shape		*sphere;
	t_matrix	transform;

	sphere = create_sphere();
	transform = translation(2, 3, 4);
	set_transform(sphere, transform);
	TEST_ASSERT_TRUE(is_equal_matrix(transform, sphere->transform));
	destroy_shape(sphere);
}

void	intersecting_scaled_sphere(void)
{
	t_point			point;
	t_vector		vec;
	t_shape			*sphere;
	t_intersections	*list;
	t_ray			ray, transformed;
	t_intersection	*aux;

	list = NULL;
	point = create_point(0, 0, -5);
	vec = create_vector(0, 0, 1);
	ray = create_ray(point, vec);
	sphere = create_sphere();
	set_transform(sphere, scaling(2, 2, 2));
	transformed = transform(ray, inverse_matrix(sphere->transform));
	intersect_sphere(sphere, transformed, &list);
	aux = (t_intersection *)list->content;
	TEST_ASSERT_EQUAL_DOUBLE(3.0, aux->t);
	aux = (t_intersection *)list->next->content;
	TEST_ASSERT_EQUAL_DOUBLE(7.0, aux->t);
	destroy_shape(sphere);
	ft_lstclear(&list, free);
}

void	 intersecting_translated_sphere(void)
{
	t_shape			*sphere;
	t_intersections	*list;
	t_ray			ray, transformed;

	list = NULL;
	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	sphere =  create_sphere();
	set_transform(sphere, translation(5, 0, 0));
	transformed = transform(ray, sphere->transform);
	intersect_sphere(sphere, transformed, &list);
	TEST_ASSERT_NULL(list);
	destroy_shape(sphere);
	ft_lstclear(&list, free);
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
	RUN_TEST(intersect_sets_object_intersection);
	RUN_TEST(test_aggregating_intersections);
	RUN_TEST(translating_ray);
	RUN_TEST(scaling_ray);
	RUN_TEST(sphere_default_transform);
	RUN_TEST(intersecting_scaled_sphere);
	RUN_TEST(intersecting_translated_sphere);
}