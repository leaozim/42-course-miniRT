/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <larissa_silva@outlook.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:24:14 by marcrodr          #+#    #+#             */
/*   Updated: 2023/03/17 17:03:49 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isfloat(char *str)
{
	int		dot;
	size_t	len;
	char	*aux;

	len = ft_strlen(str);
	dot = 0;
	if (len == 0)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0' || !ft_isdigit(*str))
		return (0);
	aux = str;
	while (*aux)
	{
		if (*aux == '.')
		{
			if (++dot > 1)
				return (0);
		}			
		else if (!ft_isdigit(*aux))
			return (0);
		aux++;
	}
	return (1);
}