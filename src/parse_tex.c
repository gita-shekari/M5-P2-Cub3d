/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:24:03 by gshekari          #+#    #+#             */
/*   Updated: 2026/02/16 21:24:06 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	check_rgb_value(char **rgb_str, t_rgb *rgb)
{
	int	i;
	int	j;

	i = -1;
	if (!rgb_str)
		return (0);
	while (++i < 3)
	{
		j = 0;
		if (!rgb_str[i])
			return (ft_error_map("missing rgb value"));
		j = pass_spaces(rgb_str[i]);
		if (!rgb_str[i][j])
			return (ft_error_map("missing rgb value"));
	}
	if (rgb_str[i])
		return (ft_error_map("too many rgb value"));
	rgb->r = ft_atoi(rgb_str[0]);
	rgb->g = ft_atoi(rgb_str[1]);
	rgb->b = ft_atoi(rgb_str[2]);
	if (rgb->r < 0 || rgb->r > 255
		|| rgb->g < 0 || rgb->g > 255
		|| rgb->b < 0 || rgb->b > 255)
		return (ft_error_map("invalid rgb value"));
	return (1);
}

static	int	set_floor_ceiling(char *line, int i, t_env *env, char type)
{
	char	**rgb_str;
	t_rgb	rgb;

	rgb_str = ft_split(&line[i], ',');
	if (!check_rgb_value(rgb_str, &rgb))
		return (free_split(rgb_str), 0);
	if (type == 'F' && env->check.f_checked == 0)
	{
		env->floor.r = rgb.r;
		env->floor.g = rgb.g;
		env->floor.b = rgb.b;
		env->check.f_checked = 1;
	}
	else if (type == 'C' && env->check.c_checked == 0)
	{
		env->ceiling.r = rgb.r;
		env->ceiling.g = rgb.g;
		env->ceiling.b = rgb.b;
		env->check.c_checked = 1;
	}
	else
		return (free_split(rgb_str),
			ft_error_map("duplicated value for ceiling or floor"));
	return (free_split(rgb_str), 1);
}

static void	set_env_tex(t_side	side, t_env *env, char *path)
{
	if (side == NORTH)
	{
		env->tex_path[NORTH] = path;
		env->check.no_checked = 1;
	}
	if (side == SOUTH)
	{
		env->tex_path[SOUTH] = path;
		env->check.so_checked = 1;
	}
	if (side == WEST)
	{
		env->tex_path[WEST] = path;
		env->check.we_checked = 1;
	}
	if (side == EAST)
	{
		env->tex_path[EAST] = path;
		env->check.ea_checked = 1;
	}
}

static int	set_textures(char *line, int i, char *side, t_env *env)
{
	char	*path;

	path = ft_strtrim(&line[i], "\n");
	if (!path)
		return (ft_malloc("parse texture"));
	if (ft_strncmp(side, "NO", 2) == 0 && env->check.no_checked == 0)
		set_env_tex(NORTH, env, path);
	else if (ft_strncmp(side, "SO", 2) == 0 && env->check.so_checked == 0)
		set_env_tex(SOUTH, env, path);
	else if (ft_strncmp(side, "WE", 2) == 0 && env->check.we_checked == 0)
		set_env_tex(WEST, env, path);
	else if (ft_strncmp(side, "EA", 2) == 0 && env->check.ea_checked == 0)
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
		|| ft_strncmp(&line[i], "EA", 2) == 0
		|| ft_strncmp(&line[i], "WE", 2) == 0)
	{
		ft_strlcpy(side, &line[i], 3);
		i += 2;
		i = pass_spaces(&line[i]) + i;
		if (!set_textures(line, i, side, env))
			return (0);
	}
	else if (line[i] == 'C' || line[i] == 'F')
	{
		type = line[i++];
		i += pass_spaces(&line[i]);
		if (!set_floor_ceiling(line, i, env, type))
			return (0);
	}
	else
		return (ft_error_map("unrelated information"));
	return (1);
}
