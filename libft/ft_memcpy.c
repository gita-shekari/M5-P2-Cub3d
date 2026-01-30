/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:46:08 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/04 18:18:08 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t				i;

	destination = (unsigned char *)dest;
	source = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
