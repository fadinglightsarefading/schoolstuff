/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:09:54 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/05 18:57:38 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

void	ft_printalnum(char ch, int c, int *i)
{
	char	printch;
	char	*printstr;

	printch = (char)c;
	if (ch == 'd')
	{
		printstr = ft_strdup(ft_itoa(c));
		write(1, printstr, ft_strlen(printstr));
	}
	else
		write(1, &printch, 1);
	(*i)++;
}
