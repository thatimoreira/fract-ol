/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:42:20 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/27 11:42:23 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    operate_complex(t_fract *fractal, double imag1, double imag2)
{
    double  temp_z;
    double  temp_y;
    double  zx_sq;
    double  zy_sq;

    // Sum the complex numbers
    temp_z = fractal->zx + fractal->cx;
    temp_y = fractal->zy + fractal->cy;

    // Square the complex number
    zx_sq = (temp_z * temp_z) - (temp_y * temp_y);
    zy_sq = 2 * temp_z * temp_y;

    // Update the fractal's zx and zy values
    fractal->zx = zx_sq;
    fractal->zy = zy_sq;
}