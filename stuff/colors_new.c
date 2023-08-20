/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:57:58 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/20 13:55:54 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// Function to calculate the color based on the number of iterations
uint32_t	calculate_color(t_fractol *f)
{
	t_colors	*color;

	if (f->iter == MAX_ITER)
		return (get_rgba(0, 0, 0, 255)); // Black for points in the set

	color->gradient = (double)f->iter / MAX_ITER; // Calculate a value between 0 and 1
	color->r = (int)(255 * (1 - color->gradient)); // Red component based on t
	color->g = (int)(255 * (1 - color->gradient)); // Green component based on (1 - t)
	color->b = (int)(255); // Blue component based on t

	color->final = get_rgba(color->r, color->g, color->b, 255);
	mlx_put_pixel(f->g_img, f->x, f->y, color->final);
}
 */