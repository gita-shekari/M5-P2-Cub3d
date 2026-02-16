#include "cub3d.h"

static void	copy_grid(char **temp, t_env *env, size_t i)
{
	size_t	j;
	j = 0;
	while(j < i)
	{
		temp[j] = env->map.grid[j];
		j++;
	}
}

static int	calculate_map_width(t_map map)
{
	size_t	max;
	size_t	size;
	size_t	i;

	i = 0;
	max = 0;
	while(i < map.height)
	{
		size = ft_strlen(map.grid[i]);
		if (map.grid[i][size - 1] == '\n')
			size -= 1;
		if(size > max)
			max = size;
		i++;
	}
	return (max);
}

int	parse_map(int fd, t_env *env,char *line)
{
	char	**temp;
	size_t		i;

	i = 0;
	env->map.grid = NULL;
	while(line)
	{
		temp = (char **)malloc(sizeof(char *) * (i + 2));
		if(!temp)
			return (ft_malloc("parsing map"));
		copy_grid(temp, env, i);
		temp[i] = line;
		temp[i + 1] = NULL;
		free(env->map.grid);
		env->map.grid = temp;
		i++;
		line = get_next_line(fd);
	}
	env->map.height = i;
	env->map.width = calculate_map_width(env->map);
	if(!validate_map(env))
		return (0);
	if(!set_start_position(env))
		return (0);
	return (1);
}
