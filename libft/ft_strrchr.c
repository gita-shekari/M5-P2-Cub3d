/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:20:09 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/06 14:09:08 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	if ((unsigned char)c == '\0')
		return (str + i);
	while (i > 0)
	{
		i--;
		if ((unsigned char)str[i] == (unsigned char)c)
			return (str + i);
	}
	return (NULL);
}
