/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:52:45 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/05 14:13:33 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	int		i;
	char	*copy;

	i = 0;
	size = ft_strlen(s);
	copy = (char *)malloc(size + 1);
	if (!copy)
		return (0);
	while (i < size + 1)
	{
		copy[i] = s[i];
		i ++;
	}
	return (copy);
}
