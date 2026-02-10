/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:29:05 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/20 18:11:33 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		str[13];
	long int	num;
	int			i;

	num = (long)n;
	i = 0;
	if (num == 0)
		write(fd, "0", 1);
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num = num / 10;
	}
	str[i] = '\0';
	ft_reverse(str);
	write(fd, str, ft_strlen(str));
}
