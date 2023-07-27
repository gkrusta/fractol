/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:23:28 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/27 18:02:54 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 200
#define HEIGHT 200

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		g_img->instances[0].y -= 2;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		g_img->instances[0].x -= 2;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}

double	ft_calculate_c_real(int x)
{
	double	c_real;

	c_real = 3.0 * x / (WIDTH - 1);
	return (-.5 + c_real);
}

double	ft_calculate_c_imag(int y)
{
	double	c_imag;

	c_imag = 3.0 * y / (HEIGHT - 1);
	return (-2.0 + c_imag);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// Function to calculate the color based on the number of iterations
uint32_t	calculate_color(int iter)
{
	uint32_t	color;
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	if (iter <= 10)
		r = 255;
	else if (iter <= 20)
		g = 255;
	else if (iter <= 38)
		b = 255;
	else
	{
		r = 255;
		g = 255;
		b = 255;
	}
	color = r << 16 | g << 8 | b;
	return (color);
}

/* calculate how many iterations it takes for the Mandelbrot fractal
function to escape the bounded region*/
int	ft_calculate_iterations(double c_real, double c_imag)
{
	double	z_abs;
	double	z_real;
	double	z_imag;
	int		iter;

	iter = 0;
	z_real = 0;
	z_imag = 0;
	while (iter < 40) // how far to go?
	{
		z_real = (z_real - z_imag) * (z_real + z_imag) + c_real; //  the real part: 2xyi + c_real 
		z_imag = 2 * z_real * z_imag + c_imag; //  the imaginary part: x^2 - y^2 + c_imag
		/* z_abs = z_real + z_imag; */ // the abosulute: z = x^2 + 2xyi - y^2 + c
		if (z_real > 2 || z_imag > 3)
			break ;
		iter++;
	}
	return (iter);
}

// iterate through every x and y pixel cordinates and find the corresponding c_imag and c_real
int32_t	main(void)
{
	double		c_real;
	double		c_imag;
	int32_t		y;
	int32_t		x;
	int			iterations;
	uint32_t	color;
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MANDELBORT>(", true);

	mlx_set_setting(MLX_MAXIMIZED, true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	/* Do stuff */
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_real = ft_calculate_c_real(x); // coresponding c number: c_real
			c_imag = ft_calculate_c_imag(y); // coresponding c nu,ber: c_imag * i
			iterations = ft_calculate_iterations(c_real, c_imag); // calculate iterations 
			/* printf("iterations: %d\n", iterations); */
			color = calculate_color(iterations);
			/* printf("color is %d\n\n", color); */
			memset(img->pixels, color, x * y * sizeof(int));
			/* mlx_put_pixel(img, x, y, color); */
			x++;
		}
		y++;
	} 
	// Create and display the image.
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	mlx_close_window(mlx);
	return (EXIT_SUCCESS);
}


