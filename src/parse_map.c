/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshekari <gshekari@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/16 21:23:44 by gshekari      #+#    #+#                 */
/*   Updated: 2026/02/19 20:18:23 by jdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_grid(char **temp, t_env *env, size_t i, char *line)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		temp[j] = env->map.grid[j];
		j++;
	}
	temp[i] = line;
	temp[i + 1] = NULL;
	free(env->map.grid);
	env->map.grid = temp;
}

static	int	calculate_map_width(t_map map)
{
	size_t	max;
	size_t	size;
	size_t	i;

	i = 0;
	max = 0;
	while (i < map.height)
	{
		size = ft_strlen(map.grid[i]);
		if (map.grid[i][size - 1] == '\n')
			size -= 1;
		if (size > max)
			max = size;
		i++;
	}
	return (max);
}

static int	line_is_not_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\n' || !line[i])
		return (0);
	else
		return (1);
}

static int	line_is_empty(int fd, char *line)
{
	size_t	i;

	free_charptr(&line);
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		while (++i < ft_strlen(line))
			if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
				return (free_charptr(&line), 0);
		free_charptr(&line);
		line = get_next_line(fd);
	}
	return (1);
}

int	parse_map(int fd, t_env *env, char *line)
{
	char	**temp;
	size_t	i;

	i = 0;
	env->map.grid = NULL;
	while (line && line_is_not_empty(line))
	{
		temp = (char **)malloc(sizeof(char *) * (i + 2));
		if (!temp)
			return (ft_malloc("parsing map"));
		copy_grid(temp, env, i, line);
		i++;
		line = get_next_line(fd);
	}
	if (line && !line_is_empty(fd, line))
		return (ft_error_map("contents after map"));
	env->map.height = i;
	env->map.width = calculate_map_width(env->map);
	if (!validate_map_grid(env->map) || !set_start_position(env))
		return (0);
	return (1);
}
