
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
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (0);
	RGB.R = ft_atoi(rgb[0]);
	RGB.G = ft_atoi(rgb[1]);
	RGB.B = ft_atoi(rgb[2]);
	if (RGB.R < 0 || RGB.R > 255 || RGB.G < 0 || RGB.G > 255 || RGB.B < 0 || RGB.B > 255)
		return (0);
	if (type == 'F' && game->check.F_checked == 0)
	{
		game->floor.R = RGB.R;
		game->floor.G = RGB.G;
		game->floor.B = RGB.B;
		game->check.F_checked = 1;
	}
	else if (type == 'C' && game->check.C_checked == 0)
	{
		game->ceiling.R = RGB.R;
		game->ceiling.G = RGB.G;
		game->ceiling.B = RGB.B;
		game->check.C_checked = 1;
	}
	else
		return (free_split(rgb), 0);
	return (free_split(rgb), 1);
}

int	set_textures(char *line, int i, char *side, t_game *game)
{
	char	*path;

	path = ft_strtrim(&line[i], "\n");
	if(!path)
		return (0);
	if(ft_strncmp(side, "NO", 2) == 0 && game->check.NO_checked == 0)
	{
		game->xpm[NORTH].path = path;
		game->check.NO_checked = 1;
	}
	else if(ft_strncmp(side, "SO", 2) == 0 && game->check.SO_checked == 0)
	{
		game->xpm[SOUTH].path = path;
		game->check.SO_checked = 1;
	}
	else if(ft_strncmp(side, "WE", 2) == 0 && game->check.WE_checked == 0)
	{
		game->xpm[WEST].path = path;
		game->check.WE_checked = 1;
	}
	else if(ft_strncmp(side, "EA", 2) == 0 && game->check.EA_checked == 0)
	{
		game->xpm[EAST].path = path;
		game->check.EA_checked = 1;
	}
	else
		return (free(path), 0);
	return (1);
}

int	parse_textures(char *line, int i, t_game *game)
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
		return(0);
	return (1);
}

int init_game(int fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if(!line)
		return (0);
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
		if (!parse_textures(line, i, game))
			return (free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	 	printf("%s\n", game->xpm[NORTH].path);
		printf("%s\n", game->xpm[SOUTH].path);
		printf("%s\n", game->xpm[WEST].path);
		printf("%s\n", game->xpm[EAST].path);
		printf("floor R : %d G: %d B: %d\n", game->floor.R, game->floor.G, game->floor.B);
		printf("ceiling R : %d G: %d B: %d\n", game->ceiling.R, game->ceiling.G, game->ceiling.B);
		size_t j = 0;
		while(j < game->map.height)
		{
			printf("%s", game->map.data[j]);
			j++;
		}
		printf("height : %zu  width : %zu\n", game->map.height, game->map.width);
		printf("player.x : %zu  player.x : %zu\n", game->player.x , game->player.y);
	return (1);
}


	//  printf("%s\n", game->xpm[NORTH].path);
	// 	printf("%s\n", game->xpm[SOUTH].path);
	// 	printf("%s\n", game->xpm[WEST].path);
	// 	printf("%s\n", game->xpm[EAST].path);
	// 	printf("floor R : %d G: %d B: %d\n", game->floor.R, game->floor.G, game->floor.B);
	// 	printf("ceiling R : %d G: %d B: %d\n", game->ceiling.R, game->ceiling.G, game->ceiling.B);
	// 	size_t j = 0;
	// 	while(j < game->map.height)
	// 	{
	// 		printf("%s", game->map.data[j]);
	// 		j++;
	// 	}
	// 	printf("height : %zu  width : %zu\n", game->map.height, game->map.width);
	// 	printf("player.x : %zu  player.x : %zu\n", game->player.x , game->player.y);
