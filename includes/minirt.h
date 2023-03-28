#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include "defines.h"
# include "error.h"
# include <fcntl.h>
# include <math.h>
// apagar
# include <stdio.h>

void		error_msg(char *msg);
int			check_argc(int argc);
int			read_file(char *filename, t_scene *scene);
int			check_id_a(char **tokens, t_bool *is_duplicate);
int			check_id_c(char **tokens, t_bool *is_duplicate);
int			check_id_l(char **tokens, t_bool *is_duplicate);
int			check_id_sp(char **tokens);
int			check_id_pl(char **tokens);
int			check_id_cy(char **tokens);
int			is_invalid_file_data(char **tokens);
int			check_orientation(char *tokens);
int			check_coordinates(char *tokens);
int			check_color(char *tokens);
t_color		set_color(double r, double g, double b);
t_tuple		create_parameter(char *tks, t_tuple (*f)(double, double, double));
t_point		create_point(double x, double y, double z);
t_vector	create_vector(double x, double y, double z);
t_tuple		create_tuple(double x, double y, double z, double w);
void		replace_char(char *str, int value_substituted);	
int			check_file(char *filename);
int			check_open_file(char *file);
void		create_sphere_node(char **tokens, t_scene *scene);
void		create_light_node(char **tokens, t_scene *scene);
void		create_cylinder_node(char **tokens, t_scene *scene);
void		destroy_minirt(t_scene *scene);
t_color		create_parameter_color(char *tokens);
void		create_camera(char **tokens, t_scene *scene);
void		create_plane_node(char **tokens, t_scene *scene);
void		create_ambient(char **tokens, t_scene *scene);
int			soma(int a, int b);
t_tuple		neg_tuple(t_tuple tuple);
t_tuple		multiply_tupla(t_tuple tuple, double multiplier);
t_vector	normalize(t_vector vector);
double		dot_product(t_vector vec1, t_vector vec2);
t_tuple		adding_tuples(t_tuple a, t_tuple b);
t_tuple		sub_tuples(t_tuple a, t_tuple b);
t_tuple		div_tuples(t_tuple t, double div);
double		magnitude(t_vector vec);
t_vector	cross_product(t_vector vec1, t_vector vec2);
t_canvas	create_canvas(void *mlx_ptr);
void		destroy_mlx(void *mlx_ptr, void *win_ptr);
void	    write_pixel(void *mlx_ptr, int width, int height, t_color color, t_canvas canvas);









//// APAGAR ////
void		print_array(char **str);
#endif
