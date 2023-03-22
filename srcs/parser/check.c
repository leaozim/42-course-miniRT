#include "minirt.h"

int	check_rgb(int red, int green, int blue)
{
	if (ft_isrange(red, 0, 255)
		|| ft_isrange(green, 0, 255)
		|| ft_isrange(blue, 0, 255))
		return (error_msg("Incorrect range of RGB [0-255]"), ERROR);
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
	{
		ft_free_array(rgb);
		return (error_msg("Invalid RGB"), ERROR);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);		
	if (check_rgb(r, g, b))
		return (ERROR);
	ft_free_array(rgb);
	return (0);
}

int check_orientation(char *tokens)
{
	char	**orientation;
	int		i;

	i = 0;
	orientation = ft_split(tokens, ',');
	if (!orientation)
		return (0);
	while (orientation[i])
	{
		if (ft_isrange(ft_atoi(orientation[i]), -1, 1) || i > 2)
			return (ERROR);
		i++;
	}
	free(orientation);
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
		return (free(coordinates), ERROR);
	while (coordinates[i])
	{
		if (!ft_isfloat(coordinates[i]))
			return (free(coordinates), ERROR);
		i++;
	}
	free(coordinates);
	return (OK);
}
