#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (!(*s))
		s++;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s--;
	if (c > 127)
		return (str);
	while (*++s)
		if (*s == (char)c)
			str = (char *)s;
	if (*str == (char)c)
		return (str);
	else if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	dup = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	while (!(*s2))
		s2++;
	str = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2)) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[j++] = s1[i];
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	return (str);
}
