/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:42:17 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/01 18:00:24 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dst);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[] = "Comoestas";
	char	dst[] = "fdfdfd";
	size_t	len;

	len = 4;
	printf("result is %s\n\n", ft_memcpy(dst, src + 1, len));
	printf("result is %s", memcpy(dst, src + 1, len));
	return (0);
} */