#include "minirt.h"

t_light_pnt	*create_point_light(t_point position, t_color intensity)
{
	t_light_pnt	*light;

	light = (t_light_pnt *)malloc(sizeof(t_light_pnt));
	light->position = position;
	light->intensity = intensity;
	return (light);
}

t_material	create_material(void)
{
	t_material	material;

	material.color = create_color(1, 1, 1);
	material.ambient = create_color(0.1, 0.1, 0.1);
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200.0;
	return (material);
}
