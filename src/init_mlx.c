#include "cub3d.h"

void	init_env_mlx(t_env *env)
{
	int	i;

	env->mlx = NULL;
	env->img = NULL;
	env->xpm = NULL;
	env->xpm = ft_calloc(4, sizeof(xpm_t *));
	if (!env->xpm)
		ft_error_mlx(env);
	i = -1;
	while (++i < 4)
	{
		env->xpm[i] = mlx_load_xpm42(env->tex_path[i]);
		if (!env->xpm[i])
			ft_error_mlx(env);
	}
	env->mlx = mlx_init(WIDTH, HEIGHT, "No way out", false);
	if (!env->mlx)
		ft_error_mlx(env);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		ft_error_mlx(env);
	if (mlx_image_to_window(env->mlx, env->img, 0, 0) < 0)
		ft_error_mlx(env);
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
		else if (key.key == MLX_KEY_A)
			player_move_left(env);
		else if (key.key == MLX_KEY_D)
			player_move_right(env);
		else if (key.key == MLX_KEY_W)
			player_move_forward(env);
		else if (key.key == MLX_KEY_S)
			player_move_back(env);
		else if (key.key == MLX_KEY_ESCAPE)
			mlx_close_window(env->mlx);
	}
}

void	set_game(void *param)
{
	t_env	*env;

	env = param;
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
