/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:52:18 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/16 17:38:54 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		clen;
	char		*cbig;
	char		*clittle;

	if (!(*little))
		return ((char *)big);
	if (len)
	{
		while (*big && len--)
		{
			clen = len + 1;
			cbig = (char *)big;
			clittle = (char *)little;
			while (*cbig && *clittle && clen-- && (*cbig == *clittle))
			{
				cbig++;
				clittle++;
			}
			if (!(*clittle))
				return ((char *)big);
			big++;
		}
	}
	return (NULL);
}
