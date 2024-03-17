/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:49:23 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/17 05:49:16 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temps1;
	unsigned char	*temps2;
	size_t			i;

	temps1 = (unsigned char *)s1;
	temps2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (temps1[i] == temps2[i])
			i++;
		else
			return (temps1[i] - temps2[i]);
	}
	return (0);
}
/*
int	main(void)
{
	#include <stdio.h>

	char	str1[] = "Bom dia!";
	char	str2[] = "Boa tarde!";
	size_t	num;
	int		cmp;

	num = 3;
	cmp = ft_memcmp(str1, str2, num);
	printf("%d\n", cmp);
	return (0);
}*/
