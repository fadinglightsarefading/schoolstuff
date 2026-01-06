#include "get_next_line.h"
#include <stdio.h>

void	update_buffer(char *buf)
{
	while (*buf != '\n')
		*buf++ = '\0';
	if (*buf == '\n')
		*buf = '\0';
}

int	check_newline(char *s)
{
	while (!(*s))
		s++;
	while (*s)
	{
		if (*s++ == '\n')
			return (0);
	}
	return (1);
}

char	*construct_line(char *s, int bytes)
{
	int		i;
	char	*return_string;

	if (*s == '\0')
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (bytes)
		i++;
	return_string = malloc((i + 1) * sizeof(char));
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		return_string[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		return_string[i] = s[i];
	return_string[++i] = '\0';
	return (return_string);
}

char	*read_line(int fd, char *buf)
{
	int		flag;
	int		bytes;
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
	flag = 1;
	while (flag)
	{
		if (check_newline(buf))
		{
			bytes = read(fd, buf, BUFFER_SIZE);
			if (!bytes)
				break ;
		}
		str2 = ft_strjoin(str1, buf, bytes);
		if (!str2)
			return (NULL);
		free(str1);
		str1 = ft_strdup(str2);
		if (!str1)
			return (NULL);
		free(str2);
		flag = check_newline(buf);
	}
	return_string = construct_line(str1, bytes);
	free(str1);
	return (return_string);
}

char	*get_next_line(int fd)
{
	int		i;
	static char	*buffer;
	char		*return_string;

	i = 0;
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		while (i <= BUFFER_SIZE)
			buffer[i++] = '\0';
	}
	if (!buffer)
		return (NULL);
	return_string = read_line(fd, buffer);
	return (return_string);
}
