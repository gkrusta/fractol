/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:03:58 by gkrusta           #+#    #+#             */
/*   Updated: 2023/04/24 19:20:56 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_dest;
	char	*ptr_src;
	size_t	i;

	if (src == NULL && dst == NULL)
		return (0);
	i = 0;
	ptr_dest = (char *)dst;
	ptr_src = (char *)src;
	if (ptr_dest > ptr_src)
	{
		while (len-- != 0)
			ptr_dest[len] = ptr_src[len];
	}
	else
	{
		while (i < len)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
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
	printf("result is %s\n\n", ft_memmove(dst, src + 1, len));
	printf("result is %s", memmove(dst, src + 1, len));
	return (0);
} */