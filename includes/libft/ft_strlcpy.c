/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:03:18 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/15 07:39:02 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			src_len;
	unsigned char	*source;

	i = 0;
	src_len = ft_strlen(src);
	source = (unsigned char *)src;
	if (size == 0)
		return (src_len);
	while (source[i] && i < (size - 1))
	{
		dst[i] = source[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
int	main(void)
{
	#include <stdio.h>

	char		*str_dest;
	const char	*str_src;
	size_t		dest_size;
	size_t		src_size;

	str_src = "Yolo!! :)";
	dest_size = 6;
	str_dest = (char *)calloc(dest_size, sizeof(str_dest));
	if (str_dest == NULL)
		return (-1);
	else
		src_size = ft_strlcpy(str_dest, str_src, dest_size);
	printf("str_dest = %s\n", str_dest);
	printf("str_src length: %lu\n", src_size);
	return (0);
}*/
