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

static int	identifier(char *line, t_bool is_duplicated[])
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (ft_free_array(tokens), 0);
	if (is_invalid_file_data(tokens))
		return (error_msg(ERROR_FILE), ft_free_array(tokens), ERROR);
	if (ft_strcmp(tokens[0], "A") == 0 && is_duplicated[AMBIENT] == FALSE)
		return (check_id_a(tokens, is_duplicated));
	else if (ft_strcmp(tokens[0], "C") == 0 && is_duplicated[CAMERA] == FALSE)
		return (check_id_c(tokens, is_duplicated));
	else if (ft_strcmp(tokens[0], "L") == 0 && is_duplicated[LIGHT] == FALSE)
		return (check_id_l(tokens, is_duplicated));
	else if (ft_strcmp(tokens[0], "sp") == 0)
		return (check_id_sp(tokens));
	else if (ft_strcmp(tokens[0], "pl") == 0)
		return (check_id_pl(tokens));
	else if (ft_strcmp(tokens[0], "cy") == 0)
		return (check_id_cy(tokens));
	else if (tokens[0][0] == '#')
		return (ft_free_array(tokens), OK);
	return (ft_free_array(tokens), error_msg(ERROR_FILE), ERROR);
}

int	check_file(char *filename)
{
	char	*line;
	int		fd;
	t_bool	is_duplicated[10];

	is_duplicated[CAMERA] = FALSE;
	is_duplicated[LIGHT] = FALSE;
	is_duplicated[AMBIENT] = FALSE;
	fd = check_open_file(filename);
	if (fd == ERROR)
		return (ERROR);
	while (42)
	{
		line = gnl(fd);
		if (!line)
			return (close(fd), free(line), OK);
		replace_char(line, ' ');
		if (identifier(line, is_duplicated) == ERROR)
			return (close(fd), free(line), ERROR);
		// if (check_elements_count(line) == ERROR)
		// 	return (close(fd), free(line), ERROR);
		free(line);
	}
	close (fd);
	return (OK);
}
