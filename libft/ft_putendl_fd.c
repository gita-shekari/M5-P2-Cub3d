/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:58:19 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/07 13:41:00 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// int main()
// {
// 	ft_putendl_fd("HELLO world ", 1);
// 	ft_putendl_fd("", 2);
// 	ft_putendl_fd("difng;kdnmf;kgjdkhn;kdjghdjfkhok", 2);
// 	return (0);
// }
