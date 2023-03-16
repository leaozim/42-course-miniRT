# include "minirt.h"

// int	ft_char_format_flout(char *nbr)
// {
	
// }

// int	is_invalid_flout(char **tokens)
// {
// 	int	i;

// 	i = 0;
// 	while (tokens[++i])
// 	{
// 		ft_char_format_flout
// 	}		
// }

int	is_invalid_data(char **tokens)
{
	int	i;
	int	j;

	i = 0;
	while (tokens[++i])
	{
		j = 0;
		while(tokens[i][j] != '\0')
		{
				if (!ft_isdigit(tokens[i][j]) && tokens[i][j] != '.' 
					&& tokens[i][j] != ',' && tokens[i][j] != '-' 
						&& tokens[i][j] != '\n')
				return (ERROR);
			j++;
		}
	}
	return (OK);
}

int	check_id_c(char **tokens)
{
	if (ft_array_size(tokens) != 4)
		return (error_msg("to many or few arguments for camera"), ERROR);
	if (is_invalid_data(tokens))
		return (error_msg("data are invaded"), ERROR);

	return (OK);
}

static int identifier(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if(!tokens)
		return (0);
	// if (ft_strncmp(tokens[0], "A", 1) == 0)
	// 	printf("check_id_a %s\n", line);
	if (ft_strncmp(tokens[0], "C", 1) == 0)
	{
		check_id_c(tokens);
	}
	// if (ft_strncmp(tokens[0], "L", 1) == 0)
	// 	printf("Letter L -> %s\n", line);
	// if (ft_strncmp(tokens[0], "sp", 1) == 0)
	// 	printf("Letter sp -> %s\n", line);
	// if (ft_strncmp(tokens[0], "pl", 1) == 0)
	// 	printf("Letter pl -> %s\n", line);
	// if (ft_strncmp(tokens[0], "cy", 1) == 0)
	// 	printf("Letter cy -> %s\n", line);
	return (0);
}

int	read_file(char *filename)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	while(42)
	{
		line = gnl(fd);
		if (!line)
			return (0);
		identifier(line);
	}
	return (0);
}
