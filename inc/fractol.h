/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:45:05 by gkrusta           #+#    #+#             */
/*   Updated: 2023/08/17 12:50:32 by gkrusta          ###   ########.fr       */
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
#define WIDTH 600
#define HEIGHT 600å


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