
#ifndef CUB3d_H
#define CUB3d_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef enum s_side
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
	DEFAULT = 4
} t_side;

typedef struct s_xpm
{
	char	*path;

}	t_xpm;

typedef struct s_rgb
{
	int R;
	int G;
	int B;
} t_rgb;

typedef struct s_map
{
	char	**data;
	size_t	width;
	size_t	height;

} t_map;

typedef struct s_player
{
	size_t		x;
	size_t		y;
	t_side		side;

} t_player;


typedef struct s_check
{
	int		NO_checked;
	int		SO_checked;
	int		WE_checked;
	int		EA_checked;
	int		F_checked;
	int		C_checked;

} t_check;


typedef struct s_game
{
	t_map		map;
	t_xpm		xpm[4];
	t_player	player;
	t_rgb		ceiling;
	t_rgb		floor;
	t_check		check;

}	t_game;

int init_game(int fd, t_game *game);

/****************clean********************/
void	free_split(char **split);

/****************init_map********************/
int	parse_map(int fd, t_game *game, char *line);

/****************validate_map********************/
int	validate_map(t_game *game);

/****************validate_textures********************/
int	validate_textures(t_game *game);

#endif
