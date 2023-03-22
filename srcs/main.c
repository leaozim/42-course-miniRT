#include "minirt.h"

void	print_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_scene	scene;
		t_shape	*current_shape;
	t_list	*shape_list;

	if (check_argc(argc))
		return (EXIT_FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	if (check_file(argv[1]) == ERROR)
		return (EXIT_FAILURE);
	read_file(argv[1], &scene);

	shape_list = scene.shapes;
	current_shape = (t_shape *)shape_list->content;
	printf("%lf\n", current_shape->sphere.color.R * 255);
	printf("%f\n", current_shape->sphere.color.G * 255);
	printf("%lf\n", current_shape->sphere.diameter);
	destroy_minirt(&scene);
	return (0);
}
