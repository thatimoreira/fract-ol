/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:03:00 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/26 21:37:28 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tempdest;
	const char	*tempsrc;

	tempdest = (char *)dest;
	tempsrc = (char *)src;
	if (dest > src)
	{
		while (n--)
			tempdest[n] = tempsrc[n];
	}
	else
		ft_memcpy(dest, src, n);
	return ((void *)dest);
}

/*int	main(void)
{
	#include <stdio.h>
	#include <string.h>

	char testmemmove1[] = "PEACE among WORLDS ,,l,,";
	char testmemmove2[30];
	ft_memmove(testmemmove2, testmemmove1, 25);
	printf("resultado ft*.c : %s\n", testmemmove2);

	char testmemmove3[] = "PEACE among WORLDS ,,l,,";
	char testmemmove4[30];
	memmove(testmemmove4, testmemmove3, 25);
	printf("resultado original : %s\n", testmemmove4);
	return (0);
}*/
