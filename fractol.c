/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:01:09 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/21 18:34:53 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol(t_fractol *f)
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
				f->z_real = calculate_real_part(f); // coresponding c number: c_real
				f->z_imag = calculate_imag_part(f); // coresponding c number: c_imag * i
			}
			else
			{
				f->c_real = calculate_real_part(f); // coresponding c number: c_real
				//printf("c real is %f\n", f->c_real);
				f->c_imag = calculate_imag_part(f); // coresponding c number: c_imag * i
				//printf("c imag is %f\n", f->c_imag); 
			}
			f->iter = ft_calculate_iter(f); // calculate iter 
			//printf ("iterations: %d\n", f->iter);
			color = calculate_color(f);
			mlx_put_pixel(f->g_img, f->x, f->y, color);
			f->x++;
		}
		f->y++;
	}
}
/* 
void	julia(t_fractol *f)
{
	uint32_t	color;

	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			f->z_real = calculate_real_part(f); // coresponding c number: c_real
			f->z_imag = calculate_imag_part(f); // coresponding c number: c_imag * i
			f->iter = ft_calculate_iter(f); // calculate iter 
			color = calculate_color(f);
			mlx_put_pixel(f->g_img, f->x, f->y, color);
			f->x++;
		}
		f->y++;
	}
}

// ADD ALL THESE 3 INTO ONE !

void	burning_ship(t_fractol *f)
{
	uint32_t	color;

	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			f->c_real = calculate_real_part(f); // corresponding c number: c_real
			f->c_imag = calculate_imag_part(f); // corresponding c number: c_imag * i
			f->iter = ft_calculate_iter(f); // calculate iter 
			color = calculate_color(f);
			mlx_put_pixel(f->g_img, f->x, f->y, color);
			f->x++;
		}
		f->y++;
	}
}
 */