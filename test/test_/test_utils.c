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
