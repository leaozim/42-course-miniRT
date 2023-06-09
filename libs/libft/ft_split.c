/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <larissa_silva@outlook.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:54:32 by lade-lim          #+#    #+#             */
/*   Updated: 2023/03/20 12:35:30 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char const *s, char c)
{
	size_t	found_word;
	size_t	words;

	words = 0;
	found_word = 0;
	while (*s)
	{
		if (*s != c && found_word == 0)
		{
			found_word = 1;
			words++;
		}
		else if (*s == c)
			found_word = 0;
		s++;
	}			
	return (words);
}

static char	**build_array(char **array_str, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	index_list;

	i = -1;
	start = 0;
	index_list = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
		{
			if (start != i)
				array_str[index_list++] = ft_substr(s, start, i - start);
			start = i + 1;
		}
	}
	if (i > 0 && s[i - 1] != c)
		array_str[index_list++] = ft_substr(s, start, i - start);
	array_str[index_list] = NULL;
	return (array_str);
}

char	**ft_split(char const *s, char c)
{
	char	**array_str;
	int		words_size;

	if (!s || (*s == c && ft_strlen(s) == 1))
		return (NULL);
	words_size = words_count(s, c);
	if (words_size == 0)
		return (NULL);
	array_str = malloc((words_size + 1) * sizeof(char *));
	if (!array_str)
		return (NULL);
	array_str = build_array(array_str, s, c);
	return (array_str);
}
