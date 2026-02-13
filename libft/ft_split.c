/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshekari <gshekari@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 21:07:18 by gshekari      #+#    #+#                 */
/*   Updated: 2026/02/13 21:23:28 by jingyandong   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	**ft_make_free(char **str, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**ft_fill(char **splitedstr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			splitedstr[j] = ft_substr(s, start, i - start);
			if (!splitedstr[j])
				return (ft_make_free(splitedstr, j));
			j++;
		}
	}
	splitedstr[j] = 0;
	return (splitedstr);
}

char	**ft_split(char const *s, char c)
{
	char	**splitedstr;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_words(s, c);
	splitedstr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!splitedstr)
		return (NULL);
	return (ft_fill(splitedstr, s, c));
}

// int main()
// {
// 	char *str = "......It.is...t.m..y.stri....ng....";
// 	char c = '.';
// 	char **splitedstrs = ft_split(str, c);

// 	if (!splitedstrs)
// 	{
// 		return (0);
// 	}

// 	size_t i = 0;
// 	while (splitedstrs[i])
// 	{
// 		printf("%s\n", splitedstrs[i]);
// 		free(splitedstrs[i]);
// 		i++;
// 	}
// 	free(splitedstrs);
// 	return (0);
// }
