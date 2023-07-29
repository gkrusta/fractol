/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:38:59 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/01 17:50:12 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*s;

	i = 0;
	s = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!s)
		return (0);
	while (i <= ft_strlen(str))
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str[] = "";

	printf ("my result: %s\n", ft_strdup(str));
	printf ("original result: %s\n", strdup(str));
	printf ("my result: %p\n", ft_strdup(str));
	printf ("original result: %p\n", strdup(str));
	return (0);
} */