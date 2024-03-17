/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:29:38 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/16 20:29:40 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "../includes/minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <math.h>

typedef struct s_fract // s_data
{
    void    *img;
    char    *addr; // mem address frow where I'm going to change(???) the bytes
    int     bpp; // bits per pixel
    int     line_len;
    int     endian; // used to specify how pixel data is stored or interpreted within an image (check thi case)
}           t_fract;

void    pixel_put(t_fract fract, int x, int y, int color);

#endif