/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:21:51 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/24 17:02:48 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zooming(t_fractol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_I))
		f->zoom /= 1.05; // increase zoom by 10%
	if (mlx_is_key_down(f->mlx, MLX_KEY_O))
		f->zoom *= 1.05; // Decrease zoom by 10%
}

void	change_iterations(t_fractol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_U))
		f->max_iter += 1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_D))
		f->max_iter -= 1;
}

void	change_color(t_fractol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_1))
		f->color_set = 1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_2))
		f->color_set = 2;
	if (mlx_is_key_down(f->mlx, MLX_KEY_3))
		f->color_set = 3;
}

void	move_with_arrows(t_fractol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
		f->slide_y -= 0.3;
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
		f->slide_y += 0.3;
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
		f->slide_x -= 0.3;
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
		f->slide_x += 0.3;
}

void	chose_c_julia(t_fractol *f)
{
	if (f->set == 2)
	{
		if (mlx_is_key_down(f->mlx, MLX_KEY_4))
		{
			f->c_real = -0.57;
			f->c_imag = -0.47;
		}
		if (mlx_is_key_down(f->mlx, MLX_KEY_5))
		{
			f->c_real = -1.0;
			f->c_imag = 0.0;
		}
		if (mlx_is_key_down(f->mlx, MLX_KEY_6))
		{
			f->c_real = 0.33;
			f->c_imag = -0.43;
		}
		if (mlx_is_key_down(f->mlx, MLX_KEY_7))
		{
			f->c_real = -0.112;
			f->c_imag = -0.742;
		}
	}
}

void my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol *f = (t_fractol *)param;
	int32_t mouse_x;
	int32_t mouse_y;
	double movex;
	double movey;

	(void)xdelta;
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	movex = (mouse_x - WIDTH / 2.0) * f->zoom ;
	movey = (mouse_y - HEIGHT / 2.0) * f->zoom;
	if (ydelta > 0)
		f->zoom *= 1.1;
	else if (ydelta < 0)
		f->zoom /= 1.1;
	f->slide_x += movex - (mouse_x - WIDTH / 2.0) * f->zoom / WIDTH;
	f->slide_y += movey - (mouse_y - HEIGHT / 2.0) * f->zoom / HEIGHT;
}

void	hook(void *param)
{
	t_fractol	*f;

	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	if (mlx_is_key_down(f->mlx, MLX_KEY_SPACE))
	{
		start_initialization(f);
		fractol(f);
	}
	chose_c_julia(f);
	move_with_arrows(f);
	change_color(f);
	change_iterations(f);
	mlx_scroll_hook(f->mlx, &my_scrollhook, f);
	zooming(f);
	fractol(f);
}