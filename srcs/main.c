/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:35:13 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/27 06:09:01 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_fractal_name(t_fract *fractal, char **arguments)
{
	if (fractal->user_option == 1)
		fractal->name = "Mandelbrot";
	else if (fractal->user_option == 2)
	{
		fractal->name = "Julia";
		fractal->zx = atof(arguments[2]);
		fractal->zy = atof(arguments[3]);
	}
}

int	validate_input(int n_args, char **args)
{
	int	user_op;

	user_op = 0;
	// ./fractol 1 => mandelbrot
	// ./fractol 2 => julia
	// ./fractol 2 <real> <i> => julia
	if (n_args < 2)
	{
		ft_putstr_fd(INVALID_USAGE, STDERR_FILENO);
		print_menu();
		exit(EXIT_FAILURE);
	}
	user_op = ft_atoi(args[1]);
	if (user_op != 1 && user_op!= 2)
	{
		ft_putstr_fd(INVALID_FRACTAL, STDERR_FILENO);
		print_menu();
		exit(EXIT_FAILURE);
	}
	else if ((user_op == 1 && n_args > 2) // Mandelbrot with params
			|| (user_op == 2 && n_args != 4)) // Julia with less params then needed
	{
		ft_putstr_fd(INVALID_USAGE, STDERR_FILENO);
		print_menu();
		exit(EXIT_FAILURE);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_fract	*fractal;

	fractal = (t_fract *)malloc(sizeof(t_fract));
	if (!fractal)
		handle_allocation_failure();
	if (validate_input(argc, argv) == 0)
	{
		fractal->user_option = ft_atoi(argv[1]);
		set_fractal_name(fractal, argv);
		fractol_init(fractal);
		//init_minilibx(fractal);
		render_fractals(fractal);
		mlx_loop(fractal->mlx_connection);
		free(fractal);
		return (EXIT_SUCCESS);
	}
	free(fractal);
	return (EXIT_FAILURE);
}
