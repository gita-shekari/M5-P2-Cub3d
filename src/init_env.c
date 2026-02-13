#include "cub3d.h"

//while (line[i] == ' ' || line[i] =='\t')
int	pass_spaces(char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

static int	process_line(char *line, t_env *env, int i, int fd)
{
	if (line[i] == '1' || line[i] =='0')
		return (parse_map(fd, env, line));
	else if (!line[i] || line[i] == '\n')
		return (2);
	else
	{
		if (!parse_textures(line, i, env))
			return (0);
		else
			return (2);
	}
}

int	check_invalid(t_env *env)
{
	if (env->check.C_checked != 1 || env->check.F_checked != 1
	|| env->check.NO_checked != 1 || env->check.SO_checked != 1
	|| env->check.EA_checked != 1 || env->check.WE_checked != 1)
		return (ft_putstr_fd("missing info for texture or color\n", 2), 0);
	if (env->map.width < 4 || env->map.height < 4)
		return (ft_putstr_fd("map is too small\n", 2), 0);
	return (1);
}

int	init_env(int fd, t_env *env)
{
	char	*line;
	int		i;
	int		res;

	line = get_next_line(fd);
	if(!line)
		return (0);
	while (line)
	{
		i = pass_spaces(line);
		res = process_line(line, env, i, fd);
		if (res == 0)
		{
			free(line);
			line = get_next_line(-1);
			return (0);
		}
		else if (res == 1)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (!check_invalid(env))
		return (0);
	return (1);
}

//int	init_env(int fd, t_env *env)
//{
//	char	*line;
//	int		i;

//	line = get_next_line(fd);
//	if(!line)
//		return (0);
//	while (line)
//	{
//		i = pass_spaces(line);
//		if (!line[i] || line[i] == '\n')
//		{
//			free(line);
//			line = get_next_line(fd);
//			continue;
//		}
//		if (line[i] == '1' || line[i] == '0')
//		{
//			if(!parse_map(fd, env, line))
//				return (free(line), 0);
//			break;
//		}
//		if (!parse_textures(line, i, env))
//			return (free(line), 0);	
//		free(line);
//		line = get_next_line(fd);
//	}
//	if(env->map.height < 4 || env->map.width < 4)
//		return (0);
//	return (1);
//}