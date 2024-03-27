/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:47:36 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/27 05:59:37 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_menu()
{
	ft_printf("Choose a fractal type accordingly to it's number:\n");
	ft_printf("1) Mandelbrot\n2) Julia\n");
	ft_printf("\nExecution patterns: \n\t./fractol 1 or \n\t./fractol 2 <x value> <y value>\n\n");
}

