/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:59:57 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/11 14:30:44 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_printunsdec(unsigned int u)
{
	char	*printstr;

	printstr = ft_strdup(ft_unsigned_itoa(u));
	if (!printstr)
		return ;
	write(1, printstr, ft_strlen(printstr));
	free(printstr);
}

static void	ft_puthex(unsigned int n, char *hex)
{
	if (n >= 16)
		ft_puthex((n / 16), hex);
	write(1, &hex[n % 16], 1);
}

void	ft_printunsigned(char x, unsigned int n, int *i)
{
	char	*hexlower;
	char	*hexupper;

	hexlower = "0123456789abcdef";
	hexupper = "0123456789ABCDEF";
	if (x == 'u')
		ft_printunsdec(n);
	else if (x == 'x')
		ft_puthex(n, hexlower);
	else
		ft_puthex(n, hexupper);
	(*i)++;
}
