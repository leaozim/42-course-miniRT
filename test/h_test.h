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
void	test_matrix(void);
void 	test_soma(void);
void	test_sum_array(void);
void	test_operation_tuple(void);
void	test_operation_color(void);
void	test_canvas(void);
void    test_rotation(void);
void	test_shearing(void);
void	test_transformations_matrix(void);
void	test_hit(void);
void	test_ray(void);

t_bool	is_equal_tuple(t_tuple a, t_tuple b);
t_shearing	set_shearing(void);
t_scene	create_sphere_test(void);


#endif
