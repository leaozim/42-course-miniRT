# include "../h_test.h"

void	test_normal_sphere_point_x_axis(void)
{
	t_shape		*sphere;
	t_vector		n;

	sphere = create_sphere();
	n = normal_at(sphere, create_point(1, 0, 0));
	TEST_ASSERT_TRUE(is_equal_tuple((t_vector){1, 0, 0, 0}, n));
	destroy_shape(sphere);
}

void	test_normal_sphere_point_y_axis(void)
{
	t_shape		*sphere;
	t_vector		n;

	sphere = create_sphere();
	n = normal_at(sphere, create_point(0, 0, 1));
	TEST_ASSERT_TRUE(is_equal_tuple((t_vector){0, 0, 1, 0}, n));
	destroy_shape(sphere);
}

void	test_normal_sphere_point_z_axis(void)
{
	t_shape		*sphere;
	t_vector		n;

	sphere = create_sphere();
	n = normal_at(sphere, create_point(0, 1, 0));
	TEST_ASSERT_TRUE(is_equal_tuple((t_vector){0, 1, 0, 0}, n));
	destroy_shape(sphere);
}

void	test_normal_sphere_nonaxial_point(void)
{
	t_shape		*sphere;
	t_vector		n;

	sphere = create_sphere();
	n = normal_at(sphere, create_point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
	TEST_ASSERT_TRUE(is_equal_tuple((t_vector){sqrt(3)/3, sqrt(3)/3, sqrt(3)/3, 0}, n));
	destroy_shape(sphere);
}

void	test_normal_normalized_vector(void)
{
	t_shape		*sphere;
	t_vector		n;

	sphere = create_sphere();
	n = normal_at(sphere, create_point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
	TEST_ASSERT_TRUE(is_equal_tuple((t_vector){sqrt(3)/3, sqrt(3)/3, sqrt(3)/3, 0}, n));
	destroy_shape(sphere);
}

void	test_computing_normal_translated_sphere(void)
{
	t_shape		*sphere;
	t_vector		n;

	sphere = create_sphere();
	set_transform(sphere, translation(0, 1, 0));
	n = normal_at(sphere, create_point(0, 1.70711, -0.70711));
	TEST_ASSERT_TRUE(is_equal_tuple((t_vector){0, 0.70711, -0.70711, 0}, n));
	destroy_shape(sphere);
}

void	test_computing_normal_transformed_sphere(void)
{
	t_shape		*sphere;
	t_vector		n;
	t_matrix		m, s, r;

	sphere = create_sphere();
	s = scaling(1, 0.5, 1);
	r = rotation_z(radians(180 / 5));
	m = multiply_matrix(s, r);
	set_transform(sphere, m);
	n = normal_at(sphere, create_point(0, sqrt(2)/2, -sqrt(2)/2));
	TEST_ASSERT_TRUE(is_equal_tuple((t_vector){0, 0.97014, -0.24254, 0}, n));
	destroy_shape(sphere);
}

void	test_reflecting_vector_approaching_45(void)
{
	t_vector	v, n, r;

	v = create_vector(1, -1, 0);
	n = create_vector(0, 1, 0);
	r = reflect(v, n);
	TEST_ASSERT_TRUE(is_equal_tuple((t_vector){1, 1, 0, 0}, r));
}

void	test_reflecting_vector_off_slanted_surface(void)
{
	t_vector	v, n, r;

	v = create_vector(0, -1, 0);
	n = create_vector(sqrt(2)/2, sqrt(2)/2, 0);
	r = reflect(v, n);
	TEST_ASSERT_TRUE(is_equal_tuple((t_vector){1, 0, 0, 0}, r));
}

void	test_point_light_position_and_intensity(void)
{
	t_color		intensi;
	t_point		posit;
	t_light_pnt	*light;

	intensi = create_color(1, 1 ,1);
	posit = create_point(0, 0, 0);
	light = create_point_light(posit, intensi);
	TEST_ASSERT_TRUE(is_equal_tuple(posit, light->position));
	TEST_ASSERT_TRUE(is_equal_double(1, light->intensity.r));
	TEST_ASSERT_TRUE(is_equal_double(1, light->intensity.g));
	TEST_ASSERT_TRUE(is_equal_double(1, light->intensity.b));
	free(light);
}

void	test_default_material(void)
{
	t_material	m;

	m = create_material();
	TEST_ASSERT_TRUE(is_equal_double(1, m.color.r));
	TEST_ASSERT_TRUE(is_equal_double(1, m.color.g));
	TEST_ASSERT_TRUE(is_equal_double(1, m.color.b));
	TEST_ASSERT_TRUE(is_equal_double(0.1, m.ambient.r));
	TEST_ASSERT_TRUE(is_equal_double(0.1, m.ambient.g));
	TEST_ASSERT_TRUE(is_equal_double(0.1, m.ambient.b));
	TEST_ASSERT_TRUE(is_equal_double(0.9, m.diffuse));
	TEST_ASSERT_TRUE(is_equal_double(0.9, m.specular));
	TEST_ASSERT_TRUE(is_equal_double(200.0, m.shininess));
}

void	test_lighting_with_eye_between_light_and_surface(void)
{
	t_lighting	light;
	t_color		result;

	light = init_lighting();
	light.eyev = create_vector(0, 0, -1);
	light.normalv = create_vector(0, 0, -1);
	free(light.light_p);
	light.light_p = create_point_light(create_point(0, 0, -10), create_color(1, 1, 1));
	light.m = create_material();
	result = create_lighting(light);
	TEST_ASSERT_TRUE(is_equal_double(1.9, result.r));
	TEST_ASSERT_TRUE(is_equal_double(1.9, result.g));
	TEST_ASSERT_TRUE(is_equal_double(1.9, result.b));
	free(light.light_p);
}

void	test_lighting_eye_between_light_and_surface_eye_offset_45(void)
{
	t_lighting	light;
	t_color		result;

	light = init_lighting();
	light.eyev = create_vector(0, sqrt(2)/2, -sqrt(2)/2);
	light.normalv = create_vector(0, 0, -1);
	free(light.light_p);
	light.light_p = create_point_light(create_point(0, 0, -10), create_color(1, 1, 1));
	light.m = create_material();
	result = create_lighting(light);
	TEST_ASSERT_TRUE(is_equal_double(1.0, result.r));
	TEST_ASSERT_TRUE(is_equal_double(1.0, result.g));
	TEST_ASSERT_TRUE(is_equal_double(1.0, result.b));
	free(light.light_p);
}

void	test_lighting_eye_opposite_surface_light_offset_45(void)
{
	t_lighting	light;
	t_color		result;

	light = init_lighting();
	light.eyev = create_vector(0, 0, -1);
	light.normalv = create_vector(0, 0, -1);
	free(light.light_p);
	light.light_p = create_point_light(create_point(0, 10, -10), create_color(1, 1, 1));
	light.m = create_material();
	result = create_lighting(light);
	TEST_ASSERT_TRUE(is_equal_double(0.7364, result.r));
	TEST_ASSERT_TRUE(is_equal_double(0.7364, result.g));
	TEST_ASSERT_TRUE(is_equal_double(0.7364, result.b));
	free(light.light_p);
}

void	test_lighting_eye_path_reflection_vector(void)
{
	t_lighting	light;
	t_color		result;

	light = init_lighting();
	light.eyev = create_vector(0, -sqrt(2)/2, -sqrt(2)/2);
	light.normalv = create_vector(0, 0, -1);
	free(light.light_p);
	light.light_p = create_point_light(create_point(0, 10, -10), create_color(1, 1, 1));
	light.m = create_material();
	result = create_lighting(light);
	TEST_ASSERT_TRUE(is_equal_double(1.6364, result.r));
	TEST_ASSERT_TRUE(is_equal_double(1.6364, result.g));
	TEST_ASSERT_TRUE(is_equal_double(1.6364, result.b));
	free(light.light_p);
}

void	test_lighting_light_behind_surface(void)
{
	t_lighting	light;
	t_color		result;

	light = init_lighting();
	light.eyev = create_vector(0, 0, -1);
	light.normalv = create_vector(0, 0, -1);
	free(light.light_p);
	light.light_p = create_point_light(create_point(0, 0, 10), create_color(1, 1, 1));
	light.m = create_material();
	result = create_lighting(light);
	TEST_ASSERT_TRUE(is_equal_double(0.1, result.r));
	TEST_ASSERT_TRUE(is_equal_double(0.1, result.g));
	TEST_ASSERT_TRUE(is_equal_double(0.1, result.b));
	free(light.light_p);
}

void	test_lighting_surface_in_shadow(void)
{
	t_lighting	light;
	t_color		result;

	light = init_lighting();
	light.eyev = create_vector(0, 0, -1);
	light.normalv = create_vector(0, 0, -1);
	free(light.light_p);
	light.light_p = create_point_light(create_point(0, 0, 10), create_color(1, 1, 1));
	light.m = create_material();
	light.in_shadow = TRUE;
	result = create_lighting(light);
	TEST_ASSERT_TRUE(is_equal_double(0.1, result.r));
	TEST_ASSERT_TRUE(is_equal_double(0.1, result.g));
	TEST_ASSERT_TRUE(is_equal_double(0.1, result.b));
	free(light.light_p);
}

void	test_there_no_shadow_when_nothing_collinear_with_point_and_light(void)
{
	t_world	*w;
	t_point	p;

	w = default_world();
	p = create_point(0, 10, 0);
	TEST_ASSERT_FALSE(is_shadowed(w, p, w->light_point->content));
	destroy_world(w);
}

void	test_shadow_when_aobject_is_between_point_and_light(void)
{
	t_world	*w;
	t_point	p;

	w = default_world();
	p = create_point(10, -10, 10);
	TEST_ASSERT_TRUE(is_shadowed(w, p, w->light_point->content));
	destroy_world(w);
}

void	test_there_no_shadow_when_an_object_is_behind_light(void)
{
	t_world	*w;
	t_point	p;

	w = default_world();
	p = create_point(-20, 20, -20);
	TEST_ASSERT_FALSE(is_shadowed(w, p, w->light_point->content));
	destroy_world(w);
}

void	test_there_no_shadow_when_an_object_is_behind_point(void)
{
	t_world	*w;
	t_point	p;

	w = default_world();
	p = create_point(-2, 2, -2);
	TEST_ASSERT_FALSE(is_shadowed(w, p, w->light_point->content));
	destroy_world(w);
}

void	test_shade_hit_is_given_an_intersection_in_shadow(void)
{
	t_world	*w;
	t_shape	*s1, *s2;
	t_ray		ray;
	t_intersection	*i;
	t_comps		comps;
	t_color		color;

	w = create_world();
	w->light_point = ft_lstnew(create_point_light(create_point(0, 0, -10), create_color(1, 1, 1)));
	s1 = create_sphere();
	s2 = create_sphere();
	set_transform(s2,  translation(0, 0, 10));
	ft_lstadd_front(&w->shapes, ft_lstnew(s1));
	ft_lstadd_front(&w->shapes, ft_lstnew(s2));
	ray = create_ray(create_point(0, 0, 5), create_vector(0, 0, 1));
	i = create_intersection(4, s2);
	comps = prepare_computation(i, ray);
	color = shade_hit(w, comps, w->light_point);
	TEST_ASSERT_EQUAL_DOUBLE(0.1, color.r);
	TEST_ASSERT_EQUAL_DOUBLE(0.1, color.g);
	TEST_ASSERT_EQUAL_DOUBLE(0.1, color.b);
	destroy_world(w);
	free(i);
}

void	test_hit_should_offset_the_point(void)
{
	t_intersection	*i;
	t_shape		*shape;
	t_ray		ray;
	t_comps		comps;

	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	shape = create_sphere();
	set_transform(shape, translation(0, 0, 1));
	i = create_intersection(5, shape);
	comps = prepare_computation(i, ray);
	TEST_ASSERT_TRUE(comps.over_point.z < -EPSILON / 2);
	TEST_ASSERT_TRUE(comps.point.z > comps.over_point.z);
	destroy_shape(shape);
	free(i);
}

void	test_light_and_shading(void)
{
	RUN_TEST(test_normal_sphere_point_x_axis);
	RUN_TEST(test_normal_sphere_point_y_axis);
	RUN_TEST(test_normal_sphere_point_z_axis);
	RUN_TEST(test_normal_sphere_nonaxial_point);
	RUN_TEST(test_normal_normalized_vector);
	RUN_TEST(test_computing_normal_translated_sphere);
	RUN_TEST(test_computing_normal_transformed_sphere);
	RUN_TEST(test_reflecting_vector_approaching_45);
	RUN_TEST(test_reflecting_vector_off_slanted_surface);
	RUN_TEST(test_point_light_position_and_intensity);
	RUN_TEST(test_default_material);
	RUN_TEST(test_lighting_with_eye_between_light_and_surface);
	RUN_TEST(test_lighting_eye_between_light_and_surface_eye_offset_45);
	RUN_TEST(test_lighting_eye_opposite_surface_light_offset_45);
	RUN_TEST(test_lighting_eye_path_reflection_vector);
	RUN_TEST(test_lighting_light_behind_surface);
	RUN_TEST(test_lighting_surface_in_shadow);
	RUN_TEST(test_there_no_shadow_when_nothing_collinear_with_point_and_light);
	RUN_TEST(test_shadow_when_aobject_is_between_point_and_light);
	RUN_TEST(test_there_no_shadow_when_an_object_is_behind_light);
	RUN_TEST(test_there_no_shadow_when_an_object_is_behind_point);
	RUN_TEST(test_shade_hit_is_given_an_intersection_in_shadow);
	RUN_TEST(test_hit_should_offset_the_point);
}
