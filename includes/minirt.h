#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include "../libs/libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "defines.h"
# include "error.h"
# include <fcntl.h>

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

//// APAGAR ////
void		print_array(char **str);
#endif
