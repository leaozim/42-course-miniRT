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

// void	replace_value_inside_quotes(char *list, int old_vle, int new_vle)
// {
// 	char	*str;
// 	int		quotes;
// 	int		i;

// 	i = 0;
// 	str = list;
// 	quotes = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == SQUOTE || str[i] == DQUOTES)
// 		{
// 			quotes = str[i];
// 			i++;
// 			while (str[i] && str[i] != quotes)
// 			{
// 				if (str[i] == old_vle)
// 					str[i] = new_vle;
// 				i++;
// 			}
// 			i++;
// 		}
// 		while (str[i] && str[i] != SQUOTE && str[i] != DQUOTES)
// 			i++;
// 	}
// }

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

int	check_id_c(char **tokens)
{
	
	if (ft_array_size(tokens) != 4)
		return (error_msg("to many or few arguments for camera"), ERROR);
	if (is_invalid_file_data(tokens))
		return (error_msg("file data are invaded"), ERROR);

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
	// int status = 0;

	replace_char(line, ' ');
	tokens = ft_split(line, ' ');
	if(!tokens)
		return (0);
	// if (ft_strncmp(tokens[0], "A", 1) == 0)
	// 	printf("check_id_a %s\n", line);
	if (ft_strncmp(tokens[0], "C", 1) == 0)
	{
		return(check_id_c(tokens));
	}

	// if (ft_strncmp(tokens[0], "L", 1) == 0)
	// 	printf("Letter L -> %s\n", line);
	// if (ft_strncmp(tokens[0], "sp", 1) == 0)
	// 	printf("Letter sp -> %s\n", line);
	// if (ft_strncmp(tokens[0], "pl", 1) == 0)
	// 	printf("Letter pl -> %s\n", line);
	// if (ft_strncmp(tokens[0], "cy", 1) == 0)
	// 	printf("Letter cy -> %s\n", line);
	// if (status == OK)
	// 	return (OK);
	return (OK);
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
		if (identifier(line) == ERROR)
			return(ERROR);
	}
	close (fd);
	return (OK);
}
