/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:58:51 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/03 18:32:25 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main()
// {
// 	ft_putchar_fd('A', 1);
// 	write(1, "\n", 1);
// 	ft_putchar_fd('A', 2);
// 	write(1, "\n", 1);
// 	ft_putchar_fd('A', 3);
// 	return (0);
// }
