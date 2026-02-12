#include "cub3d.h"

void	copy_grid(char **temp, t_env *env, size_t i)
{
	size_t	j;
	j = 0;
	while(j < i)
	{
		temp[j] = env->map.grid[j];
		j++;
	}
}

int	calculate_map_width(t_map map)
{
	size_t	max;
	size_t	size;
	size_t	i;

	i = 0;
	max = 0;
	while(i < map.height)
	{
		size = ft_strlen(map.grid[i]);
		if(size > max)
			max = size;
		i++;
	}
	return (max);
}
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

static void set_player_dir(t_p *p, char c)
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
		while(j < env->map.width)
		{

			if(env->map.grid[i][j] == 'N' ||
				env->map.grid[i][j] == 'S' ||
				env->map.grid[i][j] == 'E' ||
				env->map.grid[i][j] == 'W')
					{
					if (found == 1)
					{
						ft_putstr_fd("Error: multiple player start positions\n", 2);
						return (0);
					}
					env->player.x = (double)j + 0.5;
                	env->player.y = (double)i + 0.5;
					set_player_dir(&(env->player), env->map.grid[i][j]);
					set_player_plane(&(env->player));
					env->map.grid[i][j] = '0';
					found = 1;
					}

			j++;
		}
		i++;
	}
	if (!found)
	{
		ft_putstr_fd("Error: player start position not found\n", 2);
		return (0);
	}

	return (1);
}

int	parse_map(int fd, t_env *env,char *line)
{
	char	**temp;
	size_t		i;

	i = 0;
	env->map.grid = NULL;
	while(line)
	{
		temp = (char **)malloc(sizeof(char *) * (i + 2));
		if(!temp)
			return (0);
		copy_grid(temp, env, i);
		temp[i] = line;
		temp[i+1] = NULL;
		free(env->map.grid);
		env->map.grid = temp;
		i++;
		line = get_next_line(fd);
	}
	env->map.height = i;
	env->map.width = calculate_map_width(env->map);
	if(!validate_map(env))
		return (0);
	if(!set_start_position(env))
		return (0);
	return (1);
}

