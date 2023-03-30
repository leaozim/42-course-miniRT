#ifndef DEFINES_H
# define DEFINES_H

enum e_status
{
	OK,
	ERROR
};

typedef struct s_mlx
{
	void	*mlx;
}	t_mlx;

typedef struct s_canvas
{
	void	*window;
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endianness;
}	t_canvas;

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

enum e_objects
{
	SPHERE,
	PLANE,
	AMBIENT,
};

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
	int		mixed;
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

typedef struct s_ambient
{
	double		ratio;
	t_color		color;
}	t_ambient;

typedef struct s_camera
{
	t_point		point_of_view;
	t_vector	vector;
	double		field_of_view;
}	t_camera;

typedef struct s_light
{
	t_point		coord;
	double		brightness;
}	t_light;

typedef struct s_sphere
{
	t_point		coord;
	double		diameter;
	t_color		color;
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
	double		height;
	t_color		color;
}	t_cylinder;

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_list		*shapes;
	t_list		*lights;
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

typedef struct s_matrix
{
	size_t	size;
	double	matrix[4][4];
}	t_matrix;

typedef struct s_shearing
{
	double	x_y;
	double	x_z;
	double	y_x;
	double	y_z;
	double	z_x;
	double	z_y;
}	t_shearing;

# define EPSILON 0.0001
# define CAMERA 0
# define LIGHT 1
# define CYLINDER 2
# define VECTOR_W 0
# define POINT_W 1
# define MTRX_MAX 4

#endif