/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:39:56 by cclarke           #+#    #+#             */
/*   Updated: 2026/01/16 20:27:31 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	update_buffer(char *buf)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i] != '\n' && i < BUFFER_SIZE)
		i++;
	if (buf[i] == '\n')
		i++;
	j = 0;
	while (buf[i])
		buf[j++] = buf[i++];
	while (j < BUFFER_SIZE)
		buf[j++] = '\0';
}

char	*construct_line(char *s, ssize_t *bytes)
{
	int		i;
	char	*return_string;

	if (*s == '\0')
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (*bytes)
		i++;
	return_string = malloc((i + 1) * sizeof(char));
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		return_string[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		return_string[i] = s[i];
		i++;
	}
	return_string[i] = '\0';
	return (return_string);
}

int	read_line_two(int fd, char *buf, ssize_t *bytes, char **str1, char **str2)
{
	while (1)
	{
		if (check_newline(buf))
		{
			(*bytes) = read(fd, buf, BUFFER_SIZE);
			if (*bytes == -1)
				return (1);
			if (!(*bytes))
				break ;
		}
		*str2 = ft_strjoin(*str1, buf, bytes);
		if (!str2)
			return (1);
		free(*str1);
		*str1 = *str2;
		if (!check_newline(buf))
			break ;
	}
	return (0);
}

char	*read_line(int fd, char *buf, ssize_t *bytes)
{
	char	*str1;
	char	*str2;
	char	*return_string;

	if (!check_newline(buf))
	{
		str1 = ft_strdup(ft_strchr(buf, '\n') + 1);
		update_buffer(buf);
	}
	else
		str1 = ft_strdup("");
	if (!str1)
		return (NULL);
	if (read_line_two(fd, buf, bytes, &str1, &str2))
		return (NULL);
	return_string = construct_line(str1, bytes);
	free(str1);
	return (return_string);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	ssize_t			bytes;
	char			*return_string;
	int				i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		while (i <= BUFFER_SIZE)
			buffer[i++] = '\0';
	}
	if (!buffer)
		return (NULL);
	return_string = read_line(fd, buffer, &bytes);
	if (!bytes || !return_string)
	{
		free(buffer);
		buffer = NULL;
	}
	return (return_string);
}
