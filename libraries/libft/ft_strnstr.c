/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 08:05:56 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/01 18:01:22 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < len)
		{
			if (to_find[++j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}

/* #include <stdio.h>
int	main (void)
{
	char	str1[] = "helwlo world";
	char	str2[] = "wo";
	printf("result: %s", ft_strnstr(str1, str2, 10));
	return (0);
} */