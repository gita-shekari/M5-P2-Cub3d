#ifndef TRY_H
# define TRY_H

# define WIDTH 500
# define HEIGHT 300

# define CEILING 0x1E90FFFF
# define FLOOR 0x228B22FF

# define ROTATE 30

#include <MLX42/MLX42.h>

typedef struct	s_pos
{
	int	x;
	int	y;
}			t_pos;


typedef struct s_env
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_texture_t *tex;
	char		**grid;
	t_p			*player;
	int			draw;
}				t_env;

typedef struct	s_p
{
	double	x;
	double	y;
	double	dirx;
	double	diry;
}				t_p;

uint32_t	color(mlx_texture_t *tex, int x, int y);
void		draw_texture(t_env *env, t_pos *pos);

void	ft_error_mlx(t_env *env);
void	clean_exit(t_env *env);

#endif