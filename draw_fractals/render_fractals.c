/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:15:55 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/23 02:29:01 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Implements functions for rendering fractals images

void	render_fractals(t_fract *fractal)
{
    int     x; // current pixel
    int     y; // current pixel

    x = 0;
    y = -1;
    // pass all the coordinates are in the range
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            if (fractal->user_option == 1)
            {
                fractal->x = x;
                fractal->y = y;
                calculate_mandelbrot(x, y, fractal);
            }
            /*
            else if (fractal->user_option == 2)
            {   
                fractal->x = x;
                fractal->y = y;
                calculate_julia(fractal, fractal->zx, fractal->zy);
            }
            */
            mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
                                        fractal->ptr_img, fractal->x, fractal->y);
        }
       
    }
}