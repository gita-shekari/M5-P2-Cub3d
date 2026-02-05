#include <math.h>
#include "try.h"

typedef enum	e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	DEF
}				t_dir;


typedef struct	s_ray
{
	double x;
	double y;
}				t_ray;

typedef struct	s_hit
{
	double	perp_dist;
	t_dir	side;		//side = 0; vertical wall on the west or east
}				t_hit;


t_dir	check_side(int side, t_env	*env)
{
	if (side == 0 && env->player->dirx > 0)
		return (EAST);
	else if (side == 0 && env->player->dirx <= 0)
		return (WEST);
	else if (side == 1 && env->player->diry > 0)
		return (SOUTH);
	else if (side == 1 && env->player->diry <= 0)
		return (NORTH);
	else
		return (DEF);
}
// x' = px + t * raydir_x;
// y' = py + t * raydir_x;
// t is the distane of px to the next point of x'


t_hit	*dda(t_env *env, t_ray *ray)
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
	t_hit	*p;

	p = NULL;
	if (side == 0)
	{
		p->perp_dist = (mapx - player.x + (1 - stepx) / 2) / ray->x;
	}
	else
	{
		p->perp_dist = (mapy - player.y + (1 - stepy) / 2) / ray->y;
	}
	p->side = check_side(side, env);
	return (p);
}
/**
 * ray.x = dirx + planex * camera_x (linear interpolation);
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
	t_ray ray;
	int	x;
	int y;
	t_hit	*hit;

	x = 0;
	while (x < WIDTH)
	{
		ray.x = env->player->planex * camera(x) + env->player->dirx;
		ray.y = env->player->planey * camera(x) + env->player->diry;
		hit = dda(env, &ray);

		int	line_height = (int)(HEIGHT / hit->perp_dist);
		int	start = HEIGHT / 2 - line_height / 2;
		if (start < 0)
			start = 0;
		int	end = HEIGHT / 2 + line_height / 2;
		if (end >= HEIGHT)
			end = HEIGHT - 1;
		y = 0;
		while (y < start)
		{
			tmp_put_color(env, x, y, 'c');
			//draw_ceiling(env, x, y);
			y++;
		}
		y = start;
		while (y < end)
		{
			tmp_put_color(env, x, y, 't');
			//draw_textures(env, x, y, hit->side);
			y++;
		}
		while (y < HEIGHT)
		{
			tmp_put_color(env, x, y, 'f');
			//draw_floor(env, x, y);
			y++;
		}
		x++;
	}
}