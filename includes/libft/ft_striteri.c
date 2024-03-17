/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:19:32 by tsoares-          #+#    #+#             */
/*   Updated: 2023/11/13 11:50:04 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
int	main(void)
{
	#include <stdio.h>

	char	str[] = "Qualquer coisa";

	ft_striteri(str, replace_char);
	printf("%s\n", str);
	return (0);

>>>> Function you may use to test my code:
void    replace_char(unsigned int index, char *c)
{
        if (index % 2 != 0)
                *c = '|';
}
}*/
