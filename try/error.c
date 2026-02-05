#include "try.h"
#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <libft.h>

static void	delete_image(t_env *env)
{
	if (!env->img)
		return ;
	mlx_delete_image(env->mlx, env->img);
	env->img = NULL;
}

static void	delete_xpm(t_env *env)
{
	int	i;

	i = -1;
	if (!env->xpm)
		return ;
	while (++i < 4)
	{
		if (env->xpm[i])
		{
			mlx_delete_xpm42(env->xpm[i]);
			env->xpm[i] = NULL;
		}
	}
	free(env->xpm);
	env->xpm = NULL;
}

void	clean_bf_exit(t_env *env)
{
	if (!env)
		return ;
	delete_image(env);
	delete_xpm(env);
	if (env->mlx)
	{
		mlx_terminate(env->mlx);
		env->mlx = NULL;
	}
}

void	ft_error_mlx(t_env *env)
{
	ft_putstr_fd(mlx_strerror(mlx_errno), 2);
	clean_bf_exit(env);
	exit(EXIT_FAILURE);
}