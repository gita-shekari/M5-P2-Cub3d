/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:03:12 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/20 18:10:07 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	long		num;
	int			i;
	int			len;

	num = n;
	i = 0;
	len = ft_count_digit(num);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
		num = -num;
	while (num || i == 0)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_reverse(str));
}

// int main()
// {
// 	printf("%s \n" , ft_itoa(-2147483648));
// 	printf("%s \n" , ft_itoa(2147483647));
// 	printf("%s \n" , ft_itoa(0));
// 	return (0);
// }
