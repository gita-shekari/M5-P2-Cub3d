#include <MLX42/MLX42.h>
#include <try.h>

uint32_t	color(mlx_texture_t *tex, int x, int y)
{
	int	tex_i;

	tex_i = (y * tex->width + x) * 4;
	return (
		((uint32_t)tex->pixels[tex_i + 0] << 24) |
		((uint32_t)tex->pixels[tex_i + 1] << 16) |
		((uint32_t)tex->pixels[tex_i + 2] << 8) |
		((uint32_t)tex->pixels[tex_i + 3])
	);
}

void	draw_texture(t_env *env, t_pos *pos)
{
	int 		y;
	int 		x;
	uint32_t	c;

	y = 0;
	while (y < (int)env->tex->height)
	{
		x = 0;
		while (x < (int)env->tex->width)
		{
			c = color(env->tex, x, y);
			mlx_put_pixel(env->img, pos->x + x, pos->y + y, c);
			x++;
		}
		y++;
	}
}