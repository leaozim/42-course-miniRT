# include "../h_test.h"

static void	hit_test(double t1, double t2, double expec, t_scene *scene)
{
	t_shape		shape;
	t_sphere	*sphere;

	sphere = &shape.sphere;
	sphere =  (t_sphere *)scene->shapes->content;
	shape.sphere = *sphere;
	
	
}

void	hit_intersections_positive_t(void)
{
	t_scene	scene;
	char	**tokens;

	ft_bzero(&scene, sizeof(t_scene));
	tokens = malloc(4 * sizeof(char *));
	tokens[0] = strdup("sp");
	tokens[1] = strdup("0,-10,0");
	tokens[2] = strdup("1.0");
	tokens[3] = strdup("250,200,54");
	create_sphere_node(tokens, &scene);
	hit_test(1, 2, 1, &scene);
}

void	test_hit(void)
{
	RUN_TEST(hit_intersections_positive_t);
}