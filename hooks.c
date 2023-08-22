/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:21:51 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/22 13:31:36 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zooming(t_fractol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_I))
		f->zoom *= 1.05; // increase zoom by 10%
	if (mlx_is_key_down(f->mlx, MLX_KEY_O))
		f->zoom /= 1.05; // Decrease zoom by 10%
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
		f->slide_y -= 0.5;
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
		f->slide_y += 0.5;
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
		f->slide_x -= 0.5;
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
		f->slide_x += 0.5;
	fractol(f);
}

void	hook(void *param)
{
	t_fractol	*f;

	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	move_with_arrows(f);
	change_color(f);
	change_iterations(f);
	zooming(f);
}