#include "minirt.h"

int	check_rgb(int red, int green, int blue)
{
	if (ft_isrange(red, 0, 255)
		|| ft_isrange(green, 0, 255)
		|| ft_isrange(blue, 0, 255))
		return (error_msg("Incorrect range of RGB [0-255]"), ERROR);
	return (0);
}

int	check_color(char *tokens, t_scene *scene)
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
	scene->ambient->color = set_color(r, g, b);
	ft_free_array(rgb);
	return (0);
}
