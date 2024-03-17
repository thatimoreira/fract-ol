/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:01:04 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/17 06:08:59 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
/*
int	main(void)
{
	char	*str;
	int	file_desc;

	str = "Oba, lá vem ela!";
	file_desc = 1;
	ft_putstr_fd(str, file_desc);
	return (0);
}*/
