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
	TEST_ASSERT_TRUE(is_equal_tuple((t_tuple){0, 0, -1, 0}, comps.eyev));
	TEST_ASSERT_TRUE(is_equal_tuple((t_tuple){0, 0, -1, 0}, comps.normalv));
	free(i);
	destroy_shape(sphere);
}

void	test_hit_intersection_inside(void)
{
	t_ray			ray;
	t_shape			*sphere;
	t_intersection	*i;
	t_comps			comps;

	ray = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	sphere = create_sphere();
	i = create_intersection(1, sphere);
	comps = prepare_computation(i, ray);
	TEST_ASSERT_TRUE(is_equal_tuple((t_tuple){0, 0, 1, 1}, comps.point));
	TEST_ASSERT_TRUE(is_equal_tuple((t_tuple){0, 0, -1, 0}, comps.eyev));
	TEST_ASSERT_TRUE(is_equal_tuple((t_tuple){0, 0, -1, 0}, comps.normalv));
	free(i);
	destroy_shape(sphere);
}

void	test_shading_intersection(void)
{
	t_world			*w;
	t_shape			*shape;
	t_ray			ray;
	t_intersection	*i;
	t_comps			comps;
	t_color			color;

	w = default_world();
	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	shape = (t_shape *)w->shapes->content;
	i = create_intersection(4, shape);
	comps = prepare_computation(i, ray);
	color = shade_hit(w, comps, w->light_point);
	TEST_ASSERT_TRUE(is_equal_double(0.38066, color.r));
	TEST_ASSERT_TRUE(is_equal_double(0.47583, color.g));
	TEST_ASSERT_TRUE(is_equal_double(0.2855, color.b));
	free(i);
	destroy_world(w);
}


void	test_color_ray_misses(void)
{
	t_world		*w;
	t_ray		ray;
	t_color		color;

	w = default_world();
	ray = create_ray(create_point(0, 0, -5), create_vector(0, 1, 0));
	color = color_at(w, ray);
	TEST_ASSERT_TRUE(is_equal_double(0, color.r));
	TEST_ASSERT_TRUE(is_equal_double(0, color.g));
	TEST_ASSERT_TRUE(is_equal_double(0, color.b));
	destroy_world(w);
}

void	test_color_ray_hits(void)
{
	t_world		*w;
	t_ray		ray;
	t_color		color;

	w = default_world();
	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	color = color_at(w, ray);
	TEST_ASSERT_TRUE(is_equal_double(0.38066, color.r));
	TEST_ASSERT_TRUE(is_equal_double(0.47583, color.g));
	TEST_ASSERT_TRUE(is_equal_double(0.2855, color.b));
	destroy_world(w);
}

void	test_shading_intersection_inside(void)
{
	t_world			*w;
	t_shape			*shape;
	t_ray			ray;
	t_intersection	*i;
	t_comps			comps;
	t_color			color;

	w = default_world();
	ft_lstclear(&w->light_point, destroy_light_point);
	w->light_point = ft_lstnew(create_point_light(create_point(0, 0.25, 0), create_color(1, 1, 1)));
	ray = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	shape = (t_shape *)w->shapes->next->content;
	i = create_intersection(0.5, shape);
	comps = prepare_computation(i, ray);
	color = shade_hit(w, comps, w->light_point);
	TEST_ASSERT_TRUE(is_equal_double(0.90498, color.r));
	TEST_ASSERT_TRUE(is_equal_double(0.90498, color.g));
	TEST_ASSERT_TRUE(is_equal_double(0.90498, color.b));
	free(i);
	destroy_world(w);
}

void	test_color_intersect_behind_ray(void)
{
	t_world		*w;
	t_ray		ray;
	t_color		color;
	t_shape		*outer, *inner;

	w = default_world();
	outer = (t_shape *)w->shapes->content;
	outer->material.ambient = create_color(1, 1, 1);
	inner = (t_shape *)w->shapes->next->content;
	inner->material.ambient = create_color(1, 1, 1);
	ray = create_ray(create_point(0, 0, 0.75), create_vector(0, 0, -1));
	color = color_at(w, ray);
	TEST_ASSERT_TRUE(is_equal_double(inner->material.color.r, color.r));
	TEST_ASSERT_TRUE(is_equal_double(inner->material.color.g, color.g));
	TEST_ASSERT_TRUE(is_equal_double(inner->material.color.b, color.b));
	destroy_world(w);
}

void	test_world(void)
{
	RUN_TEST(test_create_world);
	RUN_TEST(test_intersect_world);
	RUN_TEST(test_precomputing);
	RUN_TEST(test_hit_intersection_inside);
	RUN_TEST(test_shading_intersection);
	RUN_TEST(test_color_ray_misses);
	RUN_TEST(test_color_ray_hits);
	RUN_TEST(test_color_intersect_behind_ray);
	RUN_TEST(test_shading_intersection_inside);
}
