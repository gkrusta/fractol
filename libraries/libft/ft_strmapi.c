/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:48:54 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/01 14:28:12 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	char		*result;

	i = 0;
	result = (char *)s;
	result = malloc(sizeof(char) * ft_strlen(result) + 1);
	if (!result)
		return (NULL);
	while (i < ft_strlen((char *)(s)))
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* #include <stdio.h>
int	main(void)
{
	printf("result: %s", ft_strmapi("TESTstring", f));
	return (0);
}
char	f(unsigned int i, char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
} */