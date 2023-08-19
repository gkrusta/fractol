/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:00:51 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/19 13:00:47 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// Function to calculate the color based on the number of iterations
/* uint32_t	calculate_color(int iter)
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
 */
// Function to calculate the color based on the number of iterations
uint32_t calculate_color(int iter)
{
    if (iter == MAX_ITER)
        return get_rgba(0, 0, 0, 255); // Black for points in the set

    double t = (double)iter / MAX_ITER; // Calculate a value between 0 and 1

    int r = (int)(255 * (1 - t)); // Red component based on t
    int g = (int)(255 * (1 - t)); // Green component based on (1 - t)
    int b = (int)(255); // Blue component based on t

    return get_rgba(r, g, b, 255);
}
