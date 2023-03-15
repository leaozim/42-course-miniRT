/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:46 by marcrodr          #+#    #+#             */
/*   Updated: 2023/03/15 17:57:22 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int parse_file(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if(!tokens)
		return (0);
	if (ft_strncmp(tokens[0], "A", 1) == 0)
		printf("Letter A -> %s\n", line);
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
	//	printf("%s", line);
		parse_file(line);
	}
	return (0);
}