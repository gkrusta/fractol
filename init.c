/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:08:35 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/22 13:22:32 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_initialization(t_fractol *f)
{
	f->iter = 0;
	f->max_iter = 24;
	f->x = 0;
	f->y = 0;
	f->lim_x = 4; // adjust later
	f->lim_y = 4; // adjust later
	f->slide_x = -2;
	f->slide_y = -1.9;
	f->z_real = 0;
	f->z_imag = 0;
	f->c_real = 0;
	f->c_imag = 0;
	f->zoom = 1;
	f->color_set = 1;
	f->r = 0;
	f->g = 0;
	f->b = 0;
	if (f->set == 2) // in julia c is a chosen constant
	{
		f->c_real = -0.57;
		f->c_imag = -0.47;
		f->slide_x = -1.7;
		f->slide_y = -1.7;
	}
}

int	main(int argc, char **argv)
{
	t_fractol	*f;

	f = malloc(sizeof(t_fractol));
	f->set = check_argv(argv[1]);
	if (argc == 2 && (f->set == 1 || f->set == 2 || f->set == 3))
	{
		start_initialization(f);
		f->mlx = mlx_init(WIDTH, HEIGHT, choose_set(f->set), false);
		if (!f->mlx)
			exit(EXIT_FAILURE);
		f->g_img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
		if (!f->g_img)
			exit(EXIT_FAILURE);
		fractol(f);
		mlx_image_to_window(f->mlx, f->g_img, 0, 0);
		mlx_loop_hook(f->mlx, &hook, f);
		mlx_loop(f->mlx);
		mlx_delete_image(f->mlx, f->g_img);
		mlx_terminate(f->mlx);
		return (EXIT_SUCCESS);
	}
	return (0);
}