#include "cub3d.h"

void	ft_error_mlx(t_env *env)
{
	ft_putstr_fd(mlx_strerror(mlx_errno), 2);
	ft_putstr_fd("\n", 2);
	clean_bf_exit(env, -1);
	exit(EXIT_FAILURE);
}

int	ft_error_map(char *s)
{
	ft_putstr_fd("Invaild map document: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	ft_malloc(char *s)
{
	ft_putstr_fd("Malloc failed at: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	ft_error_gen(char *s)
{
	ft_putstr_fd("Invaild ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	return (EXIT_FAILURE);
}
