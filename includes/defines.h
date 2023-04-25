#ifndef DEFINES_H
# define DEFINES_H

# define EPSILON 0.0001
# define CAMERA 0
# define LIGHT 1
# define AMBIENT 2
# define VECTOR_W 0
# define POINT_W 1
# define MTRX_MAX 4
# define KEY_PRESS 02
# define ESC 65307
# define DESTROY_NOTIFY 17
# define NO_EVENT_MASK	0L
# define WIDTH 850
# define HEIGHT 650
# define _AMBIENT_ "A"
# define _CAMERA_ "C"
# define _LIGHT_ "L"
# define _SPHERE_ "sp"
# define _PLANE_ "pl"
# define _CYLINDER_ "cy"

# include "minirt.h"

enum e_status
{
	OK,
	ERROR
};

typedef struct s_matrix
{
	size_t	size;
	double	matrix[MTRX_MAX][MTRX_MAX];
}	t_matrix;

typedef struct s_canvas
{
	void	*mlx;
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
	CYLINDER,
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
	double		min;
	double		max;
	t_bool		closed;
}	t_cylinder;

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_list		*shapes;
	t_list		*lights;
}	t_scene;

typedef struct s_material
{
	t_color		color;
	t_color		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}	t_material;

typedef struct defines
{
	enum e_objects	type;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	};
	t_matrix		transform;
	t_material		material;
	t_matrix		transpose;
	t_matrix		inverse;
	t_vector		orientation;
}	t_shape;

typedef struct s_shearing
{
	double	x_y;
	double	x_z;
	double	y_x;
	double	y_z;
	double	z_x;
	double	z_y;
}	t_shearing;

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}	t_ray;

typedef t_list	t_intersections;
typedef struct s_intersection
{
	double	t;
	t_shape	*shapes;
}	t_intersection;

typedef struct s_bhaskara
{
	double	a;
	double	b;
	double	c;
	double	delta;

}	t_bhaskara;

typedef struct s_xs
{
	double	t1;
	double	t2;
	int		count;
}	t_xs;

typedef struct s_sorted
{
	t_intersection	*intersect;
	t_intersections	*aux;
	t_intersection	*intersect_head;	
}	t_sorted;

typedef struct s_light_pnt
{
	t_point	position;
	t_color	intensity;
	double	brightness;
}	t_light_pnt;

typedef struct s_lighting
{
	t_light_pnt	*light_p;
	t_shape		*shape;
	t_vector	eyev;
	t_vector	normalv;
	t_point		point;
	t_point		over_point;
	t_material	m;
	double		light_normal;
	t_bool		in_shadow;
}	t_lighting;

typedef struct s_world
{
	t_list	*light_point;
	t_list	*shapes;
}	t_world;

typedef struct s_comps
{
	t_shape		*shape;
	double		t;
	t_point		point;
	t_vector	normalv;
	t_vector	eyev;
	t_point		over_point;
}	t_comps;

typedef struct s_cam
{
	double		hsize;
	double		vsize;
	double		fov;
	double		pixel_size;
	double		half_width;
	double		half_height;
	t_matrix	transform;
	t_matrix	inverse;
}	t_cam;

#endif
