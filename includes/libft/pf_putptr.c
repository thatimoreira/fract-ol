/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:20:00 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/09 16:49:05 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_ptr(unsigned long long n)
{
	size_t	len;
	int		count;
	int		remainder;
	char	*num_conv;

	len = pf_numlen(n);
	count = len;
	remainder = 0;
	num_conv = (char *)malloc((len + 1) * sizeof(char));
	if (num_conv == NULL)
		return (0);
	num_conv[len--] = '\0';
	while (n)
	{
		remainder = n % 16;
		if (remainder < 10)
			num_conv[len--] = remainder + '0';
		else
			num_conv[len--] = remainder - 10 + 'a';
		n /= 16;
	}
	write(1, num_conv, count);
	free(num_conv);
	return (count);
}

int	pf_putptr(void *ptr)
{
	int					bytes_printed;
	unsigned long long	p;

	bytes_printed = 0;
	p = (unsigned long long)ptr;
	if (p == 0)
		bytes_printed = write(1, "(nil)", 5);
	else
	{
		bytes_printed = write(1, "0x", 2);
		bytes_printed += print_ptr(p);
	}
	return (bytes_printed);
}
