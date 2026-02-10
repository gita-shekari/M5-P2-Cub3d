
#include "../cub3d.h"

int is_edge(t_map map, size_t i, size_t j)
{
	if (i > map.height)
		return (1);
	if (j > ft_strlen(map.data[i]))
		return (1);
	if (map.data[i][j] == ' ' || map.data[i][j] == '\n')
		return (1);
	return (0);
}

int	validate_map_data(t_map	map)
{

	size_t	i;
	size_t	j;

	i = 0;
	while(i < map.height)
	{
		j = 0;
		while(j < map.width)
		{
			if (map.data[i][j] == '0' || map.data[i][j] == 'N' ||
				map.data[i][j] == 'S' || map.data[i][j] == 'E' ||
				map.data[i][j] == 'W')
			{
				if(is_edge(map, i, j-1) || is_edge(map, i, j+1) ||
					is_edge(map, i-1, j) || is_edge(map, i+1, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if(game->player.side == DEFAULT)
		return (0);
	if(game->check.C_checked == 0 || game->check.F_checked == 0
		|| game->check.NO_checked == 0 || game->check.SO_checked == 0
		|| game->check.WE_checked == 0 || game->check.EA_checked == 0)
		return (0);
	if(!validate_map_data(game->map))
		return (0);
	return (1);
}
