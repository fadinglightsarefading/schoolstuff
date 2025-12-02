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
	char	*retstr;

	retstr = malloc(ft_strlen(s1) * sizeof(char));
	i = 0;
	while (*s1)
	{
		j = 0;
		flag = 0;
		while (j < (int)ft_strlen(set))
			if (set[j++] == *s1)
				flag++;
		if (!flag)
			retstr[i++] = *s1++;
		else
			s1++;
	}
	retstr[i] = '\0';
	return (retstr);
}
