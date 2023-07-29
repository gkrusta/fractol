/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:27:48 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/13 17:20:47 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_compare(va_list args, const char c)
{
	int	sol;

	sol = 0;
	if (c == 'c')
		sol += ft_putchar(va_arg(args, int));
	else if (c == 's')
		sol += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		sol += ft_void_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		sol += ft_decimal(va_arg(args, int));
	else if (c == 'u')
		sol += ft_us_decimal(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		sol += ft_hexadec(va_arg(args, unsigned int), c);
	else if (c == '%')
		sol += ft_putchar('%');
	return (sol);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_compare(args, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
