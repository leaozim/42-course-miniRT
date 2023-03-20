/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <larissa_silva@outlook.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:02:59 by lade-lim          #+#    #+#             */
/*   Updated: 2023/03/20 11:04:16 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	int		sign;
	double	result;
	double	decimal;

	sign = 1;
	result = 0;
	decimal = 0.1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str++))
		result *= 10 + (*str - '0');
	while (ft_isdigit(*str))
	{
		result += (*str++ - '0') * decimal;
		decimal /= 10;
	}
	return (result * sign);
}
