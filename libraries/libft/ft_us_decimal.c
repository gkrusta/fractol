/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_us_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:51:47 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/13 17:27:09 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_us_decimal(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 10)
	{
		ft_putchar(n + '0');
		i++;
	}
	else
	{
		i++;
		i += ft_us_decimal(n / 10);
		ft_putchar(n % 10 + '0');
	}
	return (i);
}
