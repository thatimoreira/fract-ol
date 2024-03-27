/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:29:17 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/27 05:16:19 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Initialize the program by setting up the MiniLibX window,
// creating images and handle keyboard and mouse events
void	init_window(t_fract *fractal)
{
    // Sets up the window
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
						WIDTH, HEIGHT, fractal->name); // creates a new window
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		handle_allocation_failure();
	}
}

void	create_image(t_fract *fractal)
{
	fractal->img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT); //img or ptr_img?
	if (!fractal->img)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		handle_allocation_failure();
	}
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bpp,
						&fractal->line_len, &fractal->endian);
}
/*
void    event_handler(t_fract *fractal)
{
// Sets up event handlers for keyboard and mouse events using the mlx_hook function
// register the handle_key and handle_mouse functions as callbacks for the
//corresponding event types

    mlx_hook(fractal->mlx_window, keypress, keypress_mask, handle_keyboard_events, fractal);
    mlx_hook(fractal->mlx_window, mousepress, mousepress_mask, handle_mouse_events, fractal);
}*/
/*
void    init_data(t_fract *fractal)
{
    //Initializes the data members of the fractal struct with default values
    // zoom, shift, iterations
    fractal->color_hexa = 0xFFFFFF;
}*/

void	fractol_init(t_fract *fractal)
{
	// Entry point for initializating the program and sets up necessary components
	fractal->mlx_connection = mlx_init(); // connects software and display
	if (!fractal->mlx_connection)
	handle_allocation_failure();
	init_window(fractal);
	create_image(fractal);
	fractal->max_iter = MAX_ITER; // Initialize max_iter param
	fractal->color = 0xFFFFFF; // Initialize color param
	//event_handler(fractal);
	//init_data(fractal);
	fractal->color = 0xFFFFFF;
}

// STEPS:
// store all the pxs into an img just mlx_because pixel_put() is a very slow function
// the put the img to the screen we first buffer all pxs to an img
// to print pixels on the screen, get the mem adress on which i will mutate the bytes
// create the image
// write pixels to an image, call mlx_get_data_addr passing bpp, line_len, and endian ass params by reference
//  bytes are not aligned, calculate the memory offset using the line length set by mlx_get_data_addr
