/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:50:18 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/11 18:22:10 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 1024

#endif

int	ft_strchr_line(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (1);
		i++;
	}
	if ((unsigned char)c == '\0' && str[i] == '\0')
		return (1);
	return (0);
}

char	*stash_trim(char *stash, size_t index)
{
	size_t	j;
	char	*temp;

	j = 0;
	if (!stash || index >= ft_strlen(stash))
	{
		free(stash);
		return (NULL);
	}
	temp = malloc(ft_strlen(stash) - index + 1);
	if (!temp)
		return (NULL);
	while (stash[index])
		temp[j++] = stash[index++];
	temp[j] = '\0';
	free(stash);
	stash = NULL;
	return (temp);
}

char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	line = malloc(ft_strlen(stash) + 1);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*stash;
	ssize_t		bytesread;

	if (fd == -1)
		return (free(stash), stash = NULL, NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (1)
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread <= 0)
			break ;
		buf[bytesread] = '\0';
		stash = ft_strjoin_line(stash, buf);
		if (stash == NULL || ft_strchr_line(stash, '\n'))
			break ;
	}
	free(buf);
	if (!stash || stash[0] == '\0' || bytesread == -1)
		return (free(stash), stash = NULL, NULL);
	line = extract_line(stash);
	return (stash = stash_trim(stash, ft_strlen(line)), line);
}
