/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:58:00 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/21 11:54:58 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	calculate_color(int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (get_rgba(0, 0, 0, 255)); // Black for points in the set
	t = (double)iter / MAX_ITER; // Calculate a value between 0 and 1
	r = (int)(255 * (1 - t)); // Red component based on t
	g = (int)(255 * (1 - t)); // Green component based on (1 - t)
	b = (int)(255); // Blue component based on t=
	return (get_rgba(r, g, b, 255));
}