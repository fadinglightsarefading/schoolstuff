/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:23:33 by cclarke           #+#    #+#             */
/*   Updated: 2025/11/26 18:19:40 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	sub = malloc((int)len * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = -1;
	while (++i < (int)len)
		sub[i] = s[start + i];
	return (sub);
}
