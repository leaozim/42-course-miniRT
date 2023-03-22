#include "minirt.h"

int	fill_coordinates(char *token, t_scene *scene)
{
	char	**xyz;
	(void)scene;
	xyz = ft_split(token, ',');
	if (!xyz || ft_array_size(xyz) != 3)
		return(ft_free_array(xyz), error_msg("erro"), ERROR);
	if (!ft_isfloat(xyz[0]) || !ft_isfloat(xyz[1]) || !ft_isfloat(xyz[2]))
		return (ft_free_array(xyz), error_msg("xyz needs to be float"), ERROR);
	
	
	return (0);
}

int parser_light(char **tokens)
{
	if (ft_array_size(tokens) != 3)
		return (error_msg("To many or few arguments for Light!"), ERROR);
	else if (check_coordinates(tokens[1]))
		return (error_msg("Light orientation are invalid!"), ERROR);
	else if (!ft_isfloat(tokens[2]))
		return (error_msg("Light brightness needs to be a Float"), ERROR);
	if (ft_isrange(ft_atof(tokens[2]), 0, 1))
		return (error_msg("Invalid brightness"), ERROR);
	return (0);
}
