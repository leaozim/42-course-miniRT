# include "minirt.h"

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

int	is_invalid_file_data(char **tokens)
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
					&& tokens[i][j] != ',' && tokens[i][j] != '-')
				return (ERROR);
			j++;
		}
	}
	return (OK);
}

void	print_array(char **str)
{
	int i = 0;

	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

static int identifier(char *line)
{
	char	**tokens;

	replace_char(line, ' ');
	tokens = ft_split(line, ' ');
	if(!tokens)
		return (0);
	if (ft_strcmp(tokens[0], "A") == 0)
		return(OK);
	else if (ft_strcmp(tokens[0], "C") == 0)
		return(check_id_c(tokens));
	else if (ft_strcmp(tokens[0], "L") == 0)
		return(OK);
	else if (ft_strcmp(tokens[0], "sp") == 0)
		return(check_id_sp(tokens));
	else if (ft_strcmp(tokens[0], "pl") == 0)
		return(OK);
	else if (ft_strcmp(tokens[0], "cy") == 0)
		return(OK);
	else if (tokens[0][0] == '#')
		return(OK);
	ft_free_array(tokens);
	return (error_msg("file data are invaded"), ERROR);
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
			return (ERROR);
		if (identifier(line) == 1)
			return(ERROR);
		free(line);
	}
	close (fd);
	return (OK);
}
