/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:45:05 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/26 16:56:52 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include <memory.h>
# include <stddef.h>
# include <math.h>

#define WIDTH 900
#define HEIGHT 900

typedef struct s_fractol {
	void		*mlx;
	void		*g_img;
	void		*init;
	double		slide_x;
	double		slide_y;
	int			set;
	double		z_real;
	double		z_imag;
	double		c_real;
	double		c_imag;
	double		y;
	double		x;
	double		zoom;
	int			iter;
	int			max_iter;
	int			color_set;
	int			r;
	int			g;
	int			b;
}				t_fractol;


/* sets color based on number of iterations */
uint32_t	calculate_color(t_fractol *f);
uint32_t	calculate_color_default(t_fractol *f);
uint32_t	calculate_color_pink(t_fractol *f);
uint32_t	calculate_color_black(t_fractol *f);
int			get_rgba(int r, int g, int b, int a);

/* fractol set */
int		fractol(t_fractol *f);

/* calculations */

void		ft_display(t_fractol *f);

/* set */
int			check_argv(const char *set);
char		*choose_set(int set);

/* hooks */
void		hook(void *param);
void		move_with_arrows(t_fractol *f);
void		change_color(t_fractol *f);
void		change_iterations(t_fractol *f);
void		zooming(t_fractol *f);

/* calcualtions */

void		start_initialization(t_fractol *f);
void		zoom(t_fractol *fractal, int x, int y, int zoom);
void		my_scrollhook(double xdelta, double ydelta, void *param);

int			check_julia(int argc, char **argv, t_fractol *f);
void		print_commands(t_fractol *f);
void		set_display(t_fractol *f);

#endif