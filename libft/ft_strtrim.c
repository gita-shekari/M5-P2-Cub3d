/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:12:12 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/08 16:31:31 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimstr;

	end = ft_strlen(s1) - 1 ;
	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	trimstr = ft_substr(s1, start, end - start + 1);
	return (trimstr);
}
// #include <stdio.h>
// int main()
// {
// 	char str1[] = "It	is my string";
// 	char *set = NULL;
// 	printf("%s" , ft_strtrim(str1 , set));
// 	return (0);

// }
