/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:33:02 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/20 18:47:34 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joinstr = NULL;
	joinstr = (char *)malloc(len);
	if (!joinstr)
		return (NULL);
	if (s1)
		ft_strlcpy(joinstr, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcat(joinstr, s2, len);
	return (joinstr);
}
