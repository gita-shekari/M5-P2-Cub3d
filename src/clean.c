/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdong <jdong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/18 14:52:51 by jdong         #+#    #+#                 */
/*   Updated: 2026/02/18 14:52:54 by jdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_charptr(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free_charptr(&(split[i]));
		i++;
	}
	free(split);
	split = NULL;
}

void	free_tex(char *paths[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free_charptr(&(paths[i]));
		i++;
	}
}

static void	delete_xpm(t_env *env)
{
	int	i;

	i = -1;
	if (!env->xpm)
		return ;
	while (++i < 4)
	{
		if (env->xpm[i])
		{
			mlx_delete_xpm42(env->xpm[i]);
			env->xpm[i] = NULL;
		}
	}
	free(env->xpm);
	env->xpm = NULL;
}

void	clean_bf_exit(t_env *env, int fd)
{
	if (!env)
		return ;
	if (env->map.grid)
		free_split(env->map.grid);
	free_tex(env->tex_path);
	if (env->img)
	{
		mlx_delete_image(env->mlx, env->img);
		env->img = NULL;
	}
	delete_xpm(env);
	if (env->mlx)
	{
		mlx_terminate(env->mlx);
		env->mlx = NULL;
	}
	if (fd != -1)
		close(fd);
	free(env);
}
