# include "../h_test.h"

/*The default world
Given light ← point_light(point(-10, 10, -10), color(1, 1, 1))
And s1 ← sphere() with:
| material.color | (0.8, 1.0, 0.6) |
| material.diffuse | 0.7 |
| material.specular | 0.2 |
And s2 ← sphere() with:
| transform | scaling(0.5, 0.5, 0.5) |
When w ← default_world()
Then w.light = light
And w contains s1
And w contains s2*/

void	test_create_world(void)
{
	t_world	*w;
	t_shape	*sphere1;
	t_shape	*sphere2;
	t_light_pnt	*light;


	w = default_world();
	sphere1 = (t_shape *)w->shapes->content;
	sphere2 = (t_shape *)w->shapes->next->content;
	light	= (t_light_pnt	*)w->light_point->content;
	TEST_ASSERT_TRUE(light);
	TEST_ASSERT_TRUE(sphere1);
	TEST_ASSERT_TRUE(sphere2);
	destroy_world(w);
}


void	test_intersect_world(void)
{
	t_world	*w;
	t_ray	r1;
	t_intersections	*list;

	list = NULL;

	w = default_world();
	r1 = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	intersect_world(w, r1, &list);
	TEST_ASSERT_EQUAL(4, ft_lstsize(list));
	TEST_ASSERT_EQUAL_DOUBLE(4, ((t_intersection *)(list->content))->t);
	TEST_ASSERT_EQUAL_DOUBLE(4.5, ((t_intersection *)(list->next->content))->t);
	TEST_ASSERT_EQUAL_DOUBLE(5.5, ((t_intersection *)(list->next->next->content))->t);
	TEST_ASSERT_EQUAL_DOUBLE(6, ((t_intersection *)(list->next->next->next->content))->t);
	ft_lstclear(&list, free);
	destroy_world(w);
}

void	test_precomputing(void)
{
	t_ray			ray;
	t_shape			*sphere;
	t_intersection	*i;
	t_comps			comps;

	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	sphere = create_sphere();
	i = create_intersection(4, sphere);
	comps = prepare_computation(i, ray);
	TEST_ASSERT_EQUAL_DOUBLE(comps.t, i->t);
	TEST_ASSERT_TRUE(is_equal_tuple((t_tuple){0, 0, -1, 1}, comps.point));
	TEST_ASSERT_TRUE(is_equal_tuple((t_tuple){0, 0, -1, 0}, comps.camera));
	TEST_ASSERT_TRUE(is_equal_tuple((t_tuple){0, 0, -1, 0}, comps.normal));
	free(i);
	destroy_shape(sphere);
}

void	test_hit_intersection_outside(void)
{
	t_ray			r1;
	t_shape			*sphere;
	t_intersection	*i;

	r1 = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	sphere = create_sphere();
	i = create_intersection(4, sphere);
	// comps ← prepare_computations(i, r);
	// comps.inside = false;
	destroy_shape(sphere);
	TEST_ASSERT_EQUAL_DOUBLE(10, 80);
	

}

void	test_hit_intersection_inside(void)
{
	t_ray			r1;
	t_shape			*sphere;
	t_intersection	*i;

	r1 = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	sphere = create_sphere();
	i = create_intersection(1, sphere);
	// comps.point = point(0, 0, 1);
	// comps.inside = true;
	// comps.normalv = create_vector(0, 0, -1)
	destroy_shape(sphere);
	TEST_ASSERT_EQUAL_DOUBLE(10, 70);	
}

void	test_world(void)
{
	RUN_TEST(test_create_world);
	RUN_TEST(test_intersect_world);
	RUN_TEST(test_precomputing);
	//RUN_TEST(test_hit_intersection_outside);
	//RUN_TEST(test_hit_intersection_inside);
}