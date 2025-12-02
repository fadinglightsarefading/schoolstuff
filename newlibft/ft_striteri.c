/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:34:03 by cclarke           #+#    #+#             */
/*   Updated: 2025/11/26 18:10:04 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, char (*f)(unsigned int, char))
{
	unsigned int		len;
	unsigned int		i;

	len = strlen((char *)s);
	i = 0;
	while (i < len)
	{
		s[i] = f(i, s[i]);
		i++;
	}
	s[i] = '\0';
}
