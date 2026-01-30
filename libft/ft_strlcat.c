/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:12:45 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/02 17:47:09 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	i = 0;
	if (size <= (dest_size))
		return (size + src_size);
	while (src[i] != '\0' && (dest_size + i) < (size - 1))
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}
// int main()
// {
//     char str1[20] = "Hello World! jj";
// 	char tstr1[20] = "Hello World! jj";
//     printf("%zu \n", ft_strlcat(str1, "World", 20));
//     printf("%zu \n \n", strlcat(tstr1, "World", 20));
//     char str2[20] = "Hello ";
//     printf("%zu \n", ft_strlcat(str2, "World", 20));
//     printf("%zu \n \n", strlcat(str2, "World", 20));
//     char str3[20] = "Hello World!";
//     printf("%zu \n", ft_strlcat(str3, "Test", 10));
//     printf("%zu \n \n", strlcat(str3, "Test", 10));
//     char str4[20] = "Hello ";
//     printf("%zu \n", ft_strlcat(str4, "Some really long string", 20));
//     printf("%zu \n \n", strlcat(str4, "Some really long string", 20));
//     char str5[20] = "";
//     printf("%zu \n", ft_strlcat(str5, "World", 20));
//     printf("%zu \n \n", strlcat(str5, "World", 20));
//     char str6[10] = "Hello";
//     printf("%zu \n", ft_strlcat(str6, "World", 10));
//     printf("%zu \n \n", strlcat(str6, "World", 10));
//     char str7[2] = "A";
// 	printf("%zu \n", ft_strlcat(str7, "B", 2));
//     printf("%zu \n \n", strlcat(str7, "B", 2));
// 	return (0);
// }
