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
		if (str[i++] == ch)
		{
			(*cnt)++;
			str[i - 1] = '\0';
		}
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
	string = ft_replace_delimiter(string, c, &count);
	final = malloc((count + 2) * sizeof(char *));
	i = 0;
	count += 1;
	while (count--)
	{
		final[i++] = ft_strdup(string);
		while (*string)
			string++;
		string++;
	}
	final[i] = NULL;
	return (final);
}
