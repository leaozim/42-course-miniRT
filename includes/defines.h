#ifndef DEFINES_H
# define DEFINES_H

enum e_status
{
	OK,
	ERROR
};

enum e_objects
{
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef t_tuple	t_vector;
typedef t_tuple	t_point;

# define t_color t_tuple
# define r x
# define g y
# define b z
# define mixed w
# define VECTOR_W 0
# define POINT_W 1

typedef struct s_ambient
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
	double	brightness;
}	t_light;

typedef struct s_sphere
{
	t_point	coord;
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

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_list		*shapes;
	t_list		*lights;
	int			i;
}	t_scene;

typedef struct s_shape
{
	enum e_objects	type;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	};
}	t_shape;

#endif