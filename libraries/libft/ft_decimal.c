/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:51:21 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/13 17:25:24 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_decimal(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= (-1);
		i++;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		i++;
	}
	else
	{
		i++;
		i += ft_decimal(n / 10);
		ft_putchar(n % 10 + '0');
	}	
	return (i);
}
