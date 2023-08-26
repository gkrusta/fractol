/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:01:09 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/26 17:01:45 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_display(t_fractol *f)
{
	uint32_t	color;

	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			if (f->set == 2)
			{
				f->z_real = ((f->x - WIDTH / 2.0) * f->zoom / WIDTH + f->slide_x); // coresponding c number: c_real
				f->z_imag = ((f->y - HEIGHT / 2.0) * f->zoom / HEIGHT + f->slide_y); // coresponding c number: c_imag * i
			}
			else
			{
				f->c_real = ((f->x - WIDTH / 2.0) * f->zoom / WIDTH + f->slide_x); // coresponding c number: c_real
				f->c_imag = ((f->y - HEIGHT / 2.0) * f->zoom / HEIGHT + f->slide_y); // coresponding c number: c_imag * i
			}
			f->iter = fractol(f);
			color = calculate_color(f);
			mlx_put_pixel(f->g_img, f->x, f->y, color);
			f->x++;
		}
		f->y++;
	}
}
