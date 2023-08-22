/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:58:00 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/22 13:08:17 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	calculate_color_default(t_fractol *f)
{
	double	t;

	if (f->iter == f->max_iter)
		return (get_rgba(0, 0, 0, 255)); // Black for points in the set
	t = (double)f->iter / f->max_iter; // Calculate a value between 0 and 1
	f->r = (int)(255 * (1 - t)); // Red component based on t
	f->g = (int)(255 * (1 - t)); // Green component based on (1 - t)
	f->b = (int)(255); // Blue component based on t
	return (get_rgba(f->r, f->g, f->b, 255));
}

uint32_t	calculate_color_pink(t_fractol *f)
{
	double	t;

	if (f->iter == f->max_iter)
		return (get_rgba(0, 0, 0, 255));
	t = (double)f->iter / f->max_iter;
	f->r = (int)(255 * t);
	f->g = (int)(255 * (1 - t));
	f->b = (int)(255);
	return (get_rgba(f->r, f->g, f->b, 255));
}

uint32_t	calculate_color_black(t_fractol *f)
{
	double	t;

	if (f->iter == f->max_iter)
		return (get_rgba(0, 0, 0, 255));
	t = (double)f->iter / f->max_iter;
	f->r = (int)(255 * t);
	f->g = (int)(255 * t);
	f->b = (int)(255 * t);
	return (get_rgba(f->r, f->g, f->b, 255));
}

uint32_t	calculate_color(t_fractol *f)
{
	if (f->color_set == 1)
		return (calculate_color_default(f));
	else if (f->color_set == 2)
		return (calculate_color_pink(f));
	else if (f->color_set == 3)
		return (calculate_color_black(f));
	else
		exit (1);
}

