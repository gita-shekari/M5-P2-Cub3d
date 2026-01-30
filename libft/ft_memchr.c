/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:02:16 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/04 16:27:41 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	i = 0;
	str = (const unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

// int main()
// {
//     const char *str = "Heello everybody!";
//     if (ft_memchr(str, 'g', 50))
// 	{
// 		printf("%s\n", "Found");
// 	}
// 	else
// 	{
// 		printf("%s\n", "Not found");
// 	}
// 	return (0);
// }
