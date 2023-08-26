/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:58:00 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/26 18:07:16 by gkrusta          ###   ########.fr       */
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
	f->r = (int)(255 * (1 - t)); // Red component based on (1 - t)
	f->g = (int)(255 * (1 - t)); // Green component based on (1 - t)
	f->b = (int)(255); // Blue component based on t
	return (get_rgba(f->r, f->g, f->b, 255));
}

/* One example of colors here in calculate_color_pink():
how i got these cool color sets:

- When the iteration count (**`f->iter`**) reaches the maximum iteration value (**`f->max_iter`**), it means that the point did not escape and is within the fractal set.
In this case, the function returns a black color (RGB values: 0, 0, 0) to represent these points.
- For points that did escape and have a finite iteration count, the function calculates a normalized value **`t`** between 0 and 1,
representing the progress of the iteration count from 0 to the maximum value.
- The red (**`f->r`**) and blue (**`f->b`**) color components are calculated using the normalized value **`t`**. As **`t`** approaches 1,
the red and blue components become larger, leading to a lighter shade of pink for higher iteration counts.
- The green (**`f->g`**) color component is calculated using **`(1 - t)`**. As **`t`** approaches 0, **`(1 - t)`** approaches 1,
resulting in a larger green component and contributing to the color gradient.
 */

uint32_t	calculate_color_pink(t_fractol *f)
{
	double	t;

	if (f->iter == f->max_iter)
		return (get_rgba(0, 0, 0, 255));
	t = (double)f->iter / f->max_iter;
	f->r = (int)(255 / t);
	f->g = (int)(255 / (1 - t));
	f->b = (int)(255 / t);
	return (get_rgba(f->r, f->g, f->b, 255));
}

uint32_t	calculate_color_black(t_fractol *f)
{
	double	t;

	if (f->iter == f->max_iter)
		return (get_rgba(0, 0, 0, 255));
	t = (double)f->iter / f->max_iter;
	f->r  = (int)(255 * t);
	f->g = (int)(0);
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

