#include "cub3d.h"

void	init_env_mlx(t_env *env)
{
	int	i;

	env->mlx = NULL;
	env->img = NULL;
	env->xpm = NULL;
	env->mlx = mlx_init(WIDTH, HEIGHT, "hi and try", false);
	if (!env->mlx)
		ft_error_mlx(env);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		ft_error_mlx(env);
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
	if (mlx_image_to_window(env->mlx, env->img, 0, 0) < 0)
		ft_error_mlx(env);
	env->draw = 1;
}

