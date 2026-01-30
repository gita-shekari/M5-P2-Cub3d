/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:20:32 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/06 20:10:42 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	if ((unsigned char)c == '\0' && str[i] == '\0')
		return (str + i);
	return (NULL);
}
