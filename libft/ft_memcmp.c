/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:46:03 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/05 21:35:48 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// int   main()
// {
// 	printf( "%d expected : -    " , ft_memcmp("Hello" , "Hello Git" , 10));
// 	printf( "%d expected : 0    " , ft_memcmp("Heyrdhr" , "Heyd" , 2));
// 	printf( "%d expected : 0    " , ft_memcmp("Hello Git" , "Hello" , 0));
// 	printf( "%d expected : 32    " , ft_memcmp(" " , "" , 3));
// 	printf( "%d expected : -    " , ft_memcmp("" , "Hello" , 1));
// 	printf( "%d expected : 0    " , ft_memcmp("2535sg8634#" , "" , 0));
// 	return (0);
// }
