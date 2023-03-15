/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:00:44 by lade-lim          #+#    #+#             */
/*   Updated: 2023/03/10 12:51:36 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{	
	t_list	*aux;

	if (*lst == NULL)
		*lst = new_lst;
	else
	{
		aux = ft_lstlast(*lst);
		aux->next = new_lst;
	}
}
