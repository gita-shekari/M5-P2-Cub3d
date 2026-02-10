/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:29:00 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/07 13:40:50 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
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
