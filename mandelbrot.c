/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:23:28 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/18 20:58:51 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

double	ft_calculate_c_real(double x)
{
	double	c_real;

	c_real = 3.0 * x / (WIDTH - 1);
	return (-2.0 + c_real);
}

double	ft_calculate_c_imag(double y)
{
	double	c_imag;

	c_imag = 3.0 * y / (HEIGHT - 1);
	return (-1.5 + c_imag);
}

/* calculate how many iterations it takes for the Mandelbrot fractal
function to escape the bounded region*/
int	ft_calculate_iterations(double c_real, double c_imag)
{
	double	z_real;
	double	z_imag;
	double	z_real_temp;
	int		iter;

	iter = 0;
	z_real = 0;
	z_imag = 0;
	while (iter < MAX_ITER) // how far to go?
	{
		z_real_temp = z_real;
		z_real = (z_real - z_imag) * (z_real + z_imag) + c_real; //  the real part: x^2 - y^2 + c_imag 
		z_imag = 2 * z_real_temp * z_imag + c_imag; //  the imaginary part: 2xyi + c_real 
		if ((z_real * z_real + z_imag * z_imag) >= 4.0)
			break ;
		iter++;
	}
	return (iter);
}

/* void	make_window(t_fractol *f)
{
	if (f->set == MANDELBROT)
	{
		f->init = mlx_init(WIDTH, HEIGHT, "MANDELBORT", false);
		f->wdw = 
		if (!)
		{
			
		}
	}
	else if (f->set = JULIA)
	{
		if (!)
		{
			
		}
	}
} */

// iterate through every x and y pixel cordinates and find the corresponding c_imag and c_real
int32_t	main(void)
{
	double		c_real;
	double		c_imag;
	double		y;
	double		x;
	int			iterations;
	uint32_t	color;
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MANDELBORT>(", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		exit(EXIT_FAILURE);
	mlx_image_to_window(mlx, img, 0, 0);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_real = ft_calculate_c_real(x); // coresponding c number: c_real
			c_imag = ft_calculate_c_imag(y); // coresponding c number: c_imag * i
			iterations = ft_calculate_iterations(c_real, c_imag); // calculate iterations 
			if (iterations >= MAX_ITER)
				color = get_rgba(0,0,0,255);
			else
				color = calculate_color(iterations);
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx); 
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

/* 
void	ft_calc_mandelbrot(t_fractal *f)
{
	double	temp;

	f->c_re = (f->x - SIZE / 2.0f) * f->zoom / SIZE + f->k;
	f->c_im = (f->y - SIZE / 2.0f) * f->zoom / SIZE + f->h;
	f->z_re = 0;
	f->z_im = 0;
	f->i = 0;
	while (f->z_re * f->z_re + f->z_im * f->z_im < (1 << 8)
		&& f->i < f->max_iter)
	{
		temp = f->z_re * f->z_re - f->z_im * f->z_im + f->c_re;
		f->z_im = f->z_re * f->z_im * 2.0f + f->c_im;
		if (f->z_re == temp && f->i == f->z_im)
		{
			f->i = f->max_iter;
			break ;
		}
		f->z_re = temp;
		f->i++;
	}
	ft_put_pixel(f);
}

void	ft_calc_julia(t_fractal *f)
{
	double	temp;

	f->z_re = (f->x - SIZE / 2.0) * f->zoom / SIZE + f->k;
	f->z_im = (f->y - SIZE / 2.0) * f->zoom / SIZE + f->h;
	f->i = 0;
	while (f->z_re * f->z_re + f->z_im * f->z_im < (1 << 8)
		&& f->i < f->max_iter)
	{
		temp = f->z_re * f->z_re - f->z_im * f->z_im + f->c_re;
		f->z_im = 2.0 * f->z_re * f->z_im + f->c_im;
		if (f->z_re == temp && f->z_im == f->z_im)
		{
			f->i = f->max_iter;
			break ;
		}
		f->z_re = temp;
		f->i++;
	}
	ft_put_pixel(f);
}
 */