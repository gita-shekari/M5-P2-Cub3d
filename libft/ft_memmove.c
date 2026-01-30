/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:46:12 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/04 19:08:38 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t				i;

	destination = (unsigned char *)dest;
	source = (const unsigned char *)src;
	i = 0;
	if (destination < source)
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	if (destination > source)
	{
		while (n > 0)
		{
			n--;
			destination[n] = source[n];
		}
	}
	return (dest);
}
// int main()
// {
// 	//char str1[] = "Hello world";
// 	char str2[] = "My first String";
// 	//const char str2[] = "world";
// 	//&(str[5]);
// 	//void *result1 = ft_memmove(str1 , "world" , 6);
// 	void *result2 = ft_memmove(str2+10, str2, 5);
// 	//printf("%s \n" ,(char *)result1);
// 	printf("%s \n" ,(char *)result2);
// 	return (0);
// }
