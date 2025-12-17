/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:26:11 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/16 18:35:57 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static unsigned int	ft_determine_start(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				break ;
			}
			j++;
		}
		if (!set[j])
			break ;
	}
	return (i);
}

static unsigned int	ft_determine_end(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = (int)((int)ft_strlen(s1) - 1);
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				len++;
				i--;
				break ;
			}
			j++;
		}
		if (!set[j])
			break ;
	}
	return (len);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	start;
	size_t			len;

	if (!s1 || !set)
		return (NULL);
	if (!(*s1))
		return (ft_strdup(""));
	start = ft_determine_start(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	len = ft_strlen(s1) - start - ft_determine_end(s1, set);
	return (ft_substr(s1, start, len));
}
