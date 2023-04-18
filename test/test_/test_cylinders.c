# include "../h_test.h"

void	test_ray_misses_cylinder(void)
{
	// t_shape		*cyl;
	// t_vector	direction1, direction2, direction3;
	// t_point		origin1, origin2, origin3;
	// t_ray		ray1, ray2, ray3;
	// t_intersections	*list = NULL;

	// cyl = create_cylinder();
	// origin1 = create_point(1, 0, 0);
	// origin2 = create_point(0, 0, 0);
	// origin3 = create_point(0, 0, -5);
	// direction1 = normalize(create_vector(0, 1, 0));
	// direction2 = normalize(create_vector(0, 1, 0));
	// direction3 = normalize(create_vector(1, 1, 1));
	// ray1 = create_ray(origin1, direction1);
	// ray2 = create_ray(origin2, direction2);
	// ray3 = create_ray(origin3, direction3);
	// intersect_cylinder(cyl,ray1, &list);
	// intersect_cylinder(cyl, ray2, &list);
	// intersect_cylinder(cyl, ray3, &list);
	// TEST_ASSERT_NULL(list);
	// TEST_ASSERT_EQUAL(0, intersection_list_size(list));
	// destroy_shape(cyl);
	// ft_lstclear(&list, free);
	TEST_ASSERT_EQUAL_INT(1, 2);
}

void test_ray_strikes_cylinder(void)
{
	// t_shape		*cyl;
	// t_vector	direction1, direction2, direction3;
	// t_point		origin1, origin2, origin3;
	// t_ray		ray1, ray2, ray3;
	// t_intersections	*list = NULL;
	// t_intersection	*aux;

	// cyl = create_cylinder();
	// origin1 = create_point(1, 0, -5);
	// origin2 = create_point(0, 0, 0);
	// origin3 = create_point(0.5, 0, -5);
	// direction1 = normalize(create_vector(0, 0, 1));
	// direction2 = normalize(create_vector(0, 0, 0));
	// direction3 = normalize(create_vector(1, 1, 1));
	// ray1 = create_ray(origin1, direction1);
	// ray2 = create_ray(origin2, direction2);
	// ray3 = create_ray(origin3, direction3);
	// intersect_cylinder(cyl,ray1, &list);
	// intersect_cylinder(cyl, ray2, &list);
	// intersect_cylinder(cyl, ray3, &list);
	// aux = (t_intersection *)list->content;
	// TEST_ASSERT_EQUAL_INT(CYLINDER, aux->shapes->type);
	// TEST_ASSERT_NULL(list);
	// TEST_ASSERT_EQUAL_DOUBLE(4.0, aux->t);
	// aux = (t_intersection *)list->next->content;
	// TEST_ASSERT_EQUAL_DOUBLE(5.0, aux->t);
	// aux = (t_intersection *)list->next->next->content;
	// TEST_ASSERT_EQUAL_DOUBLE(6.0, aux->t);
	// aux = (t_intersection *)list->next->next->next->content;
	// TEST_ASSERT_EQUAL_DOUBLE(6.80798, aux->t);
	// aux = (t_intersection *)list->next->next->next->next->content;
	// TEST_ASSERT_EQUAL_DOUBLE(7.08872, aux->t);
	// destroy_shape(cyl);
	// ft_lstclear(&list, free);
	TEST_ASSERT_EQUAL_INT(1, 2);
}

void	test_normal_vector_cylinder(void)
{
	//  t_shape	*cyl;
	// t_vector	normal1, normal2, normal3, normal4;

	// cyl = create_cylinder();
	// normal1 = normal_at(cyl, create_point(1, 0, 0));
	// normal2 = normal_at(cyl, create_point(0, 5, -1));
	// normal3 = normal_at(cyl, create_point(0, -2, 1));
	// normal4 = normal_at(cyl, create_point(-1, 1, 0));
	// TEST_ASSERT_TRUE(is_equal_tuple(create_vector(1, 0, 0), normal1));
	// TEST_ASSERT_TRUE(is_equal_tuple(create_vector(0, 0, -1), normal2));
	// TEST_ASSERT_TRUE(is_equal_tuple(create_vector(0, 0, 1), normal3));
	// TEST_ASSERT_TRUE(is_equal_tuple(create_vector(-1, 0, 0), normal4));
	// destroy_shape(cyl);
	TEST_ASSERT_EQUAL_INT(1, 2);

}

void	test_default_minimum_and_maximum_cylinder(void)
{
	// t_shape	*cyl;

	// cyl = create_cylinder();
	// TEST_ASSERT_TRUE(is_equal_double(cyl->cylinder.min, INFINITY));
	// TEST_ASSERT_TRUE(is_equal_double(cyl->cylinder.max, -INFINITY));
	// destroy_shape(cyl);
	TEST_ASSERT_EQUAL_INT(1, 2);
}


void	test_intersecting_constrained_cylinder(void)
{
	// t_shape		*cyl;
	// t_vector	direction1, direction2, direction3, direction4, direction5, direction6;
	// t_ray		ray1, ray2, ray3, ray4, ray5, ray6;
	// t_intersections	*list = NULL;

	// cyl = create_cylinder();
	// cyl->cylinder.min = 1;
	// cyl->cylinder.max = 2;
	// cyl->cylinder.closed = FALSE;
	// direction1 = normalize(create_vector(0.1, 1,));
	// direction2 = normalize(create_vector(0, 0, 1));
	// direction3 = normalize(create_vector(0, 0, 1));
	// direction4 =normalize(create_vector(0, 0, 1));
	// direction5 = normalize(create_vector(0, 0, 1));
	// direction6 = normalize(create_vector(0, 0, 1));
	// ray1 = create_ray(create_point(0, 1.5, 0), direction1);
	// ray2 = create_ray(create_point(0, 3, -5), direction2);
	// ray3 = create_ray(create_point(0, 0, -5), direction3);
	// ray4 = create_ray(create_point(0, 2, -5), direction4);	
	// ray5 = create_ray(create_point(0, 1, -5), direction5);
	// ray6 = create_ray(create_point(0, 1.5, -2), direction6);
	// intersect_cylinder(cyl,ray1, &list);
	// intersect_cylinder(cyl, ray2, &list);
	// intersect_cylinder(cyl, ray3, &list);
	// intersect_cylinder(cyl, ray4, &list);
	// intersect_cylinder(cyl, ray5, &list);
	// intersect_cylinder(cyl, ray6, &list);
	// TEST_ASSERT_NOT_NULL(list);
	// TEST_ASSERT_EQUAL(2, intersection_list_size(list));
	// destroy_shape(cyl);
	// ft_lstclear(&list, free);
	TEST_ASSERT_EQUAL_INT(1, 2);
}
void	test_cylinders(void)
{
	RUN_TEST(test_ray_misses_cylinder);
	RUN_TEST(test_ray_strikes_cylinder);
	RUN_TEST(test_normal_vector_cylinder);
	RUN_TEST(test_default_minimum_and_maximum_cylinder);
	RUN_TEST(test_intersecting_constrained_cylinder);
}