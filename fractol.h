/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:45:05 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/29 16:57:47 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define WIDTH 128
#define HEIGHT 128

# include "libraries/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "libraries/libft/libft.h"

typedef struct s_fractol {
	void	*init;
	void	*wdw;
	double	c_real;
	double	c_imag;
	double	y;
	double	x;
	int		iterations;
}	t_fractol;

#endif