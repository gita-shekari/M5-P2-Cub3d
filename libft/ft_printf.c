/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:43:12 by gshekari          #+#    #+#             */
/*   Updated: 2025/05/13 14:10:12 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(const char *format, int i, va_list args, int *count)
{
	char	*str;

	if (format[i] == 'c')
		*count += ft_putcharacter_fd(va_arg(args, int), 1);
	else if (format[i] == 's')
		*count += ft_putstring_fd(va_arg(args, char *), 1);
	else if (format[i] == 'p')
	{
		str = ft_convert_pointer(va_arg(args, void *));
		*count += ft_putstring_fd(str, 1);
		free(str);
	}
	else if (format[i] == 'd' || format[i] == 'i')
		*count += ft_putnumber_fd(va_arg(args, int), 1);
	else if (format[i] == 'u')
		*count += ft_putunsigined_fd(va_arg(args, unsigned int), 1);
	else if (format[i] == 'x' || format[i] == 'X')
	{
		str = ft_base_hex(va_arg(args, unsigned int), format[i]);
		*count += ft_putstring_fd(str, 1);
		free(str);
	}
	else if (format[i] == '%')
		*count += ft_putcharacter_fd('%', 1);
	return (i + 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			i = ft_check_format(format, i + 1, args, &count);
		else
		{
			count += ft_putcharacter_fd(format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (count);
}
