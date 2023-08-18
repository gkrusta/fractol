/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:45:05 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/18 10:57:31 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/libft/libft.h"
# include <stdio.h>
#include <unistd.h>
# include <math.h>
# include <pthread.h>
#include <memory.h>
#define WIDTH 700
#define HEIGHT 700

typedef struct s_colors {
	int	r;
	int	g;
	int	b;
	int	a;
}	t_colors;

typedef struct s_fractol {
	void	*init;
	void	*wdw;
	double	c_real;
	double	c_imag;
	double	y;
	double	x;
	int		iterations;
}	t_fractol;


uint32_t	calculate_color(int iter);
void	hook(void *param);
double	ft_calculate_c_real(double x);
double	ft_calculate_c_imag(double y);
int	get_rgba(int r, int g, int b, int a);
int	ft_calculate_iterations(double c_real, double c_imag);


#endif