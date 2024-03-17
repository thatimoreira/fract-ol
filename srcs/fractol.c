/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:29:17 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/16 20:29:22 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minilibx-linux/mlx.h"
#include "../includes/fractol.h"

void    init_minilibx(void *mlx)
{
    void    *mlx_window;
    t_fract img;
    int     x;
    int     y;

    x = 720;
    y = 675;
    mlx_window = mlx_new_window(mlx, 1920, 1080, "Thati's screen"); // creates a new window
    (void)mlx_window;
    (void)img;
    img.img = mlx_new_image(mlx, 1920, 1080); // Creates an image
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
    while ( x <= 1200)
    {
        pixel_put(img, x, y, 0x00FF0000);
        x++;
    }
    mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
    mlx_loop(mlx); // keeps the window open
}

int main(void)
{
    void    *minilibx; // connects software and display
    
    
    minilibx = mlx_init();
    init_minilibx(minilibx);
    return (0);
}

// STEPS:
// store all the pxs into an img just mlx_because pixel_put() is a very slow function
// the put the img to the screen we first buffer all pxs to an img
// to print pixels on the screen, get the mem adress on which i will mutate the bytes
// create the image
// write pixels to an image, call mlx_get_data_addr passing bpp, line_len, and endian ass params by reference
//  bytes are not aligned, calculate the memory offset using the line length set by mlx_get_data_addr
// 