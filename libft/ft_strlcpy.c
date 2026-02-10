/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:20:26 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/02 17:47:19 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_size);
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}
	// int main()
	// {
	// 	char str1[20] = "Hello World! jj";
	// 	char tstr1[20] = "Hello World! jj";
	// 	printf("%zu \n", ft_strlcpy(str1, "World", 3));
	// 	printf("%zu \n", strlcpy(tstr1, "World", 3));
	// 	return (0);
	// }
