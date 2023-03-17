/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:37:43 by marcrodr          #+#    #+#             */
/*   Updated: 2023/03/17 15:37:58 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isrange(double value, double min, double max)
{
	if (value >= min && value <= max)
		return (0);
	return (1);
}
