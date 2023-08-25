/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:21:51 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/25 16:25:10 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	hook(void *param)
{
	t_fractol	*f;

	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	if (mlx_is_key_down(f->mlx, MLX_KEY_SPACE))
	{
		start_initialization(f);
		if (f->set == 2)
		{
			f->c_real = -0.57;
			f->c_imag = -0.47;
		}
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