/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:00:51 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/18 12:57:01 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// Function to calculate the color based on the number of iterations
uint32_t	calculate_color(int iter)
{
	uint32_t	color;
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	if (iter <= 3)
		r = 0;
	else if (iter <= 10)
		g = 255;
	else if (iter <= 32)
		b = 255;
	else
	{
		r = 100;
		g = 76;
	}
	color = get_rgba(r, g, b, 255);
	return (color);
}