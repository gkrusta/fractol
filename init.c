/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:08:35 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/18 15:57:05 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_initialization(t_fractol *f, int f_set)
{
	f->max_iter = 32;
	f->type = f_set;
	if (f_set == 2) // in julia c is a chosen constant
	{
		f->c_real = -0.7;
		f->c_imag = 0.27;
	}
}

int	check_argv(char set)
{
	int	selection;

	selection = ft_atoi(set);
	if (selection == 1 || selection == 2)
		return (selection);
	else
		return (0);
}

char	*choose_set(int set)
{
	if (set == 1)
		return ("Mandelbrot");
	else if (set == 2)
		return ("Julia");
}

int	main(int argc, char **argv)
{
	int			f_set;
	t_fractol	*f;
	f_set = check_argv(argv[1]);
	if (argc == 2 && (f_set == 1 || f_set == 2))
	{
		f = start_initialization(f, f_set);
	}
	return (0);
}