#ifndef TRY_H
# define TRY_H

# define WIDTH 500
# define HEIGHT 300

# define CEILING 0x1E90FFFF
# define FLOOR 0x228B22FF

# define ROTATE 30

#include <MLX42/MLX42.h>

typedef struct s_env
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			draw;
}				t_env;


void	ft_error_mlx(t_env *env);
void	clean_exit(t_env *env);

#endif