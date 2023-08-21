/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:08:35 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/21 09:30:06 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
} */


void	hook(void *param)
{
	t_fractol	*f;

	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
}

void	start_initialization(t_fractol *f)
{
	f->iter = 0;
	f->x = 0;
	f->y = 0;
	f->z_real = 0;
	f->z_imag = 0;
	f->c_real = 0;
	f->c_imag = 0;
	if (f->set == 2) // in julia c is a chosen constant
	{
		f->c_real = -0.57;
		f->c_imag = -0.47;
	}
}

double	calculate_real_part(t_fractol *f)
{
	if (f->set == 1)
	{
		f->c_real = 3.4 * f->x / (WIDTH - 1);
		return (-2.0 + f->c_real);
	}
	else
	{
		f->z_real = 3.4 * f->x / (WIDTH - 1);
		return (-1.7 + f->z_real);
	}
}

double	calculate_imag_part(t_fractol *f)
{
	if (f->set == 1)
	{
		f->c_imag = 3.4 * f->y / (HEIGHT - 1);
		return (-1.5 + f->c_imag);
	}
	else
	{
		f->z_imag = 3.4 * f->y / (HEIGHT - 1);
		return (-1.7 + f->z_imag);
	}
}

int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_calculate_iter(t_fractol *f)
{
	double	z_real_temp;

	//printf ("iterations: 2222");
	f->iter = 0;
	if (f->set == 1)
	{
		f->z_real = 0;
		f->z_imag = 0;
	}
	while (f->iter < MAX_ITER)
	{
		z_real_temp = f->z_real;
		f->z_real = (f->z_real - f->z_imag) * (f->z_real + f->z_imag) + f->c_real; //  the real part: x^2 - y^2 + c_imag 
		f->z_imag = 2 * z_real_temp * f->z_imag + f->c_imag; //  the imaginary part: 2xyi + c_real 
		if ((f->z_real * f->z_real + f->z_imag * f->z_imag) >= 4.0)
			break ;
		f->iter++;
	}
	return (f->iter);
}

// Function to calculate the color based on the number of iterations
/* void	calculate_color(t_fractol *f)
{
	t_colors	*color;

	color = malloc(sizeof(t_colors));
	if (f->iter == MAX_ITER)
		color->final = get_rgba(0, 0, 0, 255); // Black for points in the set
	color->gradient = (double)f->iter / MAX_ITER; // Calculate a value between 0 and 1
	color->r = (int)(255 * (1 - color->gradient)); // Red component based on t
	color->g = (int)(255 * (1 - color->gradient)); // Green component based on (1 - t)
	color->b = (int)(255); // Blue component based on t
	printf("colors %d %d %d\n", color->r, color->g, color->b);
	color->final = get_rgba(color->r, color->g, color->b, 255);
	mlx_put_pixel(f->g_img, f->x, f->y, color->final);
} */

/* t_colors calculate_color(t_fractol *f)
{
	t_colors color;

	if (f->iter == MAX_ITER)
	{
		color.final = get_rgba(0, 0, 0, 255); // Black for points in the set
		return color;
	}

	color.gradient = (double)f->iter / MAX_ITER; // Calculate a value between 0 and 1
	color.r = (int)(255 * (1 - color.gradient)); // Red component based on t
	color.g = (int)(255 * (1 - color.gradient)); // Green component based on (1 - t)
	color.b = (int)(255); // Blue component based on t
	color.final = get_rgba(color.r, color.g, color.b, 255);

	return color;
}
 */

uint32_t calculate_color(int iter)
{
	if (iter == MAX_ITER)
		return (get_rgba(0, 0, 0, 255)); // Black for points in the set

	double t = (double)iter / MAX_ITER; // Calculate a value between 0 and 1

	int r = (int)(255 * (1 - t)); // Red component based on t
	int g = (int)(255 * (1 - t)); // Green component based on (1 - t)
	int b = (int)(255); // Blue component based on t

	return (get_rgba(r, g, b, 255));
}

int	check_argv(const char *set)
{
	int	selection;

	selection = ft_atoi(set);
	if (selection == 1 || selection == 2)
		return (selection);
	else
		return (0);
}

char	*choose_set(int set)
{
	if (set == 1)
		return ("Mandelbrot");
	else if (set == 2)
		return ("Julia");
	else
		return ("Not found");
}

void	mandelbrot(t_fractol *f)
{
	uint32_t	color;

	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			f->c_real = calculate_real_part(f); // coresponding c number: c_real
			//printf("c real is %f\n", f->c_real);
			f->c_imag = calculate_imag_part(f); // coresponding c number: c_imag * i
			//printf("c imag is %f\n", f->c_imag);
			f->iter = ft_calculate_iter(f); // calculate iter 
			//printf ("iterations: %d\n", f->iter);
			color = calculate_color(f->iter);
			mlx_put_pixel(f->g_img, f->x, f->y, color);
			f->x++;
		}
		f->y++;
	}
}

void	julia(t_fractol *f)
{
	uint32_t	color;

	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			f->z_real = calculate_real_part(f); // coresponding c number: c_real
			f->z_imag = calculate_imag_part(f); // coresponding c number: c_imag * i
			f->iter = ft_calculate_iter(f); // calculate iter 
			color = calculate_color(f->iter);
			mlx_put_pixel(f->g_img, f->x, f->y, color);
			f->x++;
		}
		f->y++;
	}
}

void	calculate_set(t_fractol *f)
{
	if (f->set == 1)
		mandelbrot(f);
	else if (f->set == 2)
		julia(f);
/* 	else if (f->set = 3)
		burning_ship(f); */
}

int	main(int argc, char **argv)
{
	t_fractol	*f;

	f = malloc(sizeof(t_fractol));
	f->set = check_argv(argv[1]);
	if (argc == 2 && (f->set == 1 || f->set == 2))
	{
		start_initialization(f);
		f->mlx = mlx_init(WIDTH, HEIGHT, choose_set(f->set), false);
		if (!f->mlx)
			exit(EXIT_FAILURE);
		f->g_img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
		if (!f->g_img)
			exit(EXIT_FAILURE);
		calculate_set(f);
		mlx_image_to_window(f->mlx, f->g_img, 0, 0);
		mlx_loop_hook(f->mlx, &hook, f);
		mlx_loop(f->mlx);
		mlx_delete_image(f->mlx, f->g_img);
		mlx_terminate(f->mlx);
		return (EXIT_SUCCESS);
	}
	return (0);
}