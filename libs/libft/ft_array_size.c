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