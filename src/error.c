#include "cub3d.h"

void	ft_error_mlx(t_env *env)
{
	ft_putstr_fd(mlx_strerror(mlx_errno), 2);
	clean_bf_exit(env, -1);
	exit(EXIT_FAILURE);
}
