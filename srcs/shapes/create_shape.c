#include <minirt.h>

t_shape	*create_shape(void)
{
	t_shape	*shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	if (!shape)
		return (NULL);
	shape->material = create_material();
	shape->transform = create_identity_matrix();
	shape->transpose = create_identity_matrix();
	shape->inverse = create_identity_matrix();
	shape->orientation = create_vector(0, 0, 0);
	return (shape);
}
