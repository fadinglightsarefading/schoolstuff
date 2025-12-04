/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:07:27 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/02 18:36:46 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		negate;
	int		pluses;
	long	final;

	negate = 1;
	pluses = 0;
	final = 0;
	while (*nptr == ' ' || *nptr == '+' || (*nptr >= 9 && *nptr <= 13))
	{
		if (*nptr >= 9 && *nptr <= 13 && pluses)
				return (0);
		if (*nptr == '+')
			pluses++;
		nptr++;
	}
	if (*nptr == '-')
	{
		if (pluses > 0)
				return (0);
		negate = -negate;
		nptr++;
	}
	if (pluses < 2)
		while (*nptr >= '0' && *nptr <= '9')
			final = final * 10 + (*nptr++ - 48);
	return ((int)(final * negate));
}
