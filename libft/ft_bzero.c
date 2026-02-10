/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:06:40 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/04 16:56:33 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
// int main()
// {
// 	unsigned char str[] = "123456789sigkna;krg";
// 	ft_bzero(str, 5);
// 	int j = 0;
// 	while(j < sizeof(str)-1)
// 	{
// 		if(str[j] == 0)
// 			printf("%s" , "\\0");
// 		else
// 			printf("%c" , str[j]);
// 		j++;
// 	}
// 	return (0);
// }
