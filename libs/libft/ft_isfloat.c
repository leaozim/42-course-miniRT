/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:24:14 by marcrodr          #+#    #+#             */
/*   Updated: 2023/03/17 11:58:49 by marcrodr         ###   ########.fr       */
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
