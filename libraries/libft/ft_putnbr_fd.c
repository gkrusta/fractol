/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:36:46 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/01 18:01:47 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	l;
	long	nr;

	nr = (long)n;
	if (nr < 0)
	{
		write (fd, "-", 1);
		nr *= (-1);
	}
	if (nr < 10)
	{
		l = (nr + '0');
		write (fd, &l, 1);
	}
	else
	{
		ft_putnbr_fd(nr / 10, fd);
		l = ((nr % 10) + '0');
		write (fd, &l, 1);
	}
}

/* int	main (void)
{
	ft_putnbr_fd(-245, 1);
	return (0);
} */