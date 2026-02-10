/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:35:38 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/12 20:11:40 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reverse(char *str)
{
	size_t	i;
	char	temp;
	size_t	size;

	size = ft_strlen(str);
	temp = 0;
	i = 0;
	while (i < size / 2)
	{
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
		i++;
	}
	return (str);
}

size_t	ft_hex_len(uintptr_t num, int base)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

char	*ft_base_hex(unsigned int num, char type)
{
	unsigned int	mod;
	unsigned int	i;
	char			*s;

	i = 0;
	s = (char *)malloc((ft_hex_len(num, 16) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (num == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	while (num > 0)
	{
		mod = num % 16;
		if (type == 'x')
			s[i] = "0123456789abcdef"[mod];
		else
			s[i] = "0123456789ABCDEF"[mod];
		num /= 16;
		i++;
	}
	return (s[i] = '\0', ft_reverse(s));
}

char	*ft_convert_pointer(void *ptr)
{
	char	*hex;
	char	*result;

	if (!ptr)
		return (ft_strdup("(nil)"));
	hex = ft_base_ptr((uintptr_t)ptr);
	if (!hex)
		return (NULL);
	result = ft_strjoin("0x", hex);
	free (hex);
	return (result);
}

char	*ft_base_ptr(uintptr_t num)
{
	int		i;
	int		mod;
	char	*s;

	i = 0;
	s = (char *)malloc((ft_hex_len(num, 16) + 1) * sizeof(void *));
	if (!s)
		return (NULL);
	if (num == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	while (num > 0)
	{
		mod = num % 16;
		s[i++] = "0123456789abcdef"[mod];
		num /= 16;
	}
	s[i] = '\0';
	return (ft_reverse(s));
}
