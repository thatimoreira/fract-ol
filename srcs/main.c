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
    int     user_option;

    // ./fractol 1   => mandelbrot
    // ./fractol 2 <real> <i>   => julia
    i = 0;
    user_option = ft_atoi(argv[1]);
    if (argc < 2 || (user_option == 1 && argc > 2) // Mandelbrot with parameters
            || (user_option == 2 && argc < 4)// Julia with less params then needed
            || (user_option != 1 || user_option != 2))
    {
        // displays a list of available parameters and exits properly.
        ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
    else if (user_option == "1\0")
        render_mandelbrot(ft_atoi(user_option));
    else //Julia choosed
        render_julia(ft_atoi(user_option), n1, n2); // complex numbers

    // display_image(); -> displays the rendered img

    // handle_user_input(); -> handle user input for zooming and navigation
    return (0);
}
