/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <larissa_silva@outlook.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:57:50 by marcrodr          #+#    #+#             */
/*   Updated: 2023/04/25 12:54:31 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_normalize(char *token)
{
	char	**aux;
	double	x;
	double	y;
	double	z;

	aux = ft_split(token, ',');
	x = ft_atof(aux[0]);
	y = ft_atof(aux[1]);
	z = ft_atof(aux[2]);
	ft_free_array(aux);
	if (x <= 0 && y <= 0 && z <= 0)
		return (1);
	return(0);
}
