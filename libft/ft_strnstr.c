/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:52:18 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/15 19:13:08 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*cbig;
	char	*clittle;

	if (!(*big) && !(*little))
		return ((char *)big);
	if (len)
	{
		if (len == 1)
			len++;
		while (*big && --len)
		{
			cbig = (char *)big;
			clittle = (char *)little;
			while (*cbig && *clittle && (*cbig == *clittle))
			{
				cbig++;
				clittle++;
			}
			if (!(*clittle) || !ft_strlen(little))
				return ((char *)big);
			big++;
		}
	}
	return (NULL);
}
