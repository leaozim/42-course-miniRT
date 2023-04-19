# include "../h_test.h"

double	rand_double()
{
	double valor = ((double) rand() * 2) / ( double ) RAND_MAX;
	return (valor);
}

double color_rand()
{
	return ((double)rand() / RAND_MAX);
}


double	rand_rgb()
{
	double valor = (double) (rand() % 255);
	return (valor);
}

t_bool	is_equal_tuple(t_tuple a, t_tuple b)
{
	return (
		is_equal_double(a.x, b.x) && \
		is_equal_double(a.y, b.y) && \
		is_equal_double(a.z, b.z) && \
		is_equal_double(a.w, b.w)
	);
}

t_scene	create_sphere_test(void)
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
	return (scene);
}

t_shearing	set_shearing(void)
{
	t_shearing	s;

	s.x_y = 1;
	s.x_z = 0;
	s.y_x = 0;
	s.y_z = 0;
	s.z_x = 0;
	s.z_y = 0;
	return (s);
}

t_color	formatted_color(t_color color, double r, double g, double b)
{
	color.r = r;
	color.g = g;
	color.b = b;
	color.mixed = merge_colors(r, g, b);
	return (color);
}

void	destroy_shape(t_shape *shape)
{
	free(shape);
}
