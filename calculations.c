/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:22:37 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/25 16:22:19 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* For Julia set the complex number to be alcualted is z because c is set as a constant.
For Mandelbrot and Burning ship the c will change depending where it is on the complex plane 
determinating the count of the iterations later. */

/*
So the z has x and imaginary y component:
z^2 = (x + yi)*(x + yi) = x^2 + 2xyi- y^2

the multiplication formula for the imaginary part is:
2xyi

the multiplication formula for the real part is: 
x^2 - y^2

In Burning ship fractol absolute value is calculated for the imaginary part:
2(fabs)xyi
*/

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
		f->z_real = ((f->z_real - f->z_imag) * (f->z_real + f->z_imag) + f->c_real);
		if (f->set == 3)
			f->z_imag = 2 * fabs(z_real_temp * f->z_imag) + f->c_imag;
		else
			f->z_imag = (2 * z_real_temp * f->z_imag + f->c_imag);
		if ((f->z_real * f->z_real + f->z_imag * f->z_imag) >= 4.0)
			break ;
		f->iter++;
	}
	return (f->iter);
}
