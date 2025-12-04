/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:26:11 by cclarke           #+#    #+#             */
/*   Updated: 2025/11/24 15:55:57 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		flag;
	char	*s2;
	const char	*s1_cpy;

	flag = 0;
	s1_cpy = s1;
	while (*s1_cpy)
	{
		j = 0;
		while (j < (int)ft_strlen(set))
			if (set[j++] == *s1_cpy)
				flag++;
		s1_cpy++;
	}
	s2 = malloc((ft_strlen(s1) - flag + 1) * sizeof(char));
	if (!s2)
			return (NULL);
	i = 0;
	while (*s1)
	{
		j = 0;
		flag = 0;
		while (j < (int)ft_strlen(set))
			if (set[j++] == *s1)
				flag++;
		if (!flag)
			s2[i++] = *s1++;
		else
			s1++;
	}
	s2[i] = '\0';
	return (s2);
}
