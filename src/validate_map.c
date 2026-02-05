
#include "../cub3d.h"

int	is_edge(t_map map, size_t i, size_t j)
{
	if(map.data[i][j] == '1' && map.data[i][j+1] == ' ')
		return (1);
	else if (map.data[i][j] == '1' && map.data[i][j-1] == ' ')
		return (1);
	return (0);
}
int	validate_map(t_map	map)
{

	size_t	i;
	size_t	j;

	i = 0;
	while(i < map.height)
	{
		j = 0;
		while(j < ft_strlen(map.data[i]))
		{
			if(is_edge(map, i, j))
			{
				printf("\nis_edge");
				if(map.data[i+1][j-1] == '0' || map.data[i+1][j] == '0' || map.data[i+1][j+1] == '0')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
