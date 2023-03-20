/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <larissa_silva@outlook.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:37:43 by marcrodr          #+#    #+#             */
/*   Updated: 2023/03/17 17:00:43 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isrange(double value, double min, double max)
{
	if (value >= min && value <= max)
		return (0);
	return (1);
}
