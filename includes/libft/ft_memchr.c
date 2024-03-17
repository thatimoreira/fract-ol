/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:21:01 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/17 05:45:03 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temps;
	size_t			i;

	temps = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (temps[i] != (unsigned char)c)
			i++;
		else
			return ((void *)(s + i));
	}
	return (NULL);
}
/*
int	main(void)
{
	#include <stdio.h>

	char	source[] = "Eu sou o silêncio da noite";
	int		letter = 's';
	char	*find;

	find = ft_memchr(source, letter, sizeof(source));
	printf("%s\n", find);
	return (0);
}*/
