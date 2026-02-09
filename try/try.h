#ifndef TRY_H
# define TRY_H

# define WIDTH 500
# define HEIGHT 300

# define CEILING 0x1E90FFFF
# define FLOOR 0x228B22FF
# define WALL	0x964B00FF

# define FOV 66.0
//# define M_PI 3.14159265358979323846

# define ROTATE 30

#include <MLX42/MLX42.h>
#include <stdio.h> // for printing

typedef enum	e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}				t_dir;

typedef struct	s_ray
{
	double x;
	double y;
}				t_ray;

typedef struct	s_hit
{
	double	perp_dist;
	double	wall_x;
	int		wall_top;
	int		wall_height;
	t_dir	side;		//side = 0; vertical wall on the west or east
}				t_hit;

typedef struct	s_p
{
	double	x;
	double	y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}				t_p;

typedef struct s_env
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	xpm_t		**xpm;
	char		**grid;
	t_p			player;
	int			draw;
}				t_env;

uint32_t	color(mlx_texture_t *tex, int x, int y);
void	tmp_put_color(t_env *env, int x, int y, char part);
void	draw_texture(int start, int end, t_hit *hit, t_env *env, int x);

void	ft_run_dda(t_env *env);

void	ft_error_mlx(t_env *env);
void	clean_bf_exit(t_env *env);

#endif