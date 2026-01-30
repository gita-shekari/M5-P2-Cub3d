/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:52:54 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/03 20:51:40 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*alloc;
	size_t			mul;
	int				int_check;

	int_check = nmemb * size;
	mul = int_check;
	if (nmemb == 0 || size == 0)
	{
		alloc = (void *)malloc(0);
		if (!alloc)
			return (NULL);
		return (alloc);
	}
	if (mul == (nmemb * size))
	{
		alloc = (void *)malloc(size * nmemb);
		if (!alloc)
			return (NULL);
		ft_memset(alloc, 0, mul);
	}
	else
	{
		return (NULL);
	}
	return (alloc);
}
// int main()
// {
// 	void *result = ft_calloc(5466321369446 , 0);
// 	char *res = (char *)result;
// 	if(res)
// 	printf("%s" , res);
// 	else
// 	printf("%s" ,"Error");
// 	return (0);
// }
