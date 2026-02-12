
#include "cub3d.h"

int	is_map_file(char *file_name)
{
	char	*format;

	format = ft_strrchr(file_name, '.');
	if (!format)
		return (0);
	if (ft_strncmp(format, ".cub", 4) == 0)
		return (1);
	else
		return (0);
}
void	set_config(t_env *env)
{

	env->check.NO_checked = 0;
	env->check.SO_checked = 0;
	env->check.WE_checked = 0;
	env->check.EA_checked = 0;
	env->check.F_checked = 0;
	env->check.C_checked = 0;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_env	*env;

	if (argc != 2)
		return (ft_putstr_fd("Wrong number of arguments\n", 2), 1);
	if (!is_map_file(argv[1]))
		return (ft_putstr_fd("File Is Not Valid\n", 2), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\n", 2), 1);
	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		return (ft_putstr_fd("Fail at malloc\n", 2), 1);
	set_config(env);
	if (!init_env(fd, env))
		return (clean_bf_exit(env, fd), 1);
	
	close(fd);
	init_env_mlx(env);
	mlx_loop_hook(env->mlx, set_game, env);
	mlx_key_hook(env->mlx, key_func, env);
	mlx_close_hook(env->mlx, close_func, env);
	mlx_loop(env->mlx);

	clean_bf_exit(env, -1);
	return (0);
}
