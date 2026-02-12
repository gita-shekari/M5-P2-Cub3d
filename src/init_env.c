
#include "cub3d.h"

int	pass_spaces(char *line)
{
	int i = 0;
	while (line[i] == ' ' || line[i] =='\t')
		i++;
	return (i);
}
int	set_floor_ceiling(char *line, int i, t_env *env, char type)
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
		return (free_split(rgb), 0);
	if (type == 'F' && env->check.F_checked == 0)
	{
		env->floor.R = RGB.R;
		env->floor.G = RGB.G;
		env->floor.B = RGB.B;
		env->check.F_checked = 1;
	}
	else if (type == 'C' && env->check.C_checked == 0)
	{
		env->ceiling.R = RGB.R;
		env->ceiling.G = RGB.G;
		env->ceiling.B = RGB.B;
		env->check.C_checked = 1;
	}
	else
		return (free_split(rgb), 0);
	return (free_split(rgb), 1);
}

int	set_textures(char *line, int i, char *side, t_env *env)
{
	char	*path;

	path = ft_strtrim(&line[i], "\n");
	if(!path)
		return (0);
	if(ft_strncmp(side, "NO", 2) == 0 && env->check.NO_checked == 0)
	{
		env->tex_path[NORTH] = path;
		env->check.NO_checked = 1;
	}
	else if(ft_strncmp(side, "SO", 2) == 0 && env->check.SO_checked == 0)
	{
		env->tex_path[SOUTH] = path;
		env->check.SO_checked = 1;
	}
	else if(ft_strncmp(side, "WE", 2) == 0 && env->check.WE_checked == 0)
	{
		env->tex_path[WEST] = path;
		env->check.WE_checked = 1;
	}
	else if(ft_strncmp(side, "EA", 2) == 0 && env->check.EA_checked == 0)
	{
		env->tex_path[EAST] = path;
		env->check.EA_checked = 1;
	}
	else
		return (free(path), 0);
	return (1);
}

int	parse_textures(char *line, int i, t_env *env)
{
	char side[3]= "";
	char	type;

	if (ft_strncmp(&line[i], "NO", 2) == 0 || ft_strncmp(&line[i], "SO", 2) == 0 ||
		ft_strncmp(&line[i], "EA", 2) == 0 || ft_strncmp(&line[i], "WE", 2) == 0)
	{

		ft_strlcpy(side, &line[i], 3);
		i += 2;
		i = pass_spaces(&line[i]) + i;
		if(!set_textures(line, i, side, env))
			return (0);
	}
	else if (line[i] == 'C' || line[i] == 'F')
	{
		type = line[i++];
		i += pass_spaces(&line[i]);
		if(!set_floor_ceiling(line, i, env, type))
			return (0);
	}
	else
		return(0);
	return (1);
}

int init_env(int fd, t_env *env)
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
			if(!parse_map(fd, env, line))
				return (free(line), 0);
			break;
		}
		if (!parse_textures(line, i, env))
			return (free(line), 0);	
		free(line);
		line = get_next_line(fd);
	}
	if(env->map.height < 4 || env->map.width < 4)
		return (0);
	return (1);
}


	//  printf("%s\n", env->xpm[NORTH].path);
	// 	printf("%s\n", env->xpm[SOUTH].path);
	// 	printf("%s\n", env->xpm[WEST].path);
	// 	printf("%s\n", env->xpm[EAST].path);
	// 	printf("floor R : %d G: %d B: %d\n", env->floor.R, env->floor.G, env->floor.B);
	// 	printf("ceiling R : %d G: %d B: %d\n", env->ceiling.R, env->ceiling.G, env->ceiling.B);
	// 	size_t j = 0;
	// 	while(j < env->map.height)
	// 	{
	// 		printf("%s", env->map.grid[j]);
	// 		j++;
	// 	}
	// 	printf("height : %zu  width : %zu\n", env->map.height, env->map.width);
	// 	printf("player.x : %zu  player.x : %zu\n", env->player.x , env->player.y);
