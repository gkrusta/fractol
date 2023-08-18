/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:55:53 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/18 15:03:31 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_calculate_c_real(double x)
{
	double	c_real;

	c_real = 3.0 * x / (WIDTH - 1);
	return (-2.0 + c_real);
}

double	ft_calculate_c_imag(double y)
{
	double	c_imag;

	c_imag = 3.0 * y / (HEIGHT - 1);
	return (-1.5 + c_imag);
}

/* calculate how many iterations it takes for the Mandelbrot fractal
function to escape the bounded region*/
int	ft_calculate_iterations(double c_real, double c_imag)
{
	double	z_real;
	double	z_imag;
	double	z_real_temp;
	int		iter;

	iter = 0;
	z_real = 0;
	z_imag = 0;
	while (iter < 34) // how far to go?
	{
		z_real_temp = z_real;
		z_real = (z_real - z_imag) * (z_real + z_imag) + c_real; //  the real part: x^2 - y^2 + c_imag 
		z_imag = 2 * z_real_temp * z_imag + c_imag; //  the imaginary part: 2xyi + c_real 
		if ((z_real * z_real + z_imag * z_imag) >= 4.0)
			break ;
		iter++;
	}
	return (iter);
} 