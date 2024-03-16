/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:38:54 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/18 00:58:56 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	while ((i < len) && big[i])
	{
		if (len - i >= little_len)
		{
			if (ft_strncmp(&big[i], little, little_len) == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	#include <stdio.h>

	char	*bigstr;
	char	*littlestr;
	size_t	length;
	char	*localize;

	bigstr = "Paralelepipedo";
	littlestr = "lele";
	length = 8;
	localize = ft_strnstr(bigstr, littlestr, length);
	printf("%s\n", localize);
	return (0);
}*/
