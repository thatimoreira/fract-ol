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

void    put_pixel(t_fract *fract, int x, int y, int color)
{
    char    *buffer;

    buffer = fract->addr + (y * fract->line_len + x * (fract->bpp / 8));
    *(unsigned int *)buffer = color;
}
