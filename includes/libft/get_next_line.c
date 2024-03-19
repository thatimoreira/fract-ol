/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:42:16 by tsoares-          #+#    #+#             */
/*   Updated: 2024/02/02 05:18:30 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*after_buffer(char *line_read)
{
	size_t	c;
	char	*temp_str;
	size_t	len;

	c = 0;
	while (line_read[c] && line_read[c] != '\n')
		c++;
	if (line_read[c] == '\0' || line_read[1] == '\0')
		return (NULL);
	len = ft_strlen(line_read) - c;
	temp_str = ft_substr(line_read, c + 1, len);
	if (*temp_str == '\0')
	{
		free(temp_str);
		temp_str = NULL;
	}
	line_read[c + 1] = '\0';
	return (temp_str);
}

char	*find_n(const char *st, int c)
{
	size_t	i;
	char	*temp_s;

	i = 0;
	temp_s = (char *)st;
	while (temp_s[i])
	{
		if (temp_s[i] == (char)c)
			return ((char *)&temp_s[i]);
		i++;
	}
	return (NULL);
}

static char	*read_lines(int fd, char *buf, char *aftern)
{
	ssize_t	chars_read;
	char	*temp_aftern;

	chars_read = 1;
	while (chars_read != 0)
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read == 0)
			break ;
		if (chars_read < 0)
			return (NULL);
		buf[chars_read] = '\0';
		if (!aftern)
			aftern = ft_strdup("");
		temp_aftern = aftern;
		aftern = ft_strjoin(temp_aftern, buf);
		free(temp_aftern);
		temp_aftern = NULL;
		if (find_n(buf, '\n'))
			break ;
	}
	return (aftern);
}

char	*get_next_line(int file_d)
{
	static char	*after_n;
	char		*buffer;
	char		*current_ln;

	if (file_d < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	current_ln = read_lines(file_d, buffer, after_n);
	free(buffer);
	buffer = NULL;
	if (!current_ln)
		return (NULL);
	after_n = after_buffer(current_ln);
	return (current_ln);
}
