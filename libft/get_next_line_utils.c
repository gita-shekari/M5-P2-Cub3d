/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:54:36 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/11 18:23:10 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_line(char *s1, char *s2)
{
	char	*joinstr;
	size_t	len;

	joinstr = NULL;
	if (!s1)
		s1 = ft_strdup("");
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joinstr = malloc(len);
	if (!joinstr)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(joinstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(joinstr, s2, len);
	free(s1);
	return (joinstr);
}
