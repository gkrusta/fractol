/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:45:39 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/01 17:50:27 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && i + j + 1 < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	dest[] = "12345";
	char	src[] = "678";
	printf("result: %zu\n\n", ft_strlcat(dest, src, 1));
	printf("%s\n\n", dest);
	printf("result: %zu\n\n", strlcat(dest, src, 1));
	printf("%s\n\n", dest);
	return (0);
} */