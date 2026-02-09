#include <MLX42/MLX42.h>
#include "try.h"

uint32_t	tex_color(mlx_texture_t *tex, double x, double y)
{
	int	tex_i;

	tex_i = ((int)y * tex->width + (int)x) * 4;
	return (
		((uint32_t)tex->pixels[tex_i + 0] << 24) |
		((uint32_t)tex->pixels[tex_i + 1] << 16) |
		((uint32_t)tex->pixels[tex_i + 2] << 8) |
		((uint32_t)tex->pixels[tex_i + 3])
	);
}

void	tmp_put_color(t_env *env, int x, int y, char part)
{
	if (part == 'c')
		mlx_put_pixel(env->img, (uint32_t)x, (uint32_t)y, CEILING);
	if (part == 't')
		mlx_put_pixel(env->img, (uint32_t)x, (uint32_t)y, WALL);
	if (part == 'f')
		mlx_put_pixel(env->img, (uint32_t)x, (uint32_t)y, FLOOR);
}

 int	check_xpm_idx(t_dir side)
 {
	if (side == NORTH)
		return (0);
	else if (side == SOUTH)
		return (1);
	else if (side == EAST)
		return (2);
	else
		return (3);
 }
	// tex_pos = 0 is when wall height is smaller then screen. But if wall is heigher then screen, we only display the parts of wall_top - screen_height / 2
	// y = [wall_top, wall_bottom] => tex_y = [0, texture_height];
 void	draw_texture(int start, int end, t_hit *hit, t_env *env, int x)
 {
	double unit;
	double	tex_x;
	double	tex_pos;
	int		color;
	int		xpm_idx;
	mlx_texture_t tex;

	xpm_idx = check_xpm_idx(hit->side);
	tex = env->xpm[xpm_idx]->texture;
	tex_x = hit->wall_x * tex.width;
	unit = (double)tex.height / hit->wall_height;
	tex_pos = (double)(start - hit->wall_top) * unit;
	printf("wall x = %f, tex width = %d, hit wall top = %d, wall height = %d, perdist = %f\n", hit->wall_x, tex.width, hit->wall_top, hit->wall_height, hit->perp_dist);
	//printf("xpm idx = %d, tex_x = %f, tex_pos = %f\n", xpm_idx, tex_x, tex_pos);
	while (start <= end)
	{
		color = tex_color(&tex, tex_x, tex_pos);
		tex_pos += unit;
		mlx_put_pixel(env->img, x, start, color);
		start++;
	}
 }
