# include "../h_test.h"

double	rand_double()
{
	double valor = ((double) rand() * 2) / ( double ) RAND_MAX;
	return (valor);
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

