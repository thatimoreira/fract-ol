/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:05:39 by tsoares-          #+#    #+#             */
/*   Updated: 2023/10/30 22:39:38 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num_rev[12];
	int		i;

	i = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		while (n)
		{
			num_rev[i] = (n % 10) + 48;
			n /= 10;
			i++;
		}
		i--;
		while (i >= 0)
			write(fd, &num_rev[i--], 1);
	}
}
/*
int     main(void)
{
        ft_putnbr_fd(-57, 1);
	return (0);
}*/
