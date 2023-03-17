#include "minirt.h"

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

int	check_id_a(char **tokens)
{
	double	floating;

	floating = 0.0;
	if (is_invalid_file_data(tokens))
		return (error_msg("File data is invalid"), ERROR);
	if (!ft_isfloat(tokens[1]))
		return (error_msg("Parameter needs to be a Float"), ERROR);
	floating = ft_atof(tokens[1]);
	if (ft_isrange(floating, 0, 1))
		return (error_msg("Incorrect range of numbers"), ERROR);
	return (0);
}

static int	identifier(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	if (ft_strncmp(tokens[0], "A", 1) == 0)
		check_id_a(tokens);
	if (ft_strncmp(tokens[0], "C", 1) == 0)
		return (OK);
	if (ft_strncmp(tokens[0], "L", 1) == 0)
		return (OK);
	if (ft_strncmp(tokens[0], "sp", 2) == 0)
		return (OK);
	if (ft_strncmp(tokens[0], "pl", 2) == 0)
		return (OK);
	if (ft_strncmp(tokens[0], "cy", 2) == 0)
		return (OK);
	return (0);
}

int	read_file(char *filename)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	while (42)
	{
		line = gnl(fd);
		if (!line)
			return (0);
		identifier(line);
	}
	return (0);
}
