/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:19:14 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/24 12:52:39 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_argv(const char *set)
{
	int	selection;

	selection = ft_atoi(set);
	if (selection == 1 || selection == 2 || selection == 3)
		return (selection);
	else
		return (0);
}

/* void	calculate_set(t_fractol *f)
{
	if (f->set == 1)
		mandelbrot(f);
	else if (f->set == 2)
		mandelbrot(f);
	else if (f->set == 3)
		mandelbrot(f);
} */

void	chose_c_julia(const char *argv, t_fractol *f)
{
	int	c_julia;

	c_julia = ft_atoi(argv);
	if (c_julia == 4)
	{
		f->c_real = -0.57;
		f->c_imag = -0.47;
	}
	else if (c_julia == 5)
	{
		f->c_real = 1.57;
		f->c_imag = 1.47;
	}
	else if (c_julia == 6)
	{
		f->c_real = 0.77;
		f->c_imag = -0.47;
	}
}

char	*choose_set(int set)
{
	if (set == 1)
		return ("Mandelbrot");
	else if (set == 2)
		return ("Julia");
	else if (set == 3)
		return ("Burning ship");
	else
		return ("Not found");
}