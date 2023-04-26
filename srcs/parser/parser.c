#include "minirt.h"

static int	set_shape(char *line, t_scene *scene)
{
	char	**tokens;

	replace_char(line, ' ');
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (ft_free_array(tokens), 0);
	if (ft_strcmp(tokens[0], _AMBIENT_) == 0)
		return (create_ambient(tokens, scene), OK);
	else if (ft_strcmp(tokens[0], _CAMERA_) == 0)
		return (create_camera(tokens, scene), OK);
	else if (ft_strcmp(tokens[0], _LIGHT_) == 0)
		return (create_light_node(tokens, scene), OK);
	else if (ft_strcmp(tokens[0], _SPHERE_) == 0)
		return (create_sphere_node(tokens, scene), OK);
	else if (ft_strcmp(tokens[0], _PLANE_) == 0)
		return (create_plane_node(tokens, scene), OK);
	else if (ft_strcmp(tokens[0], _CYLINDER_) == 0)
		return (create_cylinder_node(tokens, scene), OK);
	ft_free_array(tokens);
	return (ERROR);
}

int	read_file(char *filename, t_scene *scene)
{
	char	**tokens;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	while (42)
	{
		line = gnl(fd);
		if (!line)
			return (close(fd), free(line), OK);
		set_shape(line, scene);
		free(line);
	}
	ft_free_array(tokens);
	close (fd);
	return (0);
}
