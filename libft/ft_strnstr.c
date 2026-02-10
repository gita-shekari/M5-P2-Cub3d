/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:20:14 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/02 17:47:52 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] && big[i + j]
			&& (i + j) < len && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// int   main()
// {
// 	printf( "%s \n" , ft_strnstr("Hello World! jj","World" , 20));
// 	printf( "%s \n" , ft_strnstr("bananananana test","nana" , 50));
// 	printf( "%s \n" , ft_strnstr("World!","World" , 1));
// 	return (0);
// }
