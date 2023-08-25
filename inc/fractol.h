/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:45:05 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/25 15:24:02 by gkrusta          ###   ########.fr       */
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
#include <math.h>

#define WIDTH 1100
#define HEIGHT 1100

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

/* typedef struct s_colors {
	int		r;
	int		g;
	int		b;
	uint32_t	final;
	double	gradient;
}	t_colors; */

typedef struct s_fractol {
	void		*mlx;
	mlx_image_t	*g_img;
	double		slide_x; // for arrows ;,)
	double		slide_y;
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
	int			max_iter;
	int			color_set;
	int			r;
	int			g;
	int			b;
}	t_fractol;


/* sets color based on number of iterations */
uint32_t	calculate_color(t_fractol *f);
uint32_t	calculate_color_default(t_fractol *f);
uint32_t	calculate_color_pink(t_fractol *f);
uint32_t	calculate_color_black(t_fractol *f);
int			get_rgba(int r, int g, int b, int a);

/* fractol set */
void	fractol(t_fractol *f);

/* calculations */
double	calculate_real_part(t_fractol *f);
double	calculate_imag_part(t_fractol *f);
int		ft_calculate_iter(t_fractol *f);

/* set */
int		check_argv(const char *set);
/* void	calculate_set(t_fractol *f); */
char	*choose_set(int set);


/* hooks */
void	hook(void *param);
void	move_with_arrows(t_fractol *f);
void	change_color(t_fractol *f);
void	change_iterations(t_fractol *f);
void	zooming(t_fractol *f);

/* calcualtions */
double	calculate_real_part(t_fractol *f);
double	calculate_imag_part(t_fractol *f);
int	ft_calculate_iter(t_fractol *f);

void	start_initialization(t_fractol *f);
//void mouse_scroll_callback(int xdelta, int ydelta, void* param);
void	zoom(t_fractol *fractal, int x, int y, int zoom);
void my_scrollhook(double xdelta, double ydelta, void *param);


void	zoom(t_fractol *fractal, int x, int y, int zoom);
// void	mouse_hook(int mouse_code, int x, int y, t_fractol *fractal);


void	ft_zoom(double x, double y, t_fractol *fractal);
void	ft_dezoom(double x, double y, t_fractol *fractal);
void	mouse_hook(int key_code, int x, int y, t_fractol *fractal);

int		check_julia(int argc, char **argv, t_fractol *f);
void	print_commands();

/* 
void	zoom(t_fractol *fractol, int x, int y, int zoom);
int			key_hook(int key_code, t_fractol *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractol *fractal); */
#endif