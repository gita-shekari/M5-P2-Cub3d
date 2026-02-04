#include <math.h>
#include "try.h"

typedef struct	s_ray
{
	double x;
	double y;
}				t_ray;

void	dda(t_env *env, t_ray *ray)
{
	t_p	  player;

	player = *(env->player);

	int	mapx;
	int	mapy;
	mapx = (int)player.x;
	mapy = (int)player.y;

	double	dx = fabs(1 / ray->x);
	double	dy = fabs(1 / ray->y);
	double	sidex;
	double	sidey;
	int		side;
	int		stepx;
	int		stepy;
	
	if (ray->x < 0)
	{
		stepx = -1;
		sidex = (player.x - mapx) * dx;
	}
	else
	{
		stepx = 1;
		sidex = (mapx + 1.0 - player.x) * dx;
	}
	if (ray->y < 0)
	{
		stepy = -1;
		sidey = (player.y - mapy) * dy;
	}
	else
	{
		stepy = 1;
		sidey = (mapy + 1.0 - player.y) * dy;
	}
	int hit = 0;
	while (hit == 0)
	{
		if (sidex < sidey)
		{
			sidex += dx;
			mapx += stepx;
			side = 0;
		}
		else
		{
			sidey += dy;
			mapy += stepy;
			side = 1;
		}
		if (env->grid[mapx][mapy] == '1')
			hit = 1;
	}
	double wall_dist;
	if (side == 0)
		wall_dist = (mapx - player.x + (1 - stepx) / 2) / ray->x;
	else
		wall_dist = (mapy - player.y + (1 - stepy) / 2) / ray->y;
}