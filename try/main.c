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

int	pidx(int x, int y, int width)
{
	return (y * width + x);
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
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{

			color = check_color(y);
			// == mlx_put_pixel(env->img, x, y, color); use the following is faster in performance.
			pixels[pidx(x, y, WIDTH)] = color;
			x++;
		}
		y++;
	}
}

void	close_func(void *param)
{
	t_env	*env;

	env = param;
	mlx_close_window(env->mlx);
}

static void set_player_dir(t_p *p, char c)
{
    if (c == 'N')
        (p->dirx = 0, p->diry = -1);
    else if (c == 'S')
        (p->dirx = 0, p->diry = 1);
    else if (c == 'E')
        (p->dirx = 1, p->diry = 0);
    else if (c == 'W')
        (p->dirx = -1, p->diry = 0);
}

void    set_grid(char *map[], t_env *env)
{
    int x;
    int y;
    int found;

    env->grid = map;
    found = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'N' || map[y][x] == 'S'
                || map[y][x] == 'E' || map[y][x] == 'W')
            {
                if (found)
                {
                    ft_putstr_fd("Error: multiple player start positions\n", 2);
                    exit(1);
                }
                env->player->x = x + 0.5;
                env->player->y = y + 0.5;
                set_player_dir(env->player, map[y][x]);
                map[y][x] = '0';
                found = 1;
            }
            x++;
        }
        y++;
    }
    if (!found)
    {
        ft_putstr_fd("Error: player start position not found\n", 2);
        exit(1);
    }
}


int32_t	main(void)
{
	t_env	env;

	char *map[] = {
    "1111111111",
    "1000000001",
    "1000110001",
    "1000100001",
    "1000N10001",
    "1000000001",
    "1111111111",
    NULL
	};
	set_grid(map, &env);

	env.mlx = NULL;
	env.img = NULL;
	env.mlx = mlx_init(WIDTH, HEIGHT, "hi and try", false);
	if (!env.mlx)
		ft_error_mlx(&env);
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	if (!env.img)
		ft_error_mlx(&env);
	
	//	draw_wall(&env);
	env.tex = mlx_load_xpm42("../textures/wood.xpm");
	
	if (mlx_image_to_window(env.mlx, env.img, 0, 0) < 0)
		ft_error_mlx(&env);
	mlx_loop_hook(env.mlx, set_game, &env);
	mlx_close_hook(env.mlx, close_func, &env);
	mlx_loop(env.mlx);
	clean_exit(&env);
	return (0);
}