/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshekari <gshekari@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/26 15:24:06 by gshekari      #+#    #+#                 */
/*   Updated: 2026/01/29 18:17:50 by jdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_file(char *file_name)
{
	char	*format;

	format = ft_strrchr(file_name, '.');
	if (!format)
		return (0);
	if (ft_strncmp(format, ".cub", 4) == 0)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		return (ft_printf("Wrong number of arguments\n"), 1);
	if (!is_map_file(argv[1]))
		return (ft_printf("File Is Not Valid\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n"), 1);
	if (!init_game(fd, &game))
		return (ft_printf("Map Is Not Valid\n"),
			free_game(&game), close(fd), 1);
	if (!play(&game))
		return (ft_printf("Failed\n"), free_game(&game), close(fd), 1);

	// ===============prepare for render==================
	
	// 1. set dir
	if (game.side == NORTH)
	{
		game.dirx = 0;
		game.diry = 1;
	}
	if (game.side == SOUTH)
	{
		game.dirx = 0;
		game.diry = -1;
	}
	if (game.side == EAST)
	{
		game.dirx = 1;
		game.diry = 0;
	}
	if (game.side == WEST)
	{
		game.dirx = -1;
		game.diry = 0;
	}
	
	// when view turns east/right, west/left, turn 30 degree each;
	game->dirx = ?
	game->diry = ? right -: left + 
	free_game(&game);
	close(fd);
	return (0);
}
