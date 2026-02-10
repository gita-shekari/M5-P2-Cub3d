/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:33:23 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/13 14:12:38 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnumber_fd(long int n, int fd)
{
	char	str[21];
	int		i;
	long	num;
	int		count;

	count = 0;
	i = 0;
	num = n;
	if (num == 0)
		return (write(fd, "0", 1), 1);
	if (num < 0)
	{
		write(fd, "-", 1);
		count++;
		num = -num;
	}
	while (num > 0)
	{
		str[i++] = (num % 10) + '0';
		num = num / 10;
	}
	str[i] = '\0';
	write(fd, ft_reverse(str), i);
	return (count + i);
}

int	ft_putstring_fd(char *s, int fd)
{
	int	count;

	if (!s)
	{
		write(fd, "(null)", 6);
		count = 6;
		return (count);
	}
	count = ft_strlen(s);
	write(fd, s, count);
	return (count);
}

int	ft_putunsigined_fd(unsigned int n, int fd)
{
	char	str[32];
	int		i;

	i = 0;
	if (n == 0)
		return (write(fd, "0", 1), 1);
	while (n)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	str[i] = '\0';
	ft_reverse(str);
	write(fd, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_putcharacter_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
