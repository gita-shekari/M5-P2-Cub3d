/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshekari <gshekari@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/26 15:24:16 by gshekari      #+#    #+#                 */
/*   Updated: 2026/01/29 18:05:00 by jdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3d_H
#define CUB3d_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

typedef enum s_side
{
	NORTH,
	SOUTH,
	EAST,
	WEST
} t_side;

typedef struct s_img
{
	void	*img_ptr;
	char	*path;
}	t_img;

typedef struct s_rgb
{
	int R;
	int G;
	int B;
} t_rgb;

typedef struct s_map
{
	char	**data;
	int		width;
	int		height;

} t_map;

typedef struct s_game
{
	t_map	map;
	t_img	img[4];
	t_rgb	ceiling;
	t_rgb	floor;
	t_side	side; // direction facing, decide dirx and diry
	double	dirx;
	double	diry; 
	double	x; // start position in map
	double	y; // start position in map

}	t_game;


#endif
