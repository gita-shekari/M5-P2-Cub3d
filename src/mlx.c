#include "cub3d.h"


int player_move_forward(t_env *env)
{
	double newX = env->player.x + env->player.dirx;
	double newY = env->player.y + env->player.diry;

	if (env->map.grid[(int)newY][(int)newX] == '0')
	{
		env->player.x = newX;
		env->player.y = newY;
		return (1);
	}
	return (0);
}

int player_move_back(t_env *env)
{

	double newX = env->player.x - env->player.dirx;
	double newY = env->player.y - env->player.diry;
	if (env->map.grid[(int)newY][(int)newX] == '0')
	{
		env->player.x = newX;
		env->player.y = newY;
		return (1);
	}
	return (0);
}

int player_move_right(t_env *env)
{

	double newX = env->player.x - env->player.diry;
	double newY = env->player.y + env->player.dirx;

	if (env->map.grid[(int)newY][(int)newX] == '0')
	{
		env->player.x = newX;
		env->player.y = newY;
		return (1);
	}
	return (0);
}

int player_move_left(t_env *env)
{
	double newX = env->player.x + env->player.diry;
	double newY = env->player.y - env->player.dirx;

	if (env->map.grid[(int)newY][(int)newX] == '0')
	{
		env->player.x = newX;
		env->player.y = newY;
		return (1);
	}
	return (0);
}

void	player_move(mlx_key_data_t key, t_env *env)
{
	int	draw;

	if (key.key == MLX_KEY_A)
		draw = player_move_left(env);
	if (key.key == MLX_KEY_D)
		draw = player_move_right(env);
	if (key.key == MLX_KEY_W)
		draw = player_move_forward(env);
	if (key.key == MLX_KEY_S)
		draw = player_move_back(env);
	env->draw = draw;
}

void	set_game(void *param)
{
	t_env	*env;

	env = param;
	//y = 0;
	//pixels = (uint32_t *)env->img->pixels;
	if (env->draw)
	{
		ft_run_dda(env);
		env->draw = 0;
	}
}

void	close_func(void *param)
{
	t_env	*env;

	env = param;
	mlx_close_window(env->mlx);
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

void	key_func(mlx_key_data_t key, void *param)
{
	t_env	*env;

	env = param;
	if (key.action == MLX_PRESS)
	{
		if (key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_LEFT)
			rotate(key, env);
		else if (key.key == MLX_KEY_A
			|| key.key == MLX_KEY_D
			|| key.key == MLX_KEY_W
			|| key.key == MLX_KEY_S)
		{
			player_move(key, env);
		}
		else if (key.key == MLX_KEY_ESCAPE)
			mlx_close_window(env->mlx);
	}
}
