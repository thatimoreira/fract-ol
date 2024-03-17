/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:10:26 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/16 23:10:28 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    pixel_put(t_fract fract, int x, int y, int color)
{
    char    *buffer;

    buffer = fract.addr + (y * fract.line_len + x * (fract.bpp / 8));
    *(unsigned int *)buffer = color;
}