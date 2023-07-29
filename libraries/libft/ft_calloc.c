/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:39:54 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/01 17:39:25 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = malloc(num * size);
	{
		if (!ptr)
			return (NULL);
		while (i < num * size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}

/* #include <stdio.h>

int	main(void)
{
	printf("my result: %p\n\n", ft_calloc(5, 2));
	printf("orginal result: %p\n", calloc(5, 2));
	return (0);
} */