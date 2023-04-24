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

int	check_qtd_elemments(t_bool is_duplicated[])
{
	if (is_duplicated[AMBIENT] == FALSE
		|| is_duplicated[CAMERA] == FALSE
		|| is_duplicated[LIGHT] == FALSE)
		return (error_msg(ERROR_QTT_), ERROR);
	return (OK);
}
