/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:23:28 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/19 12:07:39 by gkrusta          ###   ########.fr       */
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

// Define the constant c for the Julia set
const double julia_c_real = -0.343;
const double julia_c_imag = -0.212;

double	ft_calculate_c_real(double x)
{
	double	c_real;

	c_real = 3.0 * x / (WIDTH - 1);
	return (-1.5 + c_real);
}

double	ft_calculate_c_imag(double y)
{
	double	c_imag;

	c_imag = 3.0 * y / (HEIGHT - 1);
	return (-1.5 + c_imag);
}

// Calculate how many iterations it takes for the Julia fractal to escape the bounded region
int ft_calculate_iterations(double z_real, double z_imag)
{
    int iter = 0;
    while (iter < MAX_ITER)
    {
        double z_real_temp = z_real;
        z_real = z_real * z_real - z_imag * z_imag + julia_c_real; // Real part
        z_imag = 2 * z_real_temp * z_imag + julia_c_imag; // Imaginary part
        if ((z_real * z_real + z_imag * z_imag) >= 4.0)
            break;
        iter++;
    }
    return iter;
}

int32_t main(void)
{
    double y;
    double x;
    int iterations;
    uint32_t color;
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Julia Fractal", false);
    if (!mlx)
        exit(EXIT_FAILURE);
    mlx_image_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img)
        exit(EXIT_FAILURE);
    mlx_image_to_window(mlx, img, 0, 0);
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            double z_real = ft_calculate_c_real(x);
            double z_imag = ft_calculate_c_imag(y);
            iterations = ft_calculate_iterations(z_real, z_imag);
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
