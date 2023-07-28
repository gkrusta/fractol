/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:45:05 by gkrusta           #+#    #+#             */
/*   Updated: 2023/07/28 12:47:28 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



typedef struct s_fractol {
	void	*mlx;
	double	c_real;
	double	c_imag;
	double	y;
	double	x;
	int		iterations;
}	t_fractol;