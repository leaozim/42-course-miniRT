#include "minirt.h"

static int	set_shape(char *line, t_scene *scene)
{
	char	**tokens;

	replace_char(line, ' ');
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	if (ft_strcmp(tokens[0], "A") == 0)
		return (create_ambient(tokens, scene), OK);
	else if (ft_strcmp(tokens[0], "C") == 0)
		return (create_camera(tokens, scene), OK);
	else if (ft_strcmp(tokens[0], "L") == 0)
		return (create_light_node(tokens, scene), OK);
	else if (ft_strcmp(tokens[0], "sp") == 0)
		return (create_sphere_node(tokens, scene), OK);
	else if (ft_strcmp(tokens[0], "pl") == 0)
		return (create_plane_node(tokens, scene), OK);
	else if (ft_strcmp(tokens[0], "cy") == 0)
		return (create_cylinder_node(tokens, scene), OK);
	else if (tokens[0][0] == '#')
		return (ft_free_array(tokens), OK);
	ft_free_array(tokens);
	return (ERROR);
}

int	read_file(char *filename, t_scene *scene)
{
	char	**tokens;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	while (42)
	{
		line = gnl(fd);
		if (!line)
			return (close(fd), 0);
		set_shape(line, scene);
		free(line);
	}
	ft_free_array(tokens);
	close (fd);
	return (OK);
}