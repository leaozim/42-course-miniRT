# include "minirt.h"

int	check_rgb(char *red, char *green, char *blue)
{
	int	r;
	int	g;
	int	b;

	if (!ft_isdigit(*red) || !ft_isdigit(*green) || !ft_isdigit(*blue))
		return (error_msg("RGB needs to be a positive number"), ERROR);
	r = ft_atoi(red);
	g = ft_atoi(green);
	b = ft_atoi(blue);
	if (ft_isrange(r, 0, 255)
		|| ft_isrange(g, 0, 255)
		|| ft_isrange(b, 0, 255))
		return (error_msg("Incorrect range of RGB [0-255]"), ERROR);
	return (0);
}

int	check_color(char *tokens)
{
	char	**rgb;

	rgb = ft_split(tokens, ',');
	if (ft_array_size(rgb) != 3)
	{
		ft_free_array(rgb);
		return (error_msg("Invalid RGB"), ERROR);
	}	
	check_rgb(rgb[0], rgb[1], rgb[2]);
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