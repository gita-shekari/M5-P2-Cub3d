/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdong <jdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/18 14:53:44 by jdong         #+#    #+#                 */
/*   Updated: 2026/02/20 18:16:13 by jdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/**
 * ray.x = dirx + planex * camera_x (linear interpolation);
 * originally plane = tan(FOV / 2) FOV is angle, e.g. 60;
 * plane is verticle to the player.dir;
 * camerax = 2 * x / WIDTH - 1; => normalize from [0, WIDTH] to [-1, 1];
 */
//

/**
 * Be aware of the direction. North < 0, because we want to make
 * the grid as the way it is being drawed and when going down to
 * south, the y is being added. */
static t_side	check_wall(int side, t_ray ray)
{
	if (side == 0)
	{
		if (ray.dirx > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray.diry > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

void	cal_ray_dir(t_ray *ray, t_p player, int x)
{
	double	plane_position;

	plane_position = (double)x * 2 / WIDTH - 1;
	ray->dirx = player.dirx + player.planex * plane_position;
	ray->diry = player.diry + player.planey * plane_position;
}

/** p(x) = x + t * dx
 * p(y) = y + t *dy
 * t = p(x) - x / d
 */

void	cal_ray_hit(t_env *env, t_ray *ray, t_dda dda, int side)
{
	t_p		player;

	player = env->player;
	if (side == 0)
	{
		ray->perp_dist = (dda.mapx - player.x
				+ (1 - dda.stepx) / 2) / ray->dirx;
		ray->wall_x = player.y + ray->perp_dist * ray->diry;
	}
	else
	{
		ray->perp_dist = (dda.mapy - player.y
				+ (1 - dda.stepy) / 2) / ray->diry;
		ray->wall_x = player.x + ray->perp_dist * ray->dirx;
	}
	ray->wall_x -= floor(ray->wall_x);
	ray->side = check_wall(side, *ray);
	ray->wall_height = (int)(HEIGHT / ray->perp_dist);
	ray->wall_top = HEIGHT / 2 - ray->wall_height / 2;
}
