#include "cub3d.h"

static int	check_rgb_value(char **rgb, t_rgb *RGB)
{
	int	i;
	int	j;

	i = -1;
	if (!rgb)
		return (0);
	while (++i < 3)
	{
		j = 0;
		if (!rgb[i])
			return (ft_error_map("missing rgb value"));
		j = pass_spaces(rgb[i]);
		if (!rgb[i][j])
			return (ft_error_map("missing rgb value"));
	}
	if (rgb[i])
		return (ft_error_map("too many rgb value"));
	RGB->R = ft_atoi(rgb[0]);
	RGB->G = ft_atoi(rgb[1]);
	RGB->B = ft_atoi(rgb[2]);
	if (RGB->R < 0 || RGB->R > 255
		|| RGB->G < 0 || RGB->G > 255 
		|| RGB->B < 0 || RGB->B > 255)
		return (ft_error_map("invalid rgb value"));
	return (1);
}

static int	set_floor_ceiling(char *line, int i, t_env *env, char type)
{
	char	**rgb;
	t_rgb	RGB;

	rgb = ft_split(&line[i], ',');
	if (!check_rgb_value(rgb, &RGB))
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
		return (free_split(rgb), ft_error_map("duplicated value for ceiling or floor"));
	return (free_split(rgb), 1);
}

static void	set_env_tex(t_side	side, t_env *env, char *path)
{
	if (side == NORTH)
	{
		env->tex_path[NORTH] = path;
		env->check.NO_checked = 1;
	}
	if (side == SOUTH)
	{
		env->tex_path[SOUTH] = path;
		env->check.SO_checked = 1;
	}
	if (side == WEST)
	{
		env->tex_path[WEST] = path;
		env->check.WE_checked = 1;
	}
	if (side == EAST)
	{
		env->tex_path[EAST] = path;
		env->check.EA_checked = 1;
	}
}

static int	set_textures(char *line, int i, char *side, t_env *env)
{
	char	*path;

	path = ft_strtrim(&line[i], "\n");
	if(!path)
		return (ft_malloc("parse texture"));
	if(ft_strncmp(side, "NO", 2) == 0 && env->check.NO_checked == 0)
		set_env_tex(NORTH, env, path);
	else if(ft_strncmp(side, "SO", 2) == 0 && env->check.SO_checked == 0)
		set_env_tex(SOUTH, env, path);
	else if(ft_strncmp(side, "WE", 2) == 0 && env->check.WE_checked == 0)
		set_env_tex(WEST, env, path);
	else if(ft_strncmp(side, "EA", 2) == 0 && env->check.EA_checked == 0)
		set_env_tex(EAST, env, path);
	else
	{
		free_charptr(&path);
		return (ft_error_map("duplicated textures"));
	}
	return (1);
}

int	parse_textures(char *line, int i, t_env *env)
{
	char	side[3];
	char	type;

	if (ft_strncmp(&line[i], "NO", 2) == 0 || ft_strncmp(&line[i], "SO", 2) == 0 
		|| ft_strncmp(&line[i], "EA", 2) == 0 || ft_strncmp(&line[i], "WE", 2) == 0)
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
		return(ft_error_map("unrelated information"));
	return (1);
}
