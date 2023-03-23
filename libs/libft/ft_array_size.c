/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <larissa_silva@outlook.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:38:50 by lade-lim          #+#    #+#             */
/*   Updated: 2023/03/23 16:26:00 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_array_size(char **array)
{
	size_t	size;

	size = 0;
	if (!array || !*array)
		return (0);
	while (array[size])
		size++;
	return (size);
}
