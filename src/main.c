/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:08:35 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/26 17:43:29 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_display(t_fractol *f)
{
	print_commands(f);
	start_initialization(f);
	f->mlx = mlx_init(WIDTH, HEIGHT, choose_set(f->set), false);
	if (!f->mlx)
		exit(EXIT_FAILURE);
	f->g_img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->g_img)
		exit(EXIT_FAILURE);
	ft_display(f);
	mlx_image_to_window(f->mlx, f->g_img, 0, 0);
	mlx_loop_hook(f->mlx, &hook, f);
	mlx_loop(f->mlx);
	mlx_delete_image(f->mlx, f->g_img);
	mlx_terminate(f->mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	*f;

	f = malloc(sizeof(t_fractol));
	f->set = check_argv(argv[1]);
	if (argc == 2 && f->set == 2)
	{
		f->c_real = -0.57;
		f->c_imag = -0.47;
	}
	else if (argc > 2)
		check_julia(argc, argv, f);
	if (f->set == 1 || f->set == 2 || f->set == 3)
		set_display(f);
	free(f);
	return (0);
}
