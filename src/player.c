#include "cub3d.h"

void	set_player_plane(t_p *p)
{
	double	plane;

	//printf("in set player plane\n");
	plane = tan(FOV / 2 * M_PI / 180.0);
	//printf("len = %f\n", plane_len);
	p->planex = ((-1) * p->diry) * (plane);
	//printf("px = %f\n", p->planex);
	p->planey = p->dirx * (plane);
	//printf("py = %f\n", p->planey);
}

static void	init_player_dir(t_p *p, char c)
{
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
}

static int	check_player(t_env *env, int i, int j, int *found)
{
	if (env->map.grid[i][j] == 'N' || env->map.grid[i][j] == 'S' 
		|| env->map.grid[i][j] == 'E' || env->map.grid[i][j] == 'W')
	{
		if (*found == 1)
			return(ft_error_map("multiple players"));
		env->player.x = (double)j + 0.5;
		env->player.y = (double)i + 0.5;
		init_player_dir(&(env->player), env->map.grid[i][j]);
		set_player_plane(&(env->player));
		env->map.grid[i][j] = '0';
		*found = 1;
	}
	return (1);
}

int	set_start_position(t_env *env)
{
	size_t	i;
	size_t	j;
	int		found;

	i = 0;
	found = 0;
	while(i < env->map.height)
	{
		j = 0;
		while(env->map.grid[i] && j < env->map.width && env->map.grid[i][j])
		{
			if (!check_player(env, i, j, &found))
				return (0);
			j++;
		}
		i++;
	}
	if (!found)
		return (ft_error_map("no players"));
	return (1);
}