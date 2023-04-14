#include "minirt.h"

t_shape	*create_sphere(void)
{
	t_shape	*shape;

	// criar a create_shape setando algumas matrizes padroes
	shape = (t_shape *)malloc(sizeof(t_shape));
	shape->type = SPHERE;
	shape->sphere.coord = create_point(0, 0, 0);
	shape->sphere.diameter = 1.0;
	shape->sphere.color = set_color(255, 182, 100);
	shape->inverse = create_identity_matrix();
	return (shape);
}
