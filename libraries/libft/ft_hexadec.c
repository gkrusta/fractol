/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:15:44 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/13 17:25:31 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexadec(unsigned long long n, char c)
{
	unsigned int	i;

	i = 0;
	if (n < 16)
	{
		if (c == 'x')
			i += ft_putchar("0123456789abcdef"[n % 16]);
		else
			i += ft_putchar("0123456789ABCDEF"[n % 16]);
	}
	else
	{
		i += ft_hexadec(n / 16, c);
		if (c == 'x')
			i += ft_putchar("0123456789abcdef"[n % 16]);
		else
			i += ft_putchar("0123456789ABCDEF"[n % 16]);
	}
	return (i);
}
