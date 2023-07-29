/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:03:33 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/01 18:03:44 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (((char *)&str[i]));
		i--;
	}
	if (c == '\0')
		return (((char *)&str[i]));
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "1234567890";
	unsigned char	c;

	c = '7';
	printf ("the last occurrence of %c is in '%s' is %s \n\n",
		c, str, ft_strchr(str, c));
	printf ("the last occurrence of %c is in '%s' is %s \n\n",
		c, str, strchr(str, c));
	return (0);
} */