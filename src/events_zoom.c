/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:24:16 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/26 16:51:35 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zooming(t_fractol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_I))
		f->zoom /= 1.05;
	if (mlx_is_key_down(f->mlx, MLX_KEY_O))
		f->zoom *= 1.05;
}

void my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol *f;
	int32_t mouse_x;
	int32_t mouse_y;
	double movex;
	double movey;

	f = (t_fractol *)param;
	(void)xdelta;
	// Get the current mouse position
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	// Calculate how much the mouse movement affects the fractal position
	movex = (mouse_x - WIDTH / 2.0) * f->zoom / WIDTH;
	movey = (mouse_y - HEIGHT / 2.0) * f->zoom / HEIGHT;
	if (ydelta > 0)
		f->zoom *= 1.1;
	else if (ydelta < 0)
		f->zoom /= 1.1;
	f->slide_x += movex - (mouse_x - WIDTH / 2.0) * f->zoom / WIDTH;
	f->slide_y += movey - (mouse_y - HEIGHT / 2.0) * f->zoom / HEIGHT;
}
