/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:23:33 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/16 17:56:12 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int		i;
	size_t				allocamt;
	char				*sub;

	if (!s)
		return (NULL);
	allocamt = 1;
	if (start > (ft_strlen(s) + 1))
		start = ft_strlen(s);
	else if (len > ft_strlen(s) - start)
		allocamt = ft_strlen(s) - start + 1;
	else
		allocamt = len + 1;
	sub = malloc(allocamt * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < (unsigned int)allocamt && i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
