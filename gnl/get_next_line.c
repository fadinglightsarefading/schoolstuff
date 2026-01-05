#include "get_next_line.h"

void	move_buf_pointer(char *buf)
{
	while (*buf != '\n')
		*buf++ = '\0';
	if (*buf == '\n')
		*buf = '\0';
}

int	check_newline(char *s)
{
	int	i;

	i = 0;
	while (!s[i])
		i++;
	while (i < BUFFER_SIZE)
	{
		if (s[i++] == '\n')
			return (0);
	}
	return (1);
}

char	*construct_line(char *s)
{
	int		i;
	char	*return_string;

	while (!(*s))
		s++;
	i = 0;
	while (s[i] != '\n')
		i++;
	return_string = malloc((i + 2) * sizeof(char));
	i = -1;
	while (s[++i] != '\n')
		return_string[i] = s[i];
	return_string[i++] = '\n';
	return_string[i] = '\0';
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
		return_string = construct_line(buf);
		move_buf_pointer(buf);
		return (return_string);
	}
	else if (ft_strlen(buf))
		str1 = ft_strrchr(buf, '\n');
	else
		str1 = ft_strdup("");
	if (!str1)
		return (NULL);
	flag = 1;
	while (flag)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
			return (NULL);
		buf[bytes] = '\0';
		str2 = ft_strjoin(str1, buf);
		if (!str2)
			return (NULL);
		str1 = ft_strdup("");
		free(str1);
		str1 = ft_strdup(str2);
		if (!str1)
			return (NULL);
		free(str2);
		flag = check_newline(buf);
	}
	return_string = construct_line(str1);
	free(str1);
	return (return_string);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*return_string;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	return_string = read_line(fd, buffer);
	return (return_string);
}
