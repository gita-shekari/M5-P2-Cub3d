#include "try.h"
#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <libft.h>

void	ft_error_mlx(t_env *env)
{
	ft_putstr_fd(mlx_strerror(mlx_errno), 2);
	if (env->img)
		mlx_delete_image(env->mlx, env->img);
	if (env->mlx)
		mlx_terminate(env->mlx);
	exit(EXIT_FAILURE);
}

void	clean_exit(t_env *env)
{
	if (env)
	{
		if (env->img)
		{
			mlx_delete_image(env->mlx, env->img);
			env->img = NULL;
		}
		if (env->mlx)
		{
			mlx_terminate(env->mlx);
			env->mlx = NULL;
		}
	}
	return ;
}