/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 20:47:26 by gshekari          #+#    #+#             */
/*   Updated: 2026/01/27 18:40:17 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void pass_empty_lines(int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != '\n' && line[i] != '\0')
		{
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(fd);
	}
	return ;
}

int	pass_spaces(char *line)
{
	int i = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}

int	is_valid_id(char line,int *i,t_game game)
{
	if(ft_strncmp(&line[i], "NO", 2) == 0)
}
int init_game(int fd, t_game *game)
{
	char *line;
	int i;

	line = get_next_line(fd);
	while (line)
	{
		pass_empty_lines(fd);
		i = pass_spaces(line);
		if (!set_textures(line, i, game))
			return (0);
		line = get_next_line(fd);
	}
	return (1);
}

