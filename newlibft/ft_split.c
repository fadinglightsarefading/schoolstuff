/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:16:10 by cclarke           #+#    #+#             */
/*   Updated: 2025/11/29 18:29:08 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_replace_delimiter(char *str, char ch, int *cnt)
{
	int	i;

	i = 0;
	*cnt = 0;
	while (str[i])
	{
		while (str[i] == ch)
				i++;
		if (str[i] != ch && str[i] != '\0')
				(*cnt)++;
		while (str[i] != ch && str[i] != '\0')
				i++;
		if (str[i] == ch)
			str[i++] = '\0';
	}
	return (str);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		count;
	char	*string;
	char	**final;

	string = ft_strdup(s);
	if (!string)
			return (NULL);
	string = ft_replace_delimiter(string, c, &count);
	final = malloc((count + 1) * sizeof(char *));
	if (!final)
			return (NULL);
	i = 0;
	while (count--)
	{
		while (*string == c)
				string++;
		final[i++] = ft_strdup(string);
		if (!(final[i - 1]))
				return (NULL);
		while (*string)
			string++;
		string++;
	}
	final[i] = NULL;
	return (final);
}
