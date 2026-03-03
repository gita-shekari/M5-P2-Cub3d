/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshekari <gshekari@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/16 21:24:21 by gshekari      #+#    #+#                 */
/*   Updated: 2026/02/19 20:17:44 by jdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_edge(t_map map, size_t i, size_t j)
{
	if (i > map.height)
		return (1);
	if (j > ft_strlen(map.grid[i]))
		return (1);
	if (map.grid[i][j] == ' ' || map.grid[i][j] == '\n' || !map.grid[i][j])
		return (1);
	return (0);
}

int	validate_map_grid(t_map	map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < map.height)
	{
		j = 0;
		while (map.grid[i] && j < map.width && map.grid[i][j])
		{
			if (map.grid[i][j] == '0' || map.grid[i][j] == 'N' ||
				map.grid[i][j] == 'S' || map.grid[i][j] == 'E' ||
				map.grid[i][j] == 'W')
			{
				if ((j == 0 || is_edge(map, i, j - 1)) || is_edge(map, i, j + 1)
					|| (i == 0) || is_edge(map, i - 1, j)
					|| is_edge(map, i + 1, j))
					return (ft_error_map("map is wrong"));
			}
			else if (map.grid[i][j] != '1' && map.grid[i][j] != '\n'
					&& map.grid[i][j] != ' ')
				return (ft_error_map("map contain illegal characters"));
			j++;
		}
	}
	return (1);
}

int	validate_map(t_env *env)
{
	if (env->check.c_checked == 0 || env->check.f_checked == 0
		|| env->check.no_checked == 0 || env->check.so_checked == 0
		|| env->check.we_checked == 0 || env->check.ea_checked == 0)
		return (ft_error_map("invalid document format or missing information"));
	if (env->map.width == 0 || env->map.height == 0)
		return (ft_error_map("map is missing"));
	if (env->map.width < 3 || env->map.height < 3)
		return (ft_error_map("map is too small"));
	return (1);
}
