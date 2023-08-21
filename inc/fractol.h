/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:45:05 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/21 09:10:25 by gkrusta          ###   ########.fr       */
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
# include <stddef.h>

#define WIDTH 1100
#define HEIGHT 1100
#define MAX_ITER 30

typedef struct s_colors {
	int		r;
	int		g;
	int		b;
	int		a;
	uint32_t	final;
	double	gradient;
}	t_colors;

typedef struct s_fractol {
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	int			set;
	void		*init;
	void		*wdw;
	double		z_real;
	double		z_imag;
	double		c_real;
	double		c_imag;
	double		y;
	double		x;
	int			iter;
}	t_fractol;


//uint32_t	calculate_color(t_fractol *f);
uint32_t calculate_color(int iter);
int	get_rgba(int r, int g, int b, int a);
/* void	hook(void *param);
double	ft_calculate_c_real(double x);
double	ft_calculate_c_imag(double y);
int	ft_calculate_iterations(double c_real, double c_imag); */

#endif