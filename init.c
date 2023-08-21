/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:08:35 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/21 12:37:45 by gkrusta          ###   ########.fr       */
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
	if (mlx_is_key_down(f->mlx, MLX_KEY_I))
		f->zoom *= 1.1; // increase zoom by 10%
	if (mlx_is_key_down(f->mlx, MLX_KEY_O))
		f->zoom /= 1.1; // Decrease zoom by 10%
	calculate_set(f);
}

void	start_initialization(t_fractol *f)
{
	f->iter = 0;
	f->x = 0;
	f->y = 0;
	f->lim_x = 4; // adjust later
	f->lim_y = 4; // adjust later
	f->z_real = 0;
	f->z_imag = 0;
	f->c_real = 0;
	f->c_imag = 0;
	f->zoom = 1.0;
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
		f->c_real = 3.4 * f->x / (WIDTH - 1) ;
		return ((-2.0 + f->c_real) / f->zoom);
	}
	else
	{
		f->z_real = 3.4 * f->x / (WIDTH - 1);
		return ((-1.7 + f->z_real) / f->zoom);
	}
}

double	calculate_imag_part(t_fractol *f)
{
	if (f->set == 1)
	{
		f->c_imag = 3.4 * f->y / (HEIGHT - 1) ;
		return ((-1.5 + f->c_imag) / f->zoom);
	}
	else
	{
		f->z_imag = 3.4 * f->y / (HEIGHT - 1);
		return ((-1.7 + f->z_imag) / f->zoom);
	}
}

int	ft_calculate_iter(t_fractol *f)
{
	double	z_real_temp;

	f->iter = 0;
	if (f->set == 1)
	{
		f->z_real = 0;
		f->z_imag = 0;
	}
	while (f->iter < MAX_ITER)
	{
		z_real_temp = f->z_real;
		f->z_real = ((f->z_real - f->z_imag) * (f->z_real + f->z_imag) + f->c_real); //  the real part: x^2 - y^2 + c_imag 
		f->z_imag = (2 * z_real_temp * f->z_imag + f->c_imag); //  the imaginary part: 2xyi + c_real 
		if ((f->z_real * f->z_real + f->z_imag * f->z_imag) >= 4.0)
			break ;
		f->iter++;
	}
	return (f->iter);
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