#ifndef DEFINES_H
# define DEFINES_H

enum e_status
{
	OK,
	ERROR
};

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef t_tuple	t_vector;
typedef t_tuple	t_point;

typedef struct  s_ambient
{
	double	ratio;
	t_color	color;	
}	t_ambient;

typedef struct s_camera
{
	t_point		point_of_view;
	t_vector	vector;
	double		field_of_view;
}	t_camera;

typedef struct s_light
{
	t_point	coord;
}	t_light;

typedef struct s_sphere
{
	t_point coord;
	double	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_point		coord;
	t_vector	vector;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_point		coord;
	t_vector	vector;
	double		diameter;
	double		size;
}	t_cylinder;

typedef struct s_identifier
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}	t_identifier;
 



#endif