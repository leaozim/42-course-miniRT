#ifndef H_TEST_H
# define H_TEST_H

# include "unity/unity.h"
# include <string.h>
# include "../includes/minirt.h"
# include <math.h>
# include <stdlib.h>

#define MAX_INTERATIONS 100

double	rand_double();
double	rand_rgb();
void		test_soma(void);
void		test_sum_array(void);
void		test_operation_tuple(void);
void		test_operation_color(void);
void		test_matrix(void);

#endif
