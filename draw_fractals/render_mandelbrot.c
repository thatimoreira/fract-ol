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
// Mandelbort function => z = z² + c
// initial z is (0, 0)
// c is the current point
void    calc_mandelbrot(int x, int y, t_fract *fractal)
{
    double  i1;
    double  i2;
    int     iters; //  count num of iterations

   
    // 1st iteration
    fractal->zx = 0.0;
    fractal->zy = 0.0;
    iters = 0;
    
     // current point that has to be checked, linear interpolated to fit the mandelbrot set
    fractal->cx = linear_interpolate(x, -2, +2, WIDTH);
    fractal->cy = linear_interpolate(y, +2, -2, HEIGHT);

    // Iterates z² + c until the numbers diverge
    // If the numbers remain within the bound, the iteration is counted as a valid number in the set
    // If the number diverges, the iteration is counted as an invalid number
    while(iters < fractal->max_iter)
    {
        operate_complex(&fractal, i1, i2);
        if ((fractal->zx * fractal->zx) + (fractal->zy * fractal->zy) > fractal->hypotenuse) // check if it's out of set
        {
            fractal->color = linear_interpolate(iters, 0x000000, 0xFFFFFF, fractal->max_iter);
            put_pixel(&fractal->img, x, y, fractal->color);
            return ; 
        }
        iters++;
    }
    put_pixel(&fractal->img, x, y, PSYCHEDELIC_ORANGE);
}


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
