/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <larissa_silva@outlook.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:02:59 by lade-lim          #+#    #+#             */
/*   Updated: 2023/04/24 14:06:02 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	get_result(const char *str, int sign)
{
	double	decimal;
	double	result;

	decimal = 0.1;
	result = 0.0;
	while (ft_isdigit(*str))
	{
		result = (result * 10.0) + (*str - '0');
		str++;
	}
	if (*str++ != '.')
		return (sign * result);
	while (ft_isdigit(*str))
	{
		result += (*str++ - '0') * decimal;
		decimal /= 10;
	}
	return (result * sign);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	result;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = get_result(str, sign);
	return (result);
}
