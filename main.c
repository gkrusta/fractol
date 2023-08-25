/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:08:35 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/25 16:26:39 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void   ft_leaks(void)
{
    system("leaks -q fractol");
}

void	set_display(t_fractol *f)
{
	print_commands(f);
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

int	main(int argc, char **argv)
{
	atexit(ft_leaks); 
	t_fractol	*f;

	f = malloc(sizeof(t_fractol));
	if (argc == 2)
		f->set = check_argv(argv[1]);
	else if (argc > 2)
		check_julia(argc, argv, f);
	if (f->set == 1 || f->set == 2 || f->set == 3)
		set_display(f);
	free(f);
	return (0);
}