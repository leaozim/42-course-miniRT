#include "minirt.h"

void	error_msg(char *msg)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putendl_fd(msg, 2);
}
