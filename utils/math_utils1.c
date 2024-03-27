/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:10:26 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/27 06:47:16 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	calculate_decimal_part(char *s, double decimal_part)
{
	double	factor;

	factor = 0.1;
	while(ft_isdigit(*s))
		s++;
	if (*s == '.')
	{
		s++;
		while(ft_isdigit(*s))
		{
			decimal_part = decimal_part + (*s - '0') * factor;
			factor = factor / 10.0;
			s++;
		}
	}
	return (decimal_part);
}

double	calculate_integer_part(char *str, double integer_part)
{
	while(ft_isdigit(*str))
	{
		integer_part = integer_part * 10.0 + (*str - '0');
		str++;
	}
	return (integer_part);
}

double	ft_atof(const char *nptr)
{
	double	sign;
	char	*n_str;
	double	integer_part;
	double	decimal_part;

	sign = 1.0;
	n_str = (char *)nptr;
	integer_part = 0.0;
	decimal_part = 0.0;
	while (*n_str == ' ' || *n_str == '\t' || *n_str == '\r')
		n_str++;
	if (*n_str == '-' || *n_str == '+')
	{
		if (*n_str == '-')
			sign = -1.0;
		n_str++;
	}
	integer_part = calculate_integer_part(n_str, integer_part);
	decimal_part = calculate_decimal_part(n_str, decimal_part);
	return ((integer_part + decimal_part) * sign);
}

// Calculate the scaled value using linear interpolation: from [0 - 1000]scale to [-2 - +2]scale
double  linear_interpolate(double n, double n_min, double n_max, double max) // linear interpolation
{
    // old_min = 0
    // old_max = WIDTH/HEIGHT (because in this project they are equal - working with squares)
    double  interpolated_n;

    interpolated_n = (n_max - n_min) * n / WIDTH + n_min;
    return (interpolated_n);
}
