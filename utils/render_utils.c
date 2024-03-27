/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:16:43 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/23 02:30:46 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Implements auxiliary function for rendering fractal images

// Put pixel in image buffer
void    put_pixel(t_fract *fractal, int x, int y, int color)
{
    int offset;

    offset = (y * fractal->line_len) + (x * (fractal->bpp / 8));
    *(unsigned int *)(fractal->ptr_img + offset) = color;
}
