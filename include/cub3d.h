/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:02:29 by gshekari          #+#    #+#             */
/*   Updated: 2026/02/18 20:20:45 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1000
# define HEIGHT 800
# define FOV 66.0
# define M_PI 3.14159265358979323846

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <MLX42/MLX42.h>
# include "libft.h"
# include <math.h>

typedef enum s_side
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
}			t_side;

typedef struct s_ray
{
	double	dirx;
	double	diry;
	double	perp_dist;
	double	wall_x;
	int		wall_top;
	int		wall_height;
	t_side	side;
}				t_ray;

typedef struct s_dda
{
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	double	distx;
	double	disty;
}				t_dda;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_map
{
	char	**grid;
	size_t	width;
	size_t	height;
}				t_map;

typedef struct s_p
{
	double	x;
	double	y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}				t_p;

typedef struct s_check
{
	int		no_checked;
	int		so_checked;
	int		we_checked;
	int		ea_checked;
	int		f_checked;
	int		c_checked;
}				t_check;

typedef struct s_env
{
	t_map			map;
	char			*tex_path[4];
	xpm_t			**xpm;
	t_p				player;
	t_rgb			ceiling;
	t_rgb			floor;
	t_check			check;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*tex;
}				t_env;

//parsing and setup
int		init_env(int fd, t_env *env);
int		parse_textures(char *line, int i, t_env *env);
int		pass_spaces(char *line);
int		parse_map(int fd, t_env *env, char *line);
int		validate_map_grid(t_map	map);
int		validate_map(t_env *env);

//clean
void	free_split(char **split);
void	free_charptr(char **ptr);
void	clean_bf_exit(t_env *env, int fd);

// player setup
int		set_start_position(t_env *env);
void	set_player_plane(t_p *p);
void	draw_col(int x, t_ray ray, t_env *env);

//ray.c
void	cal_ray_hit(t_env *env, t_ray *ray, t_dda dda, int side);
void	cal_ray_dir(t_ray *ray, t_p player, int x);
void	ft_run_dda(t_env *env);
int		ft_error_map(char *s);
int		ft_malloc(char *s);
int		ft_error_gen(char *s);
void	ft_error_mlx(t_env *env);

//mlx related func.
void	init_env_mlx(t_env *env);
void	set_game(void *param);
void	close_func(void *param);
void	key_func(mlx_key_data_t key, void *param);

//player_moves
void	player_move_forward(t_env *env);
void	player_move_back(t_env *env);
void	player_move_right(t_env *env);
void	player_move_left(t_env *env);
void	rotate(mlx_key_data_t key, t_env *env);

#endif
