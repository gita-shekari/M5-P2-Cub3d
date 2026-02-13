#include "cub3d.h"

static uint32_t color(t_rgb rgb)
{
	return (
		((uint32_t)rgb.R << 24) |
		((uint32_t)rgb.G << 16) |
		((uint32_t)rgb.B << 8)  |
		(0xFF) 
	);
}

static uint32_t	tex_color(mlx_texture_t *tex, double x, double y)
{
	int	tex_i;
	int	i;
	int	j;

	i = (int)x;
	j = (int)y;
	if (i < 0)
		i = 0;
	else if (i >= (int)tex->width)
		i = (int)tex->width - 1;
	if (j < 0)
		j = 0;
	else if (j >= (int)tex->height)
		j = (int)tex->height - 1;
	tex_i = (j * tex->width + i) * 4;
	//if (tex_i < 0 || tex_i >= (int)(tex->width * tex->height * 4))
	//	printf("out of bounds %d, bound= %d, x = %f, y = %f\n", tex_i, (int)(tex->width * tex->height * 4), x, y);
	return (
		((uint32_t)tex->pixels[tex_i] << 24) |
		((uint32_t)tex->pixels[tex_i + 1] << 16) |
		((uint32_t)tex->pixels[tex_i + 2] << 8) |
		((uint32_t)tex->pixels[tex_i + 3])
	);
}

static mlx_texture_t	get_xpm_texture(t_side side, t_env *env)
{
	int	xpm_idx;

	if (side == NORTH)
		xpm_idx = NORTH;
	else if (side == SOUTH)
		xpm_idx = SOUTH;
	else if (side == EAST)
		xpm_idx = EAST;
	else
		xpm_idx = WEST;
	return (env->xpm[xpm_idx]->texture);
}
/**
 * tex_y = 0 is when wall height is smaller then screen. But if wall is heigher then screen, we only display the parts of wall_top - screen_height / 2
 * y = [wall_top, wall_bottom] => tex_y = [0, texture_height];
 */
	 
static void	draw_texture(t_ray hit, t_env *env, int x)
{
	mlx_texture_t	tex;
	double			tex_x;
	double			tex_y;
	int				start;
	int				end;

	tex = get_xpm_texture(hit.side, env);
	start = 0;
	if (hit.wall_top > 0)
		start = hit.wall_top;
	end = HEIGHT / 2 + hit.wall_height / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	tex_x = hit.wall_x * tex.width;
	while (start <= end)
	{
		tex_y = (double)(start - hit.wall_top) * ((double)tex.height / (double)hit.wall_height);
		mlx_put_pixel(env->img, x, start, tex_color(&tex, tex_x, tex_y));
		start++;
	}
}

void	draw_col(int x, t_ray ray, t_env *env)
{
	int	start;
	int	end;
	int	y;

	start = 0;
	if (ray.wall_top > 0)
		start = ray.wall_top;
	end = HEIGHT / 2 + ray.wall_height / 2;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	y = -1;
	while (++y < start)
		mlx_put_pixel(env->img, (uint32_t)x, (uint32_t)y, color(env->ceiling));
	draw_texture(ray, env, x);
	y = end;
	while (++y < HEIGHT)
		mlx_put_pixel(env->img, (uint32_t)x, (uint32_t)y, color(env->floor));
}
