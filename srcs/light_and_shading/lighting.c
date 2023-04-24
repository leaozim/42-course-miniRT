#include "minirt.h"

t_lighting	init_lighting(void)
{
	t_lighting	args;

	args.light_normal = 0;
	args.point = create_point(0, 0, 0);
	args.shape = NULL;
	args.eyev = create_vector(0, 0, 0);
	args.normalv = create_vector(0, 0, 0);
	args.m = create_material();
	args.in_shadow = FALSE;
	args.light_p = create_point_light(create_point(0, 0, 0), \
	create_color(0, 0, 0));
	return (args);
}

static t_color	get_diffuse(t_lighting args, t_color effect_color)
{
	t_color		diffuse;

	if (args.light_normal < 0)
		return (create_color(0, 0, 0));
	diffuse = multiply_color_scalar(effect_color, args.m.diffuse);
	diffuse = multiply_color_scalar(diffuse, args.light_normal);
	return (diffuse);
}

static t_color	get_specular(t_lighting args, t_vector lightv)
{
	t_color		specular;
	double		factor;
	t_vector	reflectv;
	double		reflect_dot_eye;

	if (args.light_normal < 0)
		return (create_color(0, 0, 0));
	reflectv = reflect(neg_tuple(lightv), args.normalv);
	reflect_dot_eye = dot_product(reflectv, args.eyev);
	if (reflect_dot_eye <= 0)
		return (create_color(0, 0, 0));
	factor = pow(reflect_dot_eye, args.m.shininess);
	specular = multiply_color_scalar(args.light_p->intensity, args.m.specular);
	specular = multiply_color_scalar(specular, factor);
	return (specular);
}

static t_color	generate_color(t_color ambient, t_color	diffuse, t_color spec)
{
	t_color	color_final;

	color_final = adding_color(ambient, diffuse);
	color_final = adding_color(color_final, spec);
	return (color_final);
}

t_color	create_lighting(t_lighting args)
{
	t_color		effect_color;
	t_vector	lightv;
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;

	effect_color = multiply_color(args.m.color, args.light_p->intensity);
	ambient = multiply_color(effect_color, args.m.ambient);
	if (args.in_shadow == TRUE)
		return (ambient);
	lightv = normalize(sub_tuples(args.light_p->position, args.point));
	args.light_normal = dot_product(lightv, args.normalv);
	diffuse = get_diffuse(args, effect_color);
	specular = get_specular(args, lightv);
	return (generate_color(ambient, diffuse, specular));
}
