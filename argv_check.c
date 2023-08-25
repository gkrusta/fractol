/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:19:14 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/25 15:35:03 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_argv(const char *set)
{
	int	selection;

	selection = ft_atoi(set);
	if (selection == 1 || selection == 2 || selection == 3)
		return (selection);
/* 	else if (selection == 2)
	{
		ft_printf("Julia set requires 2 more arguments formated as a double int./n");
		ft_printf("Execution example: ./fractol  1  -0.57  -0.47");
		return (1);
	} */
	else
		return (0);
}

void	print_commands()
{
	ft_printf("Fractal Visualization Program\n");
	ft_printf("----------------------------\n");
	ft_printf("Available commands:\n");
	ft_printf("  - Arrow keys: Move the fractal\n");
	ft_printf("  - Scroll wheel: Zoom in and out\n");
	ft_printf("  - I/O keys: Increase/decrease zoom at the center only\n");
	ft_printf("  - U/D keys: Increase/decrease iterations\n");
	ft_printf("  - 1/2/3 keys: Change color set\n");
	ft_printf("  - Space key: Reset to initial state\n");
	ft_printf("  - Esc key: Quit the program\n");
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