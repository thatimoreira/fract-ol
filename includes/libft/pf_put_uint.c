/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 03:12:02 by tsoares-          #+#    #+#             */
/*   Updated: 2024/01/09 16:03:59 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_put_uint(unsigned int num)
{
	int		i;
	int		bytes_printed;
	char	num_rev[12];

	i = 0;
	bytes_printed = 0;
	if (num == 0)
		return (write(1, "0", 1));
	while (num > 0)
	{
		num_rev[i++] = (num % 10) + '0';
		num /= 10;
	}
	i--;
	while (i >= 0)
		bytes_printed += write(1, &num_rev[i--], 1);
	return (bytes_printed);
}
