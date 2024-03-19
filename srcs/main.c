/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:35:13 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/18 22:37:13 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fract fractal;
	int     user_option;

	validate_input(argc, argv);

	if (user_option == "1\0")
	{
        	fractal.name == "Mandelbrot";
		fractol_init(&fractal);
		render_mandelbrot(&fractal);
	}
	else
	{
		fractal.name == "Julia";
		fractol_init(&fractal);
		render_julia(&fractal); // complex numbers
	}
	mlx_loop(fractal.mlx_connection); // keeps the window open - mlx() function is used to receive events

	// display_image(); -> displays the rendered img

	// handle_user_input(); -> handle user input for zooming and navigation
	return (0);
}
