/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:34:13 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/20 18:02:32 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

char		*ft_reverse(char *str);
int			ft_check_format(const char *format,
				int i, va_list args, int *count);
int			ft_printf(const char *format, ...);
char		*ft_base_hex(unsigned int num, char type);
int			ft_putunsigined_fd(unsigned int n, int fd);
char		*ft_convert_pointer(void *ptr);
int			ft_putnumber_fd(long int n, int fd);
int			ft_putstring_fd(char *s, int fd);
char		*ft_base_ptr(uintptr_t num);
int			ft_putcharacter_fd(char c, int fd);

#endif
