/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:45:05 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/18 21:23:19 by gkrusta          ###   ########.fr       */
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
#define MAX_ITER 20

typedef struct s_colors {
	int	r;
	int	g;
	int	b;
	int	a;
}	t_colors;

typedef struct s_fractol {
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	int		max_iter;
	int		type;
	void	*init;
	void	*wdw;
	double	z_real;
	double	z_imag;
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