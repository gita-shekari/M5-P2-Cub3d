
#include "../cub3d.h"

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
void	set_config(t_game *game)
{
	game->check.NO_checked = 0;
	game->check.SO_checked = 0;
	game->check.WE_checked = 0;
	game->check.EA_checked = 0;
	game->check.F_checked = 0;
	game->check.C_checked = 0;
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
	set_config(&game);
	if (!init_game(fd, &game))
		return (ft_printf("Error\n"), 1);
		// return (ft_printf("Map Is Not Valid\n"),
		// 	free_game(&game), close(fd), 1);
	// if (!play(&game))
	// 	return (ft_printf("Failed\n"), free_game(&game), close(fd), 1);
	//free_game(&game);
	close(fd);
	return (0);
}
