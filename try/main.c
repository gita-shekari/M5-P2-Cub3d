/**
 * 1. draw a grid in the window
 * 	1.1 ? draw color pixel by pixel or draw with texture.
 * 2. create player
 */
#include <MLX42/MLX42.h>
#include <libft.h>
#include "try.h"
#include <math.h> // for tan()

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
	//int		y;
	//int		x;
	//uint32_t	color;
	//uint32_t	*pixels;

	env = param;
	//y = 0;
	//pixels = (uint32_t *)env->img->pixels;
	if (env->draw)
	{
		ft_run_dda(env);
		env->draw = 0;
	}
		
	//while (y < HEIGHT)
	//{
	//	x = 0;
	//	while (x < WIDTH)
	//	{

	//		color = check_color(y);
	//		// == mlx_put_pixel(env->img, x, y, color); use the following is faster in performance.
	//		pixels[pidx(x, y, WIDTH)] = color;
	//		x++;
	//	}
	//	y++;
	//}
}

void	close_func(void *param)
{
	t_env	*env;

	env = param;
	mlx_close_window(env->mlx);
}

static void set_player_dir(t_p *p, char c)
{
	printf("%p, dirx = %f\n", p, p->dirx);
    if (c == 'N')
	{
		p->dirx = 0.0;
		p->diry = -1.0;
	}
    else if (c == 'S')
	{
		p->dirx = 0.0; 
		p->diry = 1.0;
	}      
    else if (c == 'E')
	{
		p->dirx = 1.0;
		p->diry = 0.0;
	}
    else if (c == 'W')
	{
		p->dirx = -1.0;
		p->diry = 0.0;
	}
	printf("finish\n");
}

static void	set_player_plane(t_p *p)
{
	double	plane;
	
	//printf("in set player plane\n");
	plane = tan(FOV * M_PI / 180.0);
	//printf("len = %f\n", plane_len);
	p->planex = ((-1) * p->diry) * (plane / 2);
	//printf("px = %f\n", p->planex);
	p->planey = p->dirx * (plane / 2);
	//printf("py = %f\n", p->planey);
}

void    set_grid(char *map[], t_env *env)
{
    int x;
    int y;
    int found;

    env->grid = map;
    found = 0;
    y = 0;
	printf("in set grid\n");
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
                env->player.x = (double)x + 0.5;
                env->player.y = (double)y + 0.5;
                set_player_dir(&(env->player), map[y][x]);
				set_player_plane(&(env->player));
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

	char map_data[][11] = {
    "1111111111",
    "1000000001",
    "1000110001",
    "1010000001",
    "1001N00101",
    "1000000001",
    "1111111111",
	};

	char *map[8];
	for (int i = 0; i < 7; i++)
    	map[i] = map_data[i];
	map[7] = NULL;

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
	env.xpm = malloc(sizeof(xpm_t *) * 4);
	if (!env.xpm)
		ft_error_mlx(&env);
	// later change to this.
	//int	i = -1;
	//while (++i < 4)
	//	env.xpm[i] = mlx_load_xpm42(game->xpm[i].path);
	printf("before open xpm\n");
	env.xpm[0] = mlx_load_xpm42("./textures/NO.xpm42");
	env.xpm[1] = mlx_load_xpm42("./textures/SO.xpm42");
	env.xpm[2] = mlx_load_xpm42("./textures/EA.xpm42");
	env.xpm[3] = mlx_load_xpm42("./textures/WE.xpm42");
	if (!env.xpm[0] || !env.xpm[1] || !env.xpm[2] || !env.xpm[3])
		ft_error_mlx(&env);
	
	if (mlx_image_to_window(env.mlx, env.img, 0, 0) < 0)
		ft_error_mlx(&env);
	printf("before before set game\n");
	env.draw = 1;
	mlx_loop_hook(env.mlx, set_game, &env);
	mlx_close_hook(env.mlx, close_func, &env);
	mlx_loop(env.mlx);
	clean_bf_exit(&env);
	return (EXIT_SUCCESS);
}
