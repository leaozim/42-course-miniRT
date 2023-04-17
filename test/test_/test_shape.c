# include "../h_test.h"

void test_default_transform(void)
{
	t_shape		*s;
	t_matrix	identity;

	s = create_shape();
	identity = create_identity_matrix();
	TEST_ASSERT_TRUE(is_equal_matrix(s->transform, identity));
	destroy_shape(s);
}

void	test_assign_transform(void)
{
	t_shape		*s;
	t_matrix	translated;

	s = create_shape();
	translated = translation(2, 3, 4);
	set_transform(s, translated);
	TEST_ASSERT_TRUE(is_equal_matrix(s->transform, translated));
	destroy_shape(s);
}

void	test_the_default_material(void)
{
	t_shape		*s;

	s = create_shape();
	TEST_ASSERT_EQUAL_DOUBLE(0.1, s->material.ambient.r);
	TEST_ASSERT_EQUAL_DOUBLE(0.1, s->material.ambient.g);
	TEST_ASSERT_EQUAL_DOUBLE(0.1, s->material.ambient.b);
	TEST_ASSERT_EQUAL_DOUBLE(0.9, s->material.diffuse);
	TEST_ASSERT_EQUAL_DOUBLE(0.9, s->material.specular);
	TEST_ASSERT_EQUAL_DOUBLE(200.0, s->material.shininess);
	destroy_shape(s);
}

void	teste_assigning_a_material(void)
{
	t_shape		*s;

	s = create_shape();
	s->material.ambient = create_color(1, 1, 1);
	TEST_ASSERT_EQUAL_DOUBLE(1, s->material.ambient.r);
	TEST_ASSERT_EQUAL_DOUBLE(1, s->material.ambient.g);
	TEST_ASSERT_EQUAL_DOUBLE(1, s->material.ambient.b);
	TEST_ASSERT_EQUAL_DOUBLE(0.9, s->material.diffuse);
	TEST_ASSERT_EQUAL_DOUBLE(0.9, s->material.specular);
	TEST_ASSERT_EQUAL_DOUBLE(200.0, s->material.shininess);
	destroy_shape(s);

}

void	test_the_normal_plane_is_constant_everywhere(void)
{
	t_shape		*plane;
	t_vector	n1, n2, n3;

	plane = create_plane();
	n1 = normal_at(plane, create_point(0, 0, 0));
	n2 = normal_at(plane, create_point(10, 0, -10));
	n3 = normal_at(plane, create_point(-5, 0, 150));
	TEST_ASSERT_TRUE(is_equal_tuple(create_vector(0, 1, 0), n1));
	TEST_ASSERT_TRUE(is_equal_tuple(create_vector(0, 1, 0), n2));
	TEST_ASSERT_TRUE(is_equal_tuple(create_vector(0, 1, 0), n3));
	destroy_shape(plane);
}

// ​ ​Scenario​: Intersecting a scaled shape with a ray
// ​ ​Given​r ← ray(point(0, 0, -5), vector(0, 0, 1))
// ​ ​And​s ← test_shape()
// ​ ​When​set_transform(s, scaling(2, 2, 2))
// ​ ​And​xs ← intersect(s, r)
// ​ ​Then​s.saved_ray.origin = point(0, 0, -2.5)
// ​ ​And​s.saved_ray.direction = vector(0, 0, 0.5)

// void	test_intersecting_a_scaled_shape_with_a_ray(void)
// {
// 	t_ray 			ray;
// 	t_shape 		*s;
// 	t_intersections *list;

// 	list = NULL;
// 	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
// 	s = create_sphere();
// 	intersect_sphere();
// }


void	test_intersect_with_ray_parallel_to_the_plane(void)
{

	t_intersections	*list;
	t_shape			*plane;
	t_ray			ray;

	plane = create_plane();
	ray = create_ray(create_point(0, 10, 0), create_vector(0, 0, 1));
	list = NULL;
	intersect_plane(plane, ray, &list);
	TEST_ASSERT_NULL(list);
	destroy_shape(plane);
	ft_lstclear(&list, NULL);
}


void	test_intersect_with_a_conplanar_ray(void)
{
	t_intersections	*list;
	t_shape			*plane;
	t_ray			ray;

	plane = create_plane();
	ray = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	list = NULL;
	intersect_plane(plane, ray, &list);
	TEST_ASSERT_NULL(list);
	destroy_shape(plane);
	ft_lstclear(&list, NULL);
}

void	test_ray_intersecting_a_plane_from_above(void)
{
	t_intersections	*list;
	t_intersection	*aux;
	t_shape			*plane;
	t_ray			ray;

	plane = create_plane();
	ray = create_ray(create_point(0, 1, 0), create_vector(0, -1, 0));
	list = NULL;
	intersect_plane(plane, ray, &list);
	aux = (t_intersection *)list->content;
	TEST_ASSERT_EQUAL_DOUBLE(1.0, aux->t);
	TEST_ASSERT_EQUAL_INT(PLANE, aux->shapes->type);
	TEST_ASSERT_EQUAL_INT(1, ft_lstsize(list));
	destroy_shape(plane);
	ft_lstclear(&list, free);
}


void	test_ray_intersecting_a_plane_from_below(void)
{
	t_intersections	*list;
	t_intersection	*aux;
	t_shape			*plane;
	t_ray			ray;

	plane = create_plane();
	ray = create_ray(create_point(0, -1, 0), create_vector(0, 1, 0));
	list = NULL;
	intersect_plane(plane, ray, &list);
	aux = (t_intersection *)list->content;
	TEST_ASSERT_EQUAL_DOUBLE(1.0, aux->t);
	TEST_ASSERT_EQUAL_INT(PLANE, aux->shapes->type);
	TEST_ASSERT_EQUAL_INT(1, ft_lstsize(list));
	destroy_shape(plane);
	ft_lstclear(&list, free);
}

void test_shape(void)
{
	RUN_TEST(test_default_transform);
	RUN_TEST(test_assign_transform);
	RUN_TEST(test_the_default_material);
	RUN_TEST(teste_assigning_a_material);
	RUN_TEST(test_the_normal_plane_is_constant_everywhere);
	RUN_TEST(test_intersect_with_a_conplanar_ray);
	RUN_TEST(test_ray_intersecting_a_plane_from_above);
	RUN_TEST(test_ray_intersecting_a_plane_from_below);

	// RUN_TEST(test_default_transform);

	// RUN_TEST(test_default_transform);

	// RUN_TEST(test_default_transform);

	// RUN_TEST(test_default_transform);

	// RUN_TEST(test_default_transform);

}
