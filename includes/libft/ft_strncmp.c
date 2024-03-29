/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:55:05 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/21 22:49:37 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] && str1[i] == str2[i])
	{
		if (i < n - 1)
			i++;
		else
			return (0);
	}
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}
/*
int	main(void)
{
	#include <stdio.h>

	const char	*st1;
	const char	*st2;
	size_t		i;
	int			compare;

	i = 3;
	st1 = "1234";
	st2 = "1235";
	compare = ft_strncmp(st1, st2, i);
	printf("%d\n", compare);
	return (0);
}*/
