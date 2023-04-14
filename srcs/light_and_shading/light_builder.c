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
	material.ambient = 0.1;
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200.0;
	return (material);
}

t_pos_attr	create_pos_attr(t_vector eyev, t_vector normalv, t_point pos)
{
	t_pos_attr	attributes;

	attributes.eyev = eyev;
	attributes.normalv = normalv;
	attributes.point = pos;
	return (attributes);
}

t_lighting	set_lighting(t_light_pnt *light_p, t_pos_attr pos, t_material m)
{
	t_lighting	att;

	att.shape = NULL;
	att.light_p = light_p;
	att.eyev = pos.eyev;
	att.normalv = pos.normalv;
	att.point = pos.point;
	att.m = m;
	att.light_normal = 0;
	return (att);
}


