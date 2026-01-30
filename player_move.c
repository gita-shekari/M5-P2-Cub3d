#include "try.h"
#include <MLX42/MLX42.h>

void	rotate(mlx_key_data_t key, void *param)
{
	t_env	*env;

	env = param;
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		// direction += ROTATE 
	if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		// direction -= ROTATE // if diry < 0
}