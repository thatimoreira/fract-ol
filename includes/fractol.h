/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:29:38 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/18 22:56:52 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "../includes/minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <math.h>

# define SIZE 720
# define INVALID_USAGE "Too much or missing parameter(s)!" // Choose a better string
# define INVALID_FRACTAL "Invalid fractal type!" // Choose a better string

# define WIDTH 1000 // squares keep the rendering math simple
# define HEIGHT 1000

typedef struct s_fract // s_data
{
	char	*name;
	int	user_option;
	void	*img;
	char	*addr; // mem address frow where I'm going to change(???) the bytes
	int	bpp; // bits per pixel
	int	line_len;
	int	endian; // used to specify how pixel data is stored or interpreted within an image (check thi case)
}		t_fract;

void	pixel_put(t_fract fract, int x, int y, int color);
t_fract	*validate_input(int n_args, char **args);
void	handle_allocation_failure(void);
void	render_mandelbrot(void *void_fractal);
void	calculate_mandelbrot(t_fract *fractal);
void	render_julia(void *void_fractal, double n1, double n2);
void	calculate_julia(void *void_fractal, double n1, double n2);

#endif
