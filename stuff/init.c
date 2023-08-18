/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:08:35 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/18 21:25:58 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	start_initialization(void)
{
	t_fractol	*f;

	f->max_iter = 32;
	f->type = f_set;
	f->x = 0;
	f->y = 0;
	f->z_real = 0;
	f->z_imag = 0;
	if (f_set == 2) // in julia c is a chosen constant
	{
		f->c_real = -0.7;
		f->c_imag = 0.27;
	}
}

int	check_argv(char set)
{
	int	selection;

	selection = ft_atoi(set);
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

int	main(int argc, char **argv)
{
	t_fractol	*f;
	int			f_set;

	f_set = check_argv(argv[1]);
	if (argc == 2 && (f_set == 1 || f_set == 2))
	{
		f = start_initialization();
		f->mlx = mlx_init(WIDTF, HIGHT, choose_set(f_set), false);
		if (!mlx)
			exit(EXIT_FAILURE);
		f->img = mlx_new_image(mlx, WIDTH, HEIGHT);
		if (!img)
			exit(EXIT_FAILURE);
		mlx_image_to_window(mlx, img, 0, 0);
	}
	return (0);
}