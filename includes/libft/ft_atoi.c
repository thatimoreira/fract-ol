/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:57:11 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/25 19:18:41 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		convnum;
	int		sign;

	i = 0;
	convnum = 0;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		convnum = convnum * 10 + (nptr[i] - 48);
		i++;
	}
	return (convnum * sign);
}
/*
int	main(void)
{
	#include <stdio.h>

	char	*str;
	int	convertstr;

	str = "546";
	convertstr = ft_atoi(str);
	printf("%d\n", convertstr);
	return (0);
}*/
