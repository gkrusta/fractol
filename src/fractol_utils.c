/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:19:14 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/26 17:40:40 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_initialization(t_fractol *f)
{
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

int	check_argv(const char *set)
{
	int	selection;

	selection = ft_atoi(set);
	if (selection == 1 || selection == 2 || selection == 3)
		return (selection);
	else
	{
		ft_printf("  Chose one of the following numbers:\n");
		ft_printf("  - 1 to show Mandelbrot\n");
		ft_printf("  - 2 to show Julia\n");
		ft_printf("  - 3 to show Burning ship\n");
	}
	return (0);
}

char	*choose_set(int set)
{
	if (set == 1)
		return ("Mandelbrot");
	else if (set == 2)
		return ("Julia");
	else if (set == 3)
		return ("Burning ship");
	else
		return ("Not found");
}

int	check_julia(int argc, char **argv, t_fractol *f)
{
	f->set = check_argv(argv[1]);
	if (f->set == 2 && argc == 4)
	{
		f->c_real = ft_atof(argv[2]);
		f->c_imag = ft_atof(argv[3]);
	}
	else
	{
		ft_printf("  - Julia set requires 2 more arguments formated as a double int\n");
		ft_printf("  - Execution example: ./fractol  2  -0.57  -0.47\n");
		exit (1);
	}
	return (0);
}

void	print_commands(t_fractol *f)
{
	ft_printf("Fractal Visualization Program\n");
	ft_printf("----------------------------\n");
	ft_printf("Available commands:\n");
	ft_printf("  - Arrow keys: Move the fractal\n");
	ft_printf("  - Scroll wheel: Zoom in and out\n");
	ft_printf("  - I/O keys: Increase/decrease zoom at the center only\n");
	ft_printf("  - U/D keys: Increase/decrease iterations\n");
	ft_printf("  - 1/2/3 keys: Change color set\n");
	if (f->set == 2)
		ft_printf("  - 4/5/6/7 keys: Change Julia layout\n");
	ft_printf("  - Space key: Reset to default state\n");
	ft_printf("  - Esc key: Quit the program\n");
}
