#include <math.h>
#include "try.h"

/** 
 * Be aware of the direction. North < 0, because we want to make the grid as the way it is being drawed and when going down to south, the y is being added. */
t_dir	check_side(int side, t_env	*env)
{
	if (side == 0)
	{
		if (env->player.dirx > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (env->player.diry > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}
// x' = px + t * raydir_x;
// y' = py + t * raydir_x;
// t is the distane of px to the next point of x'


void	dda(t_env *env, t_ray *ray, t_hit *p)
{
	t_p	  player;
	int	mapx;
	int	mapy;
	double sidex;
	double sidey;
	int		side;
	int		stepx;
	int		stepy;

	player = env->player;
	mapx = (int)player.x;
	mapy = (int)player.y;
	if (ray->x < 0)
	{
		stepx = -1;
		sidex = (player.x - (double)mapx) * fabs(1 / ray->x);
	}
	else
	{
		stepx = 1;
		sidex = ((double)mapx + 1.0 - player.x) * fabs(1 / ray->x);
	}
	if (ray->y < 0)
	{
		stepy = -1;
		sidey = (player.y - (double)mapy) * fabs(1 / ray->y);
	}
	else
	{
		stepy = 1;
		sidey = ((double)mapy + 1.0 - player.y) * fabs(1 / ray->y);
	}
	int hit = 0;
	while (hit == 0)
	{
		if (sidex < sidey)
		{
			sidex += fabs(1 / ray->x);
			mapx += stepx;
			side = 0;
		}
		else
		{
			sidey += fabs(1 / ray->y);
			mapy += stepy;
			side = 1;
		}
		if (env->grid[mapy][mapx] == '1')
			hit = 1;
	}
	if (side == 0)
	{
		p->perp_dist = ((double)mapx - player.x + (1 - stepx) / 2) / ray->x;
		p->wall_x = player.x + p->perp_dist * ray->y;
	}
	else
	{
		p->perp_dist = ((double)mapy - player.y + (1 - stepy) / 2) / ray->y;
		p->wall_x = player.x + p->perp_dist * ray->x;
	}
	p->wall_x -= floor(p->wall_x);
	p->side = check_side(side, env);
	p->wall_height = (int)(HEIGHT / p->perp_dist);
	p->wall_top = HEIGHT / 2 - p->wall_height / 2;
}
/**
 * ray.x = dirx + planex * camera_x (linear interpolation);
 * originally plane = tan(FOV / 2) FOV is angle, e.g. 60;
 * plane is verticle to the player.dir;
 * camerax = 2 * x / WIDTH - 1; => normalize from [0, WIDTH] to [-1, 1];
 */
//
static double camera(double x)
{
	return (2 * x / WIDTH - 1);
}

void	ft_run_dda(t_env *env)
{
	t_ray ray;
	int	x;
	int y;
	t_hit	hit;

	x = 0;		
	//double pov = (FOV * M_PI / 180) / WIDTH;
	//double angle = env->player->angle - (FOV * M_PI / 360);
	while (x < WIDTH)
	{
		//===== World Calulation =======
		printf("planex = %f, planey = %f\n", env->player.planex, env->player.planey);
		ray.x = env->player.planex * camera((double)x) + env->player.dirx;
		ray.y = env->player.planey * camera((double)x) + env->player.diry;

		//ray.x = cos(angle);
		//ray.y = sin(angle);
		//angle += pov;
		printf("rayx = %f rayy = %f\n", ray.x, ray.y);
		dda(env, &ray, &hit);

		//====== Casting Calulation ======
		int start = 0;
		if (hit.wall_top > 0)
			start = hit.wall_top;
		int	end = HEIGHT / 2 + hit.wall_height / 2;
		if (end >= HEIGHT)
			end = HEIGHT - 1;
		y = 0;
		while (y < start)
		{
			tmp_put_color(env, x, y, 'c');
			//draw_ceiling(env, x, y);
			y++;
		}
		draw_texture(start, end, &hit, env, x);
		y = end + 1;
		printf("before put color for floor\n");
		while (y < HEIGHT)
		{
			tmp_put_color(env, x, y, 'f');
			//draw_floor(env, x, y);
			y++;
		}
		x++;
	}
}