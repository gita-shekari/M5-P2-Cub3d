/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:59:17 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/02 17:47:58 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(1);
		if (!substr)
			return (NULL);
		return (substr[i] = '\0', substr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr[i] = '\0', substr);
}

// int main()
// {
// 	char str1[] = "It is my string";
// 	printf("1: %s\n" , ft_substr(str1 , 9, 15));
// 	char str2[] = "";
// 	printf("2:%s\n" , ft_substr(str2 , 7 , 6));
// 	char str3[] = "It is.my string";
// 	printf("3:%s\n" , ft_substr(str3 , 0 , 6));
// 	char str4[] = "Itismystring";
// 	printf("4:%s\n" , ft_substr(str4 , 11 , 3));
// 	char str5[] = "It is mystring";
// 	printf("5:%s\n" , ft_substr(str5 , 25 , 3));
// 	return ();
// }
