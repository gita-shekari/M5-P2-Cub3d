
#include "../cub3d.h"

int	pass_spaces(char *line)
{
	int i = 0;
	while (line[i] == ' ' || line[i] =='\t')
		i++;
	return (i);
}
int	set_floor_ceiling(char *line, int i, t_game *game, char type)
{
	char	**rgb;
	t_rgb	RGB;

	rgb = ft_split(&line[i], ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (0);
	RGB.R = ft_atoi(rgb[0]);
	RGB.G = ft_atoi(rgb[1]);
	RGB.B = ft_atoi(rgb[2]);
	if (RGB.R < 0 || RGB.R > 255 || RGB.G < 0 || RGB.G > 255 || RGB.B < 0 || RGB.B > 255)
		return (0);
	if (type == 'F')
	{
		game->floor.R = RGB.R;
		game->floor.G = RGB.G;
		game->floor.B = RGB.B;
	}
	else
	{
		game->ceiling.R = RGB.R;
		game->ceiling.G = RGB.G;
		game->ceiling.B = RGB.B;
	}
	return (free_split(rgb), 1);
}

int	set_textures(char *line, int i, char *side, t_game *game)
{
	char	*path;

	path = ft_strtrim(&line[i], "\n");
	if(!path)
		return (0);
	if(ft_strncmp(side, "NO", 2) == 0)
		game->img[NORTH].path = path;
	else if(ft_strncmp(side, "SO", 2) == 0)
		game->img[SOUTH].path = path;
	else if(ft_strncmp(side, "WE", 2) == 0)
		game->img[WEST].path = path;
	else if(ft_strncmp(side, "EA", 2) == 0)
		game->img[EAST].path = path;
	else
		return (free(path), 0);
	return (1);
}
int	parse_content(char *line, int i, t_game *game)
{
	char side[3]= "";
	char	type;

	if (ft_strncmp(&line[i], "NO", 2) == 0 || ft_strncmp(&line[i], "SO", 2) == 0 ||
		ft_strncmp(&line[i], "EA", 2) == 0 || ft_strncmp(&line[i], "WE", 2) == 0)
	{
		ft_strlcpy(side, &line[i], 3);
		i += 2;
		i = pass_spaces(&line[i]) + i;
		if(!set_textures(line, i, side, game))
			return (0);
	}
	else if (line[i] == 'C' || line[i] == 'F')
	{
		type = line[i++];
		i += pass_spaces(&line[i]);
		if(!set_floor_ceiling(line, i, game, type))
			return (0);
	}
	else
		return (0);
	return (1);
}

int init_game(int fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		i = pass_spaces(line);
		if (!line[i] || line[i] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		if (line[i] == '1' || line[i] == '0')
		{
			if(!parse_map(fd, game, line))
				return (0);
			break;
		}
		if (!parse_content(line, i, game))
			return (free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	printf("%s\n", game->img[NORTH].path);
	printf("%s\n", game->img[SOUTH].path);
	printf("%s\n", game->img[WEST].path);
	printf("%s\n", game->img[EAST].path);
	printf("floor   R : %d	G: %d	B: %d\n", game->floor.R, game->floor.G, game->floor.B);
	printf("ceiling R : %d	G: %d	B: %d\n", game->ceiling.R, game->ceiling.G, game->ceiling.B);
	size_t j = 0;
	while(j < game->map.height)
	{
		printf("%s", game->map.data[j]);
		j++;
	}
	printf("map height : %zu\n", game->map.height);
	printf("map width :  %zu\n", game->map.width);
	return (1);
}


