/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:08:35 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/25 15:53:40 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_initialization(t_fractol *f)
{
	if (f->set == 2 && isnan(f->c_real) && isnan(f->c_imag)) // if the constant hasn't been defined
	{
		f->c_real = -0.57;
		f->c_imag = -0.47;
	}
	f->iter = 0;
	f->max_iter = 24;
	f->x = 0;
	f->y = 0;
	f->slide_x = 0;
	f->slide_y = 0;
	f->z_real = 0;
	f->z_imag = 0;
	if (f->set == 1 || f->set == 3)
	{
		f->c_real = 0;
		f->c_imag = 0;
	}
	f->zoom = 4.0;
	f->color_set = 1;
	f->r = 0;
	f->g = 0;
	f->b = 0;
}

void   ft_leaks(void)
{
    system("leaks -q fractol");
}

int	check_julia(int argc, char **argv, t_fractol *f)
{
	f->set = check_argv(argv[1]);
	if (f->set == 2 && argc == 4)
	{
		f->c_real = atof(argv[2]);
		f->c_imag = atof(argv[3]);
		printf("c ral is %f and c imag is %f \n", f->c_real, f->c_imag);
	}
	else
	{
		ft_printf("  - Julia set requires 2 more arguments formated as a double int\n");
		ft_printf("  - Execution example: ./fractol  1  -0.57  -0.47\n");
		exit (1);
	}
	return (0);
}

/* void	julia_c_management(t_fractol *f)
{
	
} */

int	main(int argc, char **argv)
{
	atexit(ft_leaks); 
	t_fractol	*f;

	f = malloc(sizeof(t_fractol));
	if (argc == 2)
		f->set = check_argv(argv[1]);
	if (argc > 2)
		check_julia(argc, argv, f);
	if (f->set == 1 || f->set == 2 || f->set == 3)
	{
		print_commands();
		start_initialization(f);
		f->mlx = mlx_init(WIDTH, HEIGHT, choose_set(f->set), true);
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
	}
	free(f);
	return (0);
}