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

void    handle_pixel(int x, int y, t_fract *fractal)
{}

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
            handle_pixel(x, y, fractal) ;//change this name
        }
        x = pixel_index % WIDTH;
        y = pixel_index / WIDTH;
        if (fractal->user_option == 1)
        {
            fractal->x = x;
            fractal->y = y;
            calculate_mandelbrot(fractal);
        }/*
        else if (fractal->user_option == 2)
        {
            fractal->x = x;
            fractal->y = y;
            calculate_julia(fractal, fractal->zx, fractal->zy);
        }
            */
        pixel_index++;
    }
}