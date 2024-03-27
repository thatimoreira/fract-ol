/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:16:59 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/23 02:19:38 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Calculates the Mandelbrot set for a given pixel in the fractal image and sets
// the color attribute based on whether the pixel is inside or outside the Mandelbrot set
// real (x) coordinate: range [-2, 0.5]
// imaginary (y) coordinate: range [-1, 1]
void    calculate_mandelbrot(t_fract *fractal)
{
    double  temp_zx;
    int     iters; //  count num of iterations

    temp_zx = 0.0;
    iters = 0;
    fractal->zx = 0.0;
    fractal->zy = 0.0;
    // x and y coordinates are transformed to the range [-2, 2] in the x and y directions
    // by subtracting the width or height divided by 2, and then dividing by the width or
    // height divided by 4.
    fractal->cx = (fractal->x - WIDTH / 2.0) / (WIDTH / 4.0);
    fractal->cy = (fractal->y - HEIGHT / 2.0) / (HEIGHT / 4.0);
    while (iters < fractal->max_iter && ((fractal->zx * fractal->zx + fractal->zy * fractal->zy) <= 4))
    {
        temp_zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
        fractal->zy = 2 * fractal->zx * fractal->zy + fractal->cy;
        iters++;
    }
    if (iters == fractal->max_iter)
        put_pixel(fractal, fractal->x, fractal->y, 0x000000); // Sets color to black for pixel inside Mandelbrot set
    else
        put_pixel(fractal, fractal->x, fractal->y, fractal->color * iters);


    /*
    fractal->x_complex = (double)x / WIDTH * (MAX_SEED - MIN_SEED) + MIN_SEED;
    fractal->y_complex = (double)y / HEIGHT * (MAX_SEED - MIN_SEED) + MIN_SEED;
    fractal->x_offset = 0;
    fractal->y_offset = 0;
    fractal->zoom = 1;
    while (fractal->x_offset <= WIDTH && fractal->y_offset <= HEIGHT)
    {
        fractal->x_offset += fractal->zoom;
        fractal->y_offset += fractal->zoom;
        if (fractal->x_offset > WIDTH)
        {
            fractal->x_offset = 0;
            fractal->y_offset += fractal->zoom;
        }
        if (fractal->y_offset > HEIGHT)
        {
            fractal->y_offset = 0;
            fractal->x_offset += fractal->zoom;
        }
        if (fractal->x_offset == 0 && fractal->y_offset == 0)
            break;
        fractal->x = 0;
        while (fractal->x < WIDTH)
        {
            fractal->y = 0;
            while (fractal->y < HEIGHT)
            {
                if (mandelbrot(fractal->x, fractal->y, fractal) == 1)
                    pixel_put(fractal, fractal->x_offset, fractal->y_offset, \
                        fractal->color_hexa);
                fractal->y++;
            }
            fractal->x++;
        }*/
}

// render_mandelbrot function => generates the corresponding image
