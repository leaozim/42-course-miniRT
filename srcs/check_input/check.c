#include "minirt.h"

int	check_rgb(int red, int green, int blue)
{
	if (ft_isrange(red, 0, 255)
		|| ft_isrange(green, 0, 255)
		|| ft_isrange(blue, 0, 255))
		return (error_msg(ERROR_RANGE_COLOR), ERROR);
	return (0);
}

int	check_color(char *tokens)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(tokens, ',');
	if (ft_array_size(rgb) != 3)
		return (error_msg(ERROR_INVALID_RGB), ft_free_array(rgb), ERROR);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (check_rgb(r, g, b))
		return (ft_free_array(rgb), ERROR);
	ft_free_array(rgb);
	return (0);
}

int	check_orientation(char *tokens)
{
	char	**orientation;
	int		i;
	int		size;

	i = 0;
	orientation = ft_split(tokens, ',');
	if (!orientation)
		return (0);
	size = ft_array_size(orientation);
	if (size != 3)
		return (ft_free_array(orientation), ERROR);
	while (orientation[i])
	{
		if (ft_isrange(ft_atof(orientation[i]), -1, 1))
			return (ft_free_array(orientation), error_msg(ERROR_RANGE), ERROR);
		else if (!ft_isfloat(orientation[i]))
			return (ft_free_array(orientation), error_msg(ERROR_FLOAT), ERROR);
		i++;
	}
	ft_free_array(orientation);
	return (0);
}

int	check_coordinates(char *tokens)
{
	char	**coordinates;
	int		i;
	int		size;

	i = 0;
	coordinates = ft_split(tokens, ',');
	if (!coordinates)
		return (ERROR);
	size = ft_array_size(coordinates);
	if (size != 3)
		return (ft_free_array(coordinates), ERROR);
	while (coordinates[i])
	{
		if (!ft_isfloat(coordinates[i]))
			return (ft_free_array(coordinates), ERROR);
		i++;
	}
	ft_free_array(coordinates);
	return (OK);
}

int	check_open_file(char *file)
{
	int	len_file;
	int	fd;

	len_file = ft_strlen(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\n", 2), perror(file), ERROR);
	else if (ft_strcmp(&file[len_file - 3], ".rt") || len_file == 3)
		return (error_msg(ERROR_FORMAT), ERROR);
	return (fd);
}
