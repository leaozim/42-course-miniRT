#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include "../libs/libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "defines.h"
# include <fcntl.h>

void	error_msg(char *msg);
int		check_argc(int argc);
int		check_file(char *file);
int		read_file(char *filename);
int		check_id_c(char **tokens);
int		is_invalid_file_data(char **tokens);
int		check_orientation(char *tokens);

#endif
