/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexaddr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:00:28 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/17 14:46:54 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

static int	ft_determine_len(uintptr_t addr)
{
	int	i;

	i = 0;
	while (addr)
	{
		addr /= 16;
		i++;
	}
	return (i);
}

int	ft_printhexaddr(void *vptr, int *i)
{
	char		*hex;
	char		*hex_addr;
	uintptr_t	dec_addr;
	int		len;
	int		j;

	hex = "0123456789abcdef";
	dec_addr = (uintptr_t)vptr;
	len = ft_determine_len(dec_addr);
	hex_addr = malloc((len + 1) * sizeof(char));
	j = 0;
	while (dec_addr)
	{
		hex_addr[j++] = hex[dec_addr % 16];
		dec_addr /= 16;
	}
	hex_addr[j] = '\0';
	len = ft_strlen(hex_addr);
	write(1, "0x", 2);
	write(1, hex_addr, len);
	free(hex_addr);
	(*i)++;
	return (len + 2);
}
