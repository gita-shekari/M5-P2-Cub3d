#include "cub3d.h"

// x' = px + t * raydir_x;
// y' = py + t * raydir_x;
// t is the distane of px to the next point of x'

static double	cal_unit_dist(t_ray ray, char dir)
{
	if (dir == 'x')
	{
		if (ray.dirx == 0.0)
			return (1e30);
		else
			return (fabs(1 / ray.dirx));
	}
	else
	{
		if (ray.diry == 0.0)
			return (1e30);
		else
			return (fabs(1 / ray.diry));
	}
}

static void	init_dda(t_dda *dda, t_env *env, t_ray ray)
{
	dda->mapx = (int)env->player.x;
	dda->mapy = (int)env->player.y;

	if (ray.dirx < 0)
	{
		dda->stepx = -1;
		dda->distx = (env->player.x - dda->mapx) * cal_unit_dist(ray, 'x');
	}
	else
	{
		dda->stepx = 1;
		dda->distx = (dda->mapx + 1.0 - env->player.x) * cal_unit_dist(ray, 'x');
	}
	if (ray.diry < 0)
	{
		dda->stepy = -1;
		dda->disty = (env->player.y - dda->mapy) * cal_unit_dist(ray, 'y');
	}
	else
	{
		dda->stepy = 1;
		dda->disty = (dda->mapy + 1.0 - env->player.y) * cal_unit_dist(ray, 'y');
	}
}

static int	find_hit_side(t_dda *dda, t_ray ray, t_env *env)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (dda->distx < dda->disty)
		{
			dda->distx += cal_unit_dist(ray, 'x');
			dda->mapx += dda->stepx;
			side = 0;
		}
		else
		{
			dda->disty += cal_unit_dist(ray, 'y');
			dda->mapy += dda->stepy;
			side = 1;
		}
		if (env->map.grid[dda->mapy][dda->mapx] == '1')
			hit = 1;
	}
	return (side);
}

void	ft_run_dda(t_env *env)
{
	t_ray	ray;
	int		x;
	int		side;
	t_dda	dda;

	x = 0;
	while (x < WIDTH)
	{
		//printf("planex = %f, planey = %f\n", env->player.planex, env->player.planey);
		cal_ray_dir(&ray, env->player, x);
		//printf("rayx = %f rayy = %f\n", ray.dirx, ray.diry);
		init_dda(&dda, env, ray);
		side = find_hit_side(&dda, ray, env);
		cal_ray_hit(env, &ray, dda, side);
		draw_col(x, ray, env);
		x++;
	}
}
