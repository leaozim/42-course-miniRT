# include "../h_test.h"

double	rand_double()
{
	double valor = ((double) rand() * 2) / ( double ) RAND_MAX;
	return (valor);
}