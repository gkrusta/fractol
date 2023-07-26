/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:23:28 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/26 15:39:24 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#define WIDTH 400
#define HEIGHT 400

double	ft_calculate_c_real(int x)
{
	double	c_real;

	c_real = 3.0 * x / (WIDTH - 1);
	return (-1.5 + c_real);
}

double	ft_calculate_c_imag(int y)
{
	double	c_imag;

	c_imag = 3.0 * y / (HEIGHT - 1);
	return (-2.0 + c_imag);
}

/* calculate how many iterations it takes for the Mandelbrot fractal
function to escape the bounded region*/
int	ft_calculate_iterations(double c_real, double c_imag)
{
	double	z_abs;
	double	z_real;
	double	z_imag;
	int		iter;

	iter = 0;
	z_real = 0;
	z_imag = 0;
	while (iter < 500) // how far to go?
	{
		z_real = (z_real - z_imag) * (z_real + z_imag) + c_real; //  the real part: 2xyi + c_real 
		z_imag = 2 * z_real * z_imag + c_imag; //  the imaginary part: x^2 - y^2 + c_imag
		/* z_abs = z_real + z_imag; */ // the abosulute: z = x^2 + 2xyi - y^2 + c
		if (z_real > 2 || z_imag > 3)
			break ;
		iter++;
	}
	return (iter);
}
