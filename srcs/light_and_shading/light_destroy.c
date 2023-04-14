#include "minirt.h"

void	destroy_light_point(void *light_p)
{
	t_light_pnt	*lp;

	lp = (t_light_pnt *)light_p;
	free(lp);
}