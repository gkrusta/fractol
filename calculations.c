/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:22:37 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/22 13:22:46 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


double	calculate_real_part(t_fractol *f)
{
	if (f->set == 2)
	{
		f->z_real = 3.4 * f->x / (WIDTH - 1);
		return ((f->slide_x + f->z_real) / f->zoom);
	}
	else
	{
		f->c_real = 3.7 * f->x / (WIDTH - 1);
		return ((f->slide_x + f->c_real) / f->zoom);
	}
}

double	calculate_imag_part(t_fractol *f)
{
	if (f->set == 2)
	{
		f->z_imag = 3.4 * f->y / (HEIGHT - 1);
		return ((f->slide_y + f->z_imag) / f->zoom);
	}
	else
	{
		f->c_imag = 3.7 * f->y / (HEIGHT - 1);
		return ((f->slide_y + f->c_imag) / f->zoom);
	}
}

int	ft_calculate_iter(t_fractol *f)
{
	double	z_real_temp;

	f->iter = 0;
	if (f->set == 1 || f->set == 3)
	{
		f->z_real = 0;
		f->z_imag = 0;
	}
	while (f->iter < f->max_iter)
	{
		z_real_temp = f->z_real;
		f->z_real = ((f->z_real - f->z_imag) * (f->z_real + f->z_imag) + f->c_real); //  the real part: x^2 - y^2 + c_imag 
		if (f->set == 3) // burning ship calculates the absolute value 
			f->z_imag = 2 * fabs(z_real_temp * f->z_imag) + f->c_imag;
		else
			f->z_imag = (2 * z_real_temp * f->z_imag + f->c_imag); //  the imaginary part: 2xyi + c_real 
		if ((f->z_real * f->z_real + f->z_imag * f->z_imag) >= 4.0)
			break ;
		f->iter++;
	}
	return (f->iter);
}
