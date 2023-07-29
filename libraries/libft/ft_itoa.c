/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:58:11 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/01 17:39:16 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numblen(long n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	nr;

	nr = n;
	if (nr < 0)
		nr *= (-1);
	len = ft_numblen(nr);
	if (n < 0)
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	while (len >= 0)
	{
		result[len--] = nr % 10 + '0';
		nr /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

/* #include <stdio.h>
int	main(void)
{
	printf("result: %s\n\n", ft_itoa(-89578576));
	printf("Size of long on this system: %ld bytes\n", sizeof(long));
	return (0);
} */