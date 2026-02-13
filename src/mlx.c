#include "cub3d.h"

void	player_move_forward(t_env *env)
{
	double newX;
	double newY;

	newX = env->player.x + env->player.dirx;
	newY = env->player.y + env->player.diry;
	if (env->map.grid[(int)newY][(int)newX] == '0')
	{
		env->player.x = newX;
		env->player.y = newY;
		env->draw = 1;
	}
}

void	player_move_back(t_env *env)
{
	double newX;
	double newY;
	
	newX = env->player.x - env->player.dirx;
	newY = env->player.y - env->player.diry;
	if (env->map.grid[(int)newY][(int)newX] == '0')
	{
		env->player.x = newX;
		env->player.y = newY;
		env->draw = 1;
	}
}

void	player_move_right(t_env *env)
{
	double newX;
	double newY;

	newX = env->player.x - env->player.diry;
	newY = env->player.y + env->player.dirx;
	if (env->map.grid[(int)newY][(int)newX] == '0')
	{
		env->player.x = newX;
		env->player.y = newY;
		env->draw = 1;
	}
}

void	player_move_left(t_env *env)
{
	double newX;
	double newY;
	
	newX = env->player.x + env->player.diry;
	newY = env->player.y - env->player.dirx;
	if (env->map.grid[(int)newY][(int)newX] == '0')
	{
		env->player.x = newX;
		env->player.y = newY;
		env->draw = 1;
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
	env->draw = 1;
}
