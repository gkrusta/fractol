/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:45:05 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/21 11:58:39 by gkrusta          ###   ########.fr       */
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
	double		lim_x;
	double		lim_y;
	double		zoom;
	int			iter;
}	t_fractol;


/* sets color based on number of iterations */
uint32_t	calculate_color(int iter);
int			get_rgba(int r, int g, int b, int a);

/* fractol sets */
void	mandelbrot(t_fractol *f);
void	julia(t_fractol *f);

/* calculations */
double	calculate_real_part(t_fractol *f);
double	calculate_imag_part(t_fractol *f);
int		ft_calculate_iter(t_fractol *f);

/* set */
int		check_argv(const char *set);
void	calculate_set(t_fractol *f);
char	*choose_set(int set);

#endif