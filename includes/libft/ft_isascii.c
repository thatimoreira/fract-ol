/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:02:10 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/06 19:23:24 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c > -1 && c < 128)
		return (1);
	return (0);
}
/*
int	main(void)
{
	#include <stdio.h>

	int	character;

	character = '\0';
	printf("%d\n", ft_isascii(character));
	return (0);
}*/
