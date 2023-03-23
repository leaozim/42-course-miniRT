#include "minirt.h"

void	replace_char(char *str, int value_substituted)
{
	size_t	i;

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
		while (tokens[i][j] != '\0')
		{
			if (!ft_isdigit(tokens[i][j]) && tokens[i][j] != '.'
				&& tokens[i][j] != ',' && tokens[i][j] != '-')
				return (ERROR);
			j++;
		}
	}
	return (OK);
}

static int	identifier(char *line)
{
	char	**tokens;

	replace_char(line, ' ');
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (ft_free_array(tokens), 0);
	if (is_invalid_file_data(tokens))
		return (error_msg(ERROR_FILE), ft_free_array(tokens), ERROR);
	if (ft_strcmp(tokens[0], "A") == 0)
		return (check_id_a(tokens));
	else if (ft_strcmp(tokens[0], "C") == 0)
		return (check_id_c(tokens));
	else if (ft_strcmp(tokens[0], "L") == 0)
		return (check_id_l(tokens));
	else if (ft_strcmp(tokens[0], "sp") == 0)
		return (check_id_sp(tokens));
	else if (ft_strcmp(tokens[0], "pl") == 0)
		return (check_id_pl(tokens));
	else if (ft_strcmp(tokens[0], "cy") == 0)
		return (check_id_cy(tokens));
	else if (tokens[0][0] == '#')
		return (ft_free_array(tokens), OK);
	ft_free_array(tokens);
	return (error_msg(ERROR_FILE), ERROR);
}

int	open_file(char *file)
{
	int	len_file;
	int	fd;

	len_file = ft_strlen(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (close(fd), ft_putstr_fd("Error: ", 2), perror(file), ERROR);
	if (ft_strcmp(&file[len_file - 3], ".rt") || len_file == 3)
		return (close(fd), error_msg(ERROR_FORMAT), ERROR);
	return (fd);
}

int	check_file(char *filename)
{
	char	*line;
	int		fd;

	fd = open_file(filename);
	if (fd == ERROR)
		return (ERROR);
	while (42)
	{
		line = gnl(fd);
		if (!line)
			return (0);
		if (identifier(line) == ERROR)
			return (close(fd), free(line), ERROR);
		free(line);
	}
	close (fd);
	return (OK);
}
