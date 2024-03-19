/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:22:42 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/06 23:22:25 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	def_function(va_list ap, const char arg_type)
{
	int	total_bytes;

	total_bytes = 0;
	if (arg_type == 'c')
		total_bytes += pf_putchar(va_arg(ap, int));
	else if (arg_type == 's')
		total_bytes += pf_putstr(va_arg(ap, char *));
	else if (arg_type == 'p')
		total_bytes += pf_putptr(va_arg(ap, void *));
	else if (arg_type == 'd' || arg_type == 'i')
		total_bytes += pf_putnbr(va_arg(ap, int));
	else if (arg_type == 'u')
		total_bytes += pf_put_uint(va_arg(ap, unsigned int));
	else if (arg_type == 'x' || arg_type == 'X')
		total_bytes += pf_puthexadec(va_arg(ap, unsigned int), arg_type);
	else if (arg_type == '%')
		total_bytes += write(1, "%", 1);
	return (total_bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		bytes_printed;

	i = 0;
	bytes_printed = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			bytes_printed += def_function(ap, format[i + 1]);
			i += 2;
		}
		else
		{
			bytes_printed += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (bytes_printed);
}
