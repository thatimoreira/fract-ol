/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmsg_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:10:26 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/27 06:47:16 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_menu()
{
	ft_printf("Choose a fractal type accordingly to it's number:\n");
	ft_printf("1) Mandelbrot\n2) Julia\n");
	ft_printf("\nExecution patterns: \n\t./fractol 1 or \n\t./fractol 2 <x value> <y value>\n\n");
}

void	handle_allocation_failure(void)
{
	ft_putstr_fd("Memory allocation failed!\n", 1);
	exit(EXIT_FAILURE);
}
