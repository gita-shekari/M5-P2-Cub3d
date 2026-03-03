/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshekari <gshekari@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/18 14:54:03 by jdong         #+#    #+#                 */
/*   Updated: 2026/02/20 17:49:10 by jdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move_forward(t_env *env)
{
	double	newx;
	double	newy;
	double	value;

	value = 0.2;
	newx = env->player.x + env->player.dirx * value;
	newy = env->player.y + env->player.diry * value;
	if (env->map.grid[(int)newy][(int)newx] == '0')
	{
		env->player.x = newx;
		env->player.y = newy;
	}
}

void	player_move_back(t_env *env)
{
	double	newx;
	double	newy;
	double	value;

	value = 0.2;
	newx = env->player.x - env->player.dirx * value;
	newy = env->player.y - env->player.diry * value;
	if (env->map.grid[(int)newy][(int)newx] == '0')
	{
		env->player.x = newx;
		env->player.y = newy;
	}
}

void	player_move_right(t_env *env)
{
	double	newx;
	double	newy;
	double	value;

	value = 0.2;
	newx = env->player.x - env->player.diry * value;
	newy = env->player.y + env->player.dirx * value;
	if (env->map.grid[(int)newy][(int)newx] == '0')
	{
		env->player.x = newx;
		env->player.y = newy;
	}
}

void	player_move_left(t_env *env)
{
	double	newx;
	double	newy;
	double	value;

	value = 0.2;
	newx = env->player.x + env->player.diry * value;
	newy = env->player.y - env->player.dirx * value;
	if (env->map.grid[(int)newy][(int)newx] == '0')
	{
		env->player.x = newx;
		env->player.y = newy;
	}
}

void	rotate(mlx_key_data_t key, t_env *env)
{
	double	temp;

	temp = env->player.dirx;
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
	{
		env->player.dirx = (-1) * env->player.diry;
		env->player.diry = temp;
	}
	if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
	{
		if (env->player.dirx == 0)
		{
			env->player.dirx = env->player.diry;
			env->player.diry = temp;
		}
		else if (env->player.diry == 0)
		{
			env->player.dirx = env->player.diry;
			env->player.diry = (-1) * temp;
		}
	}
	set_player_plane(&(env->player));
}
