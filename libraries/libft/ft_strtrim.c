/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:16:14 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/01 17:51:23 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_cmp(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				break ;
			}
			j++;
		}
		if (j == ft_strlen((char *)set))
			return (i);
		j = 0;
	}
	return (0);
}

static int	end_cmp(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (i > 0)
	{
		while (set[j])
		{
			if (s1[i - 1] == set[j])
			{
				i--;
				break ;
			}
			j++;
		}
		if (j == ft_strlen((char *)set))
			return (i);
		j = 0;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	start;
	size_t	end;

	start = start_cmp(s1, set);
	end = end_cmp(s1, set);
	result = malloc((sizeof(char)) * (end - start + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (end - start > 0)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}

/* #include <stdio.h>
int	main(void)
{
	char const	s1[] = "vaariablenumber var num 123 number variable";
	char const	set[] = "variable";
	printf("result: %s\n", ft_strtrim(s1, set));
	return (0);
} */