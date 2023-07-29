/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:34:17 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/20 14:20:10 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_len(char const *s, char c, int i)
{
	unsigned int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free(char **str, int str_ind)
{
	while (str_ind-- > 0)
		free(str[str_ind]);
	free (str);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	i;
	unsigned int	str_ind;

	i = 0;
	str_ind = -1;
	str = malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!str)
		return (NULL);
	while (++str_ind < ft_counter(s, c))
	{
		while (s[i] == c)
			i++;
		str[str_ind] = ft_substr(s, i, ft_len(s, c, i));
		if (!(str[str_ind]))
		{
			ft_free(str, str_ind);
			return (0);
		}
		i += ft_len(s, c, i) + 1;
	}
	str[str_ind] = 0;
	return (str);
}

/* #include <stdio.h>
int	main(void)
{
	char const	s[] = "abc**def*****43*fdfds****";
	char	c = '*';
	int	i = 0;
	char	**result = ft_split(s, c);

	while (i < ft_counter(s, c))
	{
		printf ("result: %s\n", result[i]);
		i++;
	}
	return (0);
} */