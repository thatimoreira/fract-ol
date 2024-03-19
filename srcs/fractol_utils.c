/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:10:26 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/18 22:41:07 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pixel_put(t_fract fract, int x, int y, int color)
{
	char    *buffer;

	buffer = fract.addr + (y * fract.line_len + x * (fract.bpp / 8));
	*(unsigned int *)buffer = color;
}

void	print_menu()
{
	ft_printf("Choose a fractal type accordingly to it's number:\n");
	ft_printf("1) Mandelbrot\n2) Julia\n");
	ft_printf("\n\nExecution patterns: \n\t./fractol 1 or \n\t./fractol 2 <x value> <y value>\n");
}

t_fract	*validate_input(int n_args, char **args)
{
	t_fract	*fractal;

	// ./fractol 1   => mandelbrot
	// ./fractol 2 <real> <i>   => julia
	fractal = (t_fract *)malloc(sizeof(t_fract));
	if(!fractal)
		handle_allocation_failure();
	fractal->user_option = ft_atoi(args[1]);
	if (n_args < 2 || (fractal->user_option == 1 && n_args > 2)// Mandelbrot with parameters
		 || (fractal->user_option == 2 && n_args < 4))// Julia with less params then needed
	{
	// displays a list of available parameters and exits properly.
		ft_putstr_fd(INVALID_USAGE, STDERR_FILENO);
		print_menu();
		exit(EXIT_FAILURE);
	}
	else if (fractal->user_option != 1 || fractal->user_option != 2)
	{
		ft_putstr_fd(INVALID_FRACTAL, STDERR_FILENO);
		print_menu();
		exit(EXIT_FAILURE);
	}
	return (fractal);
}
