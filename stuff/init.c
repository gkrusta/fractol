/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:08:35 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/19 11:10:39 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_initialization(t_fractol *f)
{
	f->max_iter = 32;
	f->type = set;
	f->x = 0;
	f->y = 0;
	f->z_real = 0;
	f->z_imag = 0;
	f->c_real = 0;
	f->c_imag = 0;
	if (f->set == 2) // in julia c is a chosen constant
	{
		f->c_real = -0.7;
		f->c_imag = 0.27;
	}
}

int	check_argv(char *set)
{
	int	selection;

	selection = ft_atoi(*set);
	if (selection == 1 || selection == 2)
		return (selection);
	else
		return (0);
}

char	*choose_set(int set)
{
	if (set == 1)
		return ("Mandelbrot");
	else if (set == 2)
		return ("Julia");
}

void	mandelbrot(t_fractol *f)
{
	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			f->c_real = ft_calculate_c_real(f->x); // coresponding c number: c_real
			f->c_imag = ft_calculate_c_imag(f->y); // coresponding c number: c_imag * i
			f->iter = ft_calculate_iter(f->c_real, f->c_imag); // calculate iter 
			if (f->iter >= MAX_ITER)
				color = get_rgba(0,0,0,255);
			else
				color = calculate_color(f->iter);
			mlx_put_pixel(f->g_img, f->x, f->y, color);
			f->x++;
		}
		f->y++;
	}
}

int	main(int argc, char **argv)
{
	t_fractol	*f;
	int		set;

	f->set = check_argv(argv[1]);
	if (argc == 2 && (f->set == 1 || f->set == 2))
	{
		start_initialization(f);
		f->mlx = mlx_init(WIDTH, HEIGHT, choose_set(f->set), false);
		if (!f->mlx)
			exit(EXIT_FAILURE);
		f->g_img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
		if (!f->g_img)
			exit(EXIT_FAILURE);
		if (f->set == 1)
			mandelbrot(f);
		else if (f->set == 2)
			julia(f);
		mlx_image_to_window(f->mlx, f->g_img, 0, 0);
		mlx_loop_hook(f->mlx, &hook, f);
		mlx_loop(f->mlx);
		mlx_delete_image(f->mlx, f->g_img);
		mlx_terminate(f->mlx);
		return (EXIT_SUCCESS);
	}
	return (0);
}