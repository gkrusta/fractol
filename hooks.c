/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:21:51 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/24 11:32:16 by gkrusta          ###   ########.fr       */
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

void my_scrollhook(double xdelta, double ydelta, void *param)
{
    t_fractol *f = (t_fractol *)param;
    int32_t mouse_x;
    int32_t mouse_y;
    double movex;
    double movey;

    (void)xdelta; // Unused parameter

    // Get the current mouse position
    mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);

    // Calculate the movement of the fractal based on mouse position
    movex = (mouse_x - WIDTH / 2.0) * f->zoom / WIDTH;
    movey = (mouse_y - HEIGHT / 2.0) * f->zoom / HEIGHT;

    // Adjust the zoom factor
	if (ydelta > 0)
		f->zoom *= 1.1;
	else if (ydelta < 0)
		f->zoom /= 1.1;

    // Adjust the slide parameters based on the new zoom and mouse position
    f->slide_x += movex - (mouse_x - WIDTH / 2.0) * f->zoom / WIDTH;
    f->slide_y += movey - (mouse_y - HEIGHT / 2.0) * f->zoom / HEIGHT;

}

/* 
void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		movex;
	double		movey;

	f = (t_fractol *)param;
	(void)xdelta;
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	mouse_x = 330;
	if (mouse_x < 0 || mouse_x >= WIDTH || mouse_y < 0 || mouse_y >= HEIGHT)
		return ;
	movex = (mouse_x - WIDTH / 2.0) * f->zoom / WIDTH;
	movey = (mouse_y - HEIGHT / 2.0) * f->zoom / HEIGHT;
	if (ydelta > 0)
		f->zoom *= 1.1;
	else if (ydelta < 0)
		f->zoom /= 1.1;
	f->slide_x += movex - (mouse_x - WIDTH / 2.0) * f->zoom / WIDTH;
	f->slide_y += movey - (mouse_y - HEIGHT / 2.0) * f->zoom / HEIGHT;
} */

/* void my_scrollhook(double xdelta, double ydelta, void *param)
{
    t_fractol *f = (t_fractol *)param;
    int cursor_x, cursor_y;
    (void)xdelta;
    mlx_get_mouse_pos(f->mlx, &cursor_x, &cursor_y);
	//printf("mouse is %d and %d \n", cursor_x, cursor_y);
	f->slide_y = 0;
	f->slide_x = 0;
    // Calculate how much to adjust the zoom based on ydelta
    double zoom_factor = 1.0 + (ydelta > 0 ? 0.1 : -0.1);

    // Calculate new slide and zoom based on cursor position
    f->slide_x -= (cursor_x - WIDTH / 2) * (1.0 - zoom_factor) / f->zoom;
	printf("slide x  is %f and %f \n", f->slide_x, zoom_factor);

    f->slide_y -= (cursor_y - HEIGHT / 2) * (1.0 - zoom_factor) / f->zoom;
	printf("slide y  is %f and %f \n", f->slide_y, zoom_factor);

    f->zoom *= zoom_factor;
} */


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
	mlx_scroll_hook(f->mlx, &my_scrollhook, f);
	zooming(f);
	fractol(f);
}