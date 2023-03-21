#include "minirt.h"

static int	set_shape(char **tokens, t_list shape)
{

	// if (ft_strcmp(tokens[0], "A") == 0)
		// return (OK);
	// else if (ft_strcmp(tokens[0], "C") == 0)
		// return (check_id_c(tokens));
	// else if (ft_strcmp(tokens[0], "L") == 0)
		// return (OK);
	if (ft_strcmp(tokens[0], "sp") == 0)
    {
        create_sphere(tokens);
    }
	return (0);
	// else if (ft_strcmp(tokens[0], "pl") == 0)
	// 	return (OK);
	// else if (ft_strcmp(tokens[0], "cy") == 0)
	// 	return (check_id_cy(tokens));
	// else if (tokens[0][0] == '#')
	// 	return (OK);
	// ft_free_array(tokens);
	return (error_msg("file data are invaded"), ERROR);
}

int	read_file(char *filename, t_scene *scene)
{
	char	**tokens;
	char	*line;
	int		fd;
    t_list  shape;

	(void)scene;
	fd = open(filename, O_RDONLY);
	while (42)
	{
		line = gnl(fd);
		if (!line)
			return (ERROR);
		replace_char(line, ' ');
		tokens = ft_split(line, ' ');
		if (!tokens)
			return (0);
		set_shape(tokens, &shape);
		free(line);
	}
	ft_free_array(tokens);
	close (fd);
	return (OK);
}