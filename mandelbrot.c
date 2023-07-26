/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:23:28 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/26 13:48:25 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"

/* calculate how many iterations it takes for the Mandelbrot fractal
function to escape the bounded region*/
int	ft_calculate_iterations(double c)
{
	double	z_abs;
	double	z_real;
	double	z_imag;
	int		iter;

	iter = 0;
	while (iter < 1000)
	{
		z_abs = z_real * i + z_imag * i;
		if (z_abs > 2)
			break ;
		(z_real + z_imag) * (z_real + z_imag)
		iter++;
	}
	return (iter);
}
