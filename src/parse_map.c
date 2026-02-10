#include "../cub3d.h"

void	copy_data(char **temp, t_game *game, size_t i)
{
	size_t	j;
	j = 0;
	while(j < i)
	{
		temp[j] = game->map.data[j];
		j++;
	}
}

int	calculate_map_width(t_map map)
{
	size_t	max;
	size_t	size;
	size_t	i;

	i = 0;
	max = 0;
	while(i < map.height)
	{
		size = ft_strlen(map.data[i]);
		if(size > max)
			max = size;
		i++;
	}
	return (max);
}
void	set_start_dir(t_game *game, size_t i, size_t j)
{
	game->player.x = i;
	game->player.y = j;
	game->player.side = DEFAULT;
	if(game->map.data[i][j] == 'N')
		game->player.side = NORTH;
	else if(game->map.data[i][j] == 'S')
		game->player.side = SOUTH;
	else if(game->map.data[i][j] == 'E')
		game->player.side = EAST;
	else if(game->map.data[i][j] == 'W')
		game->player.side = WEST;

}
void	set_start_position(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	game->player.x = i;
	game->player.y = j;
	while(i < game->map.height)
	{
		j = 0;
		while(j < game->map.width)
		{
			if(game->map.data[i][j] == 'N' ||
				game->map.data[i][j] == 'S' ||
				game->map.data[i][j] == 'E' ||
				game->map.data[i][j] == 'W')
					set_start_dir(game, i, j);

			j++;
		}
		i++;
	}
	return ;
}

int	parse_map(int fd, t_game *game,char *line)
{
	char	**temp;
	size_t		i;

	i = 0;
	game->map.data = NULL;
	while(line)
	{
		temp = (char **)malloc(sizeof(char *) * (i + 2));
		if(!temp)
			return (0);
		copy_data(temp, game, i);
		temp[i] = line;
		temp[i+1] = NULL;
		free(game->map.data);
		game->map.data = temp;
		i++;
		line = get_next_line(fd);
	}
	game->map.height = i;
	game->map.width = calculate_map_width(game->map);
	set_start_position(game);
	if(!validate_map(game))
		return (0);
	return (1);
}

