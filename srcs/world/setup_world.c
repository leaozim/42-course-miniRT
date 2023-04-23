#include "minirt.h"

static void	set_lights(t_list **light, t_scene *s)
{
	*light = s->lights;
}

static void	set_shapes(t_list **shapes, t_scene *s)
{
	t_shape	*current_shape;
	t_list	*shape_list;

	shape_list = s->shapes;
	while (shape_list)
	{
		current_shape = (t_shape *)shape_list->content;
		set_shape_material(current_shape, s);
		shape_list = shape_list->next;
	}
	*shapes = s->shapes;
}

t_world	*setup_world(t_scene *scene)
{
	t_world	*w;

	w = create_world();
	set_shapes(&w->shapes, scene);
	set_lights(&w->light_point, scene);
	return (w);
}
