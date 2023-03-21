#include "minirt.h"

void	replace_char(char *str, int value_substituted)
{
	size_t		i;

	i = -1;
	while (str[++i])
	{
		if ((ft_isspace(str[i]) && str[i] != ' ')
			|| (str[i] == '\n' && str[i] != ' ' ))
			str[i] = value_substituted;
	}
}

int	is_invalid_file_data(char	**tokens)
{
	int		i;
	int		j;

	i = 1;
	while (tokens[i])
	{	
		j = 0;
		while (tokens[i][j])
		{
			if (!ft_isdigit(tokens[i][j]) && tokens[i][j] != '.'
				&& tokens[i][j] != ',' && tokens[i][j] != '-'
					&& tokens[i][j] != '\n')
				return (ERROR);
			j++;
		}
		i++;
	}
	return (0);
}

static int	identifier(char *line, t_scene *scene)
{
	char	**tokens;

  replace_char(line, ' ');
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	if (ft_strncmp(tokens[0], "A", 1) == 0)
		return (check_id_a(tokens, scene));
	else if (ft_strcmp(tokens[0], "C") == 0)
    	return (check_id_c(tokens));
	else if (ft_strcmp(tokens[0], "L") == 0)
		return (parser_light(tokens, scene));
	else if (ft_strcmp(tokens[0], "sp") == 0)
		return (OK);
	else if (ft_strcmp(tokens[0], "pl") == 0)
		return (OK);
	else if (ft_strcmp(tokens[0], "cy") == 0)
		return (OK);
	else if (tokens[0][0] == '#')
		return (OK);
	ft_free_array(tokens);
	return (OK);
}

int	read_file(char *filename, t_scene *scene)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	while (42)
	{
		line = gnl(fd);
		if (!line)
			return (0);
		if (identifier(line, scene) == 1)
			return (ERROR);
		free(line);
	}
	close (fd);
	return (OK);
}
