#include "cub3d.h"

static int is_edge(t_map map, size_t i, size_t j)
{
	if (i > map.height)
		return (1);
	if (j > ft_strlen(map.grid[i]))
		return (1);
	if (map.grid[i][j] == ' ' || map.grid[i][j] == '\n' || !map.grid[i][j] )
		return (1);
	return (0);
}

static int	validate_map_grid(t_map	map)
{

	size_t	i;
	size_t	j;

	i = 0;
	while(i < map.height)
	{
		j = 0;
		while(map.grid[i] && j < map.width && map.grid[i][j])
		{
			if (map.grid[i][j] == '0' || map.grid[i][j] == 'N' ||
				map.grid[i][j] == 'S' || map.grid[i][j] == 'E' ||
				map.grid[i][j] == 'W')
			{
				if ((j == 0 || is_edge(map, i, j-1)) || is_edge(map, i, j+1)
					|| (i == 0) || is_edge(map, i-1, j) || is_edge(map, i+1, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_env *env)
{
	if(env->check.C_checked == 0 || env->check.F_checked == 0
		|| env->check.NO_checked == 0 || env->check.SO_checked == 0
		|| env->check.WE_checked == 0 || env->check.EA_checked == 0)
		return (0);
	if(!validate_map_grid(env->map))
		return (0);
	return (1);
}
