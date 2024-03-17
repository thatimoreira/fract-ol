/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 08:12:53 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/17 08:12:55 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char **argv)
{
    size_t  i;

    // ./fractol 1   => mandelbrot
    // ./fractol 2 <real> <i>   => julia
    i = 0;
    if (argc < 2 || (argv[1] == "1" && argc > 2) // Mandelbrot with parameters
            || (argv[1] == "2") && argc < 4) // Julia with less params then needed
    {
        // displays a list of available parameters and exits properly.
        ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    else if (argv[1] == "1")
        render_fractal(ft_atoi(argv[1]), 720, 480); // Think more about these fixed values
    else //Julia choosed
        render_fractal(ft_atoi(argv[1]), n1, n2); // complex numbers



    // render_fractal(fractal_name); -> renders the selected fractal

    // display_image(); -> displays the rendered img

    // handle_user_input(); -> handle user input for zooming and navigation
    return (0);
}
