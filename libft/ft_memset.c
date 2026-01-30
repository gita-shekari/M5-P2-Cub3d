/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:46:16 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/04 19:53:15 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

// int main()
// {
// 	char str[] = "Hey hey hey";

// 	void *result = ft_memset(str , 'q', 5);
// 	unsigned char *res = (unsigned char *)result;
// 	printf("%s \n" ,res);

// 	return (0);
// }
