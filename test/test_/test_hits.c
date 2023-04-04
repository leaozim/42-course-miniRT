# include "../h_test.h"

static void	hit_intersections_positive_t(double t1, double t2, double expec, t_scene *scene)
{
	t_shape		shape;
	t_sphere	*sphere;
	double		i;

	(void)t1; //rmeover
	(void)t2; //remover 
	i = 42; // remover

	sphere = &shape.sphere;
	sphere =  (t_sphere *)scene->shapes->content;
	shape.sphere = *sphere;

	// teste:
	// i1 ← intersection(t1, shape.sphere);
	// i2 ← intersection(t2, shape.sphere);
	// xs ← intersections(i2, i1)
	// i  ← hit(xs);
	// Then i = expec
	TEST_ASSERT_EQUAL_DOUBLE(expec, i);	
	
}

static void	hit_intersections_negative_t(double t1, double t2, double expec, t_scene *scene)
{
	t_shape		shape;
	t_sphere	*sphere;
	double		i;

	(void)t1; //rmeover
	(void)t2; //remover 
	i = 21; // remover

	sphere = &shape.sphere;
	sphere =  (t_sphere *)scene->shapes->content;
	shape.sphere = *sphere;

	// teste:
	// i1 ← intersection(t1, shape.sphere);
	// i2 ← intersection(t2, shape.sphere);
	// xs ← intersections(i2, i1)
	// i ← hit(xs);
	// Then i = expec
	TEST_ASSERT_EQUAL_DOUBLE(expec, i);	
	
}

static void	hit_intersections_all_negative_t(double t1, double t2, double expec, t_scene *scene)
{
	t_shape		shape;
	t_sphere	*sphere;
	double		i;

	(void)t1; //rmeover
	(void)t2; //remover 
	i = 73; // remover

	sphere = &shape.sphere;
	sphere =  (t_sphere *)scene->shapes->content;
	shape.sphere = *sphere;

	// teste:
	// i1 ← intersection(t1, shape.sphere);
	// i2 ← intersection(t2, shape.sphere);
	// xs ← intersections(i2, i1)
	// i ← hit(xs);
	// Then i = expec
	TEST_ASSERT_EQUAL_DOUBLE(expec, i);	
}

static void	hit_intersections_nonnegative_t(t_scene *scene)
{
	t_shape		shape;
	t_sphere	*sphere;
	double		i;
	double		expec;

	expec = 2.0; 
	i = 37; // remover

	sphere = &shape.sphere;
	sphere =  (t_sphere *)scene->shapes->content;
	shape.sphere = *sphere;

	// teste:
	// i1 ← intersection(5, shape.sphere);
	// i2 ← intersection(7, shape.sphere);
	// i3 ← intersection(-3, shape.sphere);
	// i4 ← intersection(2, shape.sphere);
	// xs ← intersections(i1, i2, i3, i4);
	// i ← hit(xs);
	// Then i = i4;
	TEST_ASSERT_EQUAL_DOUBLE(expec, i);
}

void	hits_test(void)
{
	t_scene	scene;

	scene = create_sphere_test();
	hit_intersections_positive_t(1, 2, 1, &scene);
	hit_intersections_negative_t(-1, 1, 1, &scene);
	hit_intersections_all_negative_t(-2, -1, -1, &scene);
	hit_intersections_nonnegative_t(&scene);
}


void	test_hit(void)
{
	RUN_TEST(hits_test);
}