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

	if (check_argc(argc) || check_file(argv[1]) == ERROR)
		return (EXIT_FAILURE);
	ft_bzero(&scene, sizeof(t_scene));
	printf("\n================================\n");
	read_file(argv[1], &scene);
	return (0);
}
