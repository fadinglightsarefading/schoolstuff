/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:55:07 by cclarke           #+#    #+#             */
/*   Updated: 2025/11/26 18:12:09 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*final;
	unsigned int	len;
	unsigned int	i;

	len = strlen((char *)s);
	final = malloc((len + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		final[i] = f(i, s[i]);
		i++;
	}
	final[i] = '\0';
	return (final);
}
