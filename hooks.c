/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:21:51 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/23 14:50:05 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zooming(t_fractol *f)
{
	if (mlx_is_key_down(f->mlx, MLX_KEY_I))
		f->zoom *= 1.03; // increase zoom by 10%
	if (mlx_is_key_down(f->mlx, MLX_KEY_O))
		f->zoom /= 1.03; // Decrease zoom by 10%
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
		f->slide_y += 0.8;
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
		f->slide_y -= 0.8;
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
		f->slide_x += 0.8;
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
		f->slide_x -= 0.8;
}

/* void mouse_scroll_callback(int xdelta, int ydelta, void* param)
{
    t_fractol *f = (t_fractol *)param;

    // Calculate zoom factor based on the scroll direction
    double zoom_factor = (ydelta > 0) ? 1.03 : 0.97; // Adjust as needed

    // Get the current cursor position
    int32_t cursor_x, cursor_y;
    mlx_get_mouse_pos(f->mlx, &cursor_x, &cursor_y);

    // Calculate new slide_x and slide_y based on cursor position
    f->slide_x = cursor_x - (cursor_x - f->slide_x) * zoom_factor;
    f->slide_y = cursor_y - (cursor_y - f->slide_y) * zoom_factor;

    // Apply zoom
    f->zoom *= zoom_factor;

    // Recalculate and redraw the fractol
    fractol(f);
} */
/* void	mouse_scroll_callback(double xdelta, double ydelta, void* param)
{
	t_fractol *f = (t_fractol *)param;
	int32_t cursor_x, cursor_y;

	// Get the current cursor position
	mlx_get_mouse_pos(f->mlx, &cursor_x, &cursor_y);

	double zoom_factor = 1.05; // Adjust this factor as needed

	if (ydelta > 0)
	{
		f->zoom *= zoom_factor;
		// Adjust the slide_x and slide_y based on cursor position
		f->slide_x -= (cursor_x - WIDTH / 2) * (1.0 - zoom_factor) / f->zoom;
		f->slide_y -= (cursor_y - HEIGHT / 2) * (1.0 - zoom_factor) / f->zoom;
	}
	else if (ydelta < 0)
	{
		f->zoom /= zoom_factor;
		// Adjust the slide_x and slide_y based on cursor position
		f->slide_x += (cursor_x - WIDTH / 2) * (1.0 - 1.0 / zoom_factor) / f->zoom;
		f->slide_y += (cursor_y - HEIGHT / 2) * (1.0 - 1.0 / zoom_factor) / f->zoom;
	}

	// Recalculate and redraw the fractol
	fractol(f);
} */

void	mouse_scroll(t_fractol *fractal, double x, double y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->slide_x = (x / fractal->zoom + fractal->slide_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->slide_y = (y / fractal->zoom + fractal->slide_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->slide_x = (x / fractal->zoom + fractal->slide_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->slide_y = (y / fractal->zoom + fractal->slide_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

void mlx_scroll_callback(double xdelta, double ydelta, void* param)
{
    t_fractol* f = (t_fractol*)param;

    // Call your original mouse_scroll function with the correct arguments
    if (ydelta > 0)
        mouse_scroll(4, xdelta, ydelta, f); // Zoom in
    else if (ydelta < 0)
        mouse_scroll(5, xdelta, ydelta, f); // Zoom out
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
	move_with_arrows(f);
	change_color(f);
	change_iterations(f);
	zooming(f);
	mlx_scroll_hook(f->mlx, mouse_scroll, f);
	fractol(f);
}