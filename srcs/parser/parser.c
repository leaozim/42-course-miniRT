# include "minirt.h"

static int identifier(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if(!tokens)
		return (0);
	if (ft_strncmp(tokens[0], "A", 1) == 0)
		printf("check_id_a %s\n", line);
	if (ft_strncmp(tokens[0], "C", 1) == 0)
		printf("Letter C -> %s\n", line);
	if (ft_strncmp(tokens[0], "L", 1) == 0)
		printf("Letter L -> %s\n", line);
	if (ft_strncmp(tokens[0], "sp", 1) == 0)
		printf("Letter sp -> %s\n", line);
	if (ft_strncmp(tokens[0], "pl", 1) == 0)
		printf("Letter pl -> %s\n", line);
	if (ft_strncmp(tokens[0], "cy", 1) == 0)
		printf("Letter cy -> %s\n", line);
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
