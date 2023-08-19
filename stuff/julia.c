/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:55:53 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/19 10:43:35 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_calculate_iterations(double c_real, double c_imag)
{
	double	f->z_real_temp;
	int		f->iter;

	iter = 0;
	f->z_real = f->c_real;
	f->z_imag = f->c_imag;
	while (t->iter < MAX_ITER)
	{
		f->z_real_temp = z_real;
		z_real = (z_real - z_imag) * (z_real + z_imag) + c_real; //  the real part: x^2 - y^2 + c_imag 
		z_imag = 2 * z_real_temp * z_imag + c_imag; //  the imaginary part: 2xyi + c_real 
		if ((z_real * z_real + z_imag * z_imag) >= 4.0)
			break ;
		f->iter++;
	}
	return (iter);
} 