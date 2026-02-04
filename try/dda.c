#include <math.h>
#include "try.h"

typedef struct	s_ray
{
	double x;
	double y;
}				t_ray;

// x' = px + t * raydir_x;
// y' = py + t * raydir_x;
// t is the distane of px to the next point of x'


double	dda(t_env *env, t_ray *ray)
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
	return (wall_dist);
}
/**
 * ray.x = dirx + planex * camera_x;
 * originally plane = tan(FOV / 2) FOV is angle, e.g. 60;
 * plane is verticle to the player.dir;
 * camerax = 2 * x / WIDTH - 1; => normalize from [0, WIDTH] to [-1, 1];
 */
//
static int camera(double x)
{
	return (2 * x / WIDTH - 1);
}

void	ft_run_dda(t_env *env)
{
	t_p	  player;
	t_ray ray;
	double	dist;
	int	x;
	int y;

	x = 0;
	player = *(env->player);
	while (x < WIDTH)
	{
		ray.x = player.planex * camera(x) + player.dirx;
		ray.y = player.planey * camera(x) + player.diry;
		dist = dda(env, &ray);

		int	y = start;
		while (y < end )
		{
			draw_texture_pixel();
			y++;
		}
		x++;
	}
}