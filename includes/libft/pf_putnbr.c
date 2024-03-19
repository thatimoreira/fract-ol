/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 08:57:17 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/09 15:57:33 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putnbr(int num)
{
	char	num_rev[12];	
	int		bytes_printed;
	int		i;
	long	n;

	i = 0;
	n = (long)num;
	bytes_printed = 0;
	if (n == 0)
		bytes_printed = write(1, "0", 1);
	else if (n < 0)
	{
		bytes_printed += write(1, "-", 1);
		n *= -1;
	}
	while (n > 0)
	{
		num_rev[i++] = (n % 10) + '0';
		n /= 10;
	}
	i--;
	while (i >= 0)
		bytes_printed += write(1, &num_rev[i--], 1);
	return (bytes_printed);
}
