/**
 * 1. draw a grid in the window
 * 	1.1 ? draw color pixel by pixel or draw with texture.
 * 2. create player
 */
#include <MLX42/MLX42.h>
#include <libft.h>
#include "try.h"

int	check_color(int y)
{
	if (y < HEIGHT / 2)
		return (CEILING);
	else
		return (FLOOR);
	/**
	 * if (x, y) is wall, do texture;
	 * is_wall(x, y, map);
	 * else if (y < HEIGHT / 2) return (CEILING)
	 * else return (FLOOR);
	 */
}

int	pidx(int x, int y)
{
	return (y * WIDTH + x);
}
void	set_game(void *param)
{
	t_env	*env;
	int		y;
	int		x;
	uint32_t	color;
	uint32_t	*pixels;

	env = param;
	y = 0;
	pixels = (uint32_t *)env->img->pixels;
	if (env->draw)
	{
		while (y < HEIGHT)
		{
			x = 0;
			while (x < WIDTH)
			{

				color = check_color(y);
				// == mlx_put_pixel(env->img, x, y, color); use the following is faster in performance.
				pixels[pidx(x, y)] = color;
				x++;
			}
			y++;
		}
		env->draw = 0;
	}
}

void	close_func(void *param)
{
	t_env	*env;

	env = param;
	mlx_close_window(env->mlx);
}

int32_t	main(void)
{
	t_env	env;

	env.mlx = NULL;
	env.img = NULL;
	env.mlx = mlx_init(WIDTH, HEIGHT, "hi and try", false);
	if (!env.mlx)
		ft_error_mlx(&env);
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	if (!env.img)
		ft_error_mlx(&env);

	//mlx_texture_t	*tex = mlx_load_xpm42("../textures/wood.xpm");
	//int	tex_x = 5, tex_y = 5;
	//uint32_t color = ((uint32_t *)tex->pixels)[tex_y * tex->width + tex_x];

	// set every pixel to white(int32_t is a pixel type's size);
	//ft_memset(env->img->pixels, 255, env->img->width * env->img->height * sizeof(int32_t));
	
	if (mlx_image_to_window(env.mlx, env.img, 0, 0) < 0)
		ft_error_mlx(&env);
	env.draw = 1;
	mlx_loop_hook(env.mlx, set_game, &env);
	mlx_close_hook(env.mlx, close_func, &env);
	mlx_loop(env.mlx);
	clean_exit(&env);
	return (0);
}