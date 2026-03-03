/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshekari <gshekari@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/03 16:29:00 by gshekari      #+#    #+#                 */
/*   Updated: 2026/02/12 16:43:01 by jdong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	write(fd, s, (ft_strlen(s)));
}

// int main()
// {
// 	ft_putstr_fd("HELLO world ", 1);
// 	write(1, "\n", 1);
// 	ft_putstr_fd("", 2);
// 	write(1, "\n", 1);
// 	ft_putstr_fd("difng;kdnmf;kgjdkhn;kdjghdjfkhok", 1);
// 	return (0);
// }
