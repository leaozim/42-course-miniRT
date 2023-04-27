#include "minirt.h"

static int	identifier(char *line, t_bool reqred_obj[])
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (ft_free_array(tokens), 0);
	if (is_invalid_file_data(tokens))
		return (error_msg(ERROR_FILE), ft_free_array(tokens), ERROR);
	if (ft_strcmp(tokens[0], _AMBIENT_) == 0 && reqred_obj[AMBIENT] == FALSE)
		return (check_id_a(tokens, reqred_obj));
	else if (ft_strcmp(tokens[0], _CAMERA_) == 0 && reqred_obj[CAMERA] == FALSE)
		return (check_id_c(tokens, reqred_obj));
	else if (ft_strcmp(tokens[0], _LIGHT_) == 0)
		return (check_id_l(tokens, reqred_obj));
	else if (ft_strcmp(tokens[0], _SPHERE_) == 0)
		return (check_id_sp(tokens));
	else if (ft_strcmp(tokens[0], _PLANE_) == 0)
		return (check_id_pl(tokens));
	else if (ft_strcmp(tokens[0], _CYLINDER_) == 0)
		return (check_id_cy(tokens));
	return (ft_free_array(tokens), error_msg(ERROR_FILE), ERROR);
}

int	check_file(char *filename)
{
	char	*line;
	int		fd;
	t_bool	required_obj[10];

	required_obj[CAMERA] = FALSE;
	required_obj[LIGHT] = FALSE;
	required_obj[AMBIENT] = FALSE;
	fd = check_open_file(filename);
	if (fd == ERROR)
		return (close(fd), ERROR);
	while (42)
	{
		line = gnl(fd);
		if (!line)
			break ;
		replace_char(line, ' ');
		if (identifier(line, required_obj) == ERROR)
			return (close(fd), free(line), ERROR);
		free(line);
	}
	close (fd);
	return (check_qtd_elemments(required_obj));
}
