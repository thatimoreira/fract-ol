/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthexadec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:00:37 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/09 16:47:30 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	def_format(int rd, const char arg_type)
{
	if (arg_type == 'x')
		rd = rd - 10 + 'a';
	if (arg_type == 'X')
		rd = rd - 10 + 'A';
	return (rd);
}

static int	pf_printhex(unsigned int n, const char pattern)
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
			num_conv[len--] = def_format(remainder, pattern);
		n /= 16;
	}
	write(1, num_conv, count);
	free(num_conv);
	return (count);
}

int	pf_puthexadec(unsigned int num, const char format)
{
	int	bytes_printed;

	bytes_printed = 0;
	if (num == 0)
		bytes_printed = write(1, "0", 1);
	else
		bytes_printed = pf_printhex(num, format);
	return (bytes_printed);
}
