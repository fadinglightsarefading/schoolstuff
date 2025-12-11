/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexaddr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:00:28 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/11 14:29:05 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_init_addrstr(char *s)
{
	int	i;

	i = 0;
	while (i <= 16)
		s[i++] = '\0';
}

int	ft_printhexaddr(void *vptr, int *i)
{
	int			countdown;
	int			r;
	char		*hex;
	char		*hex_addr;
	char		*hex_addr_cpy;
	uintptr_t	dec_addr;

	hex = "0123456789abcdef";
	hex_addr = malloc(17 * sizeof(char));
	if (!hex_addr)
		return (0);
	ft_init_addrstr(hex_addr);
	dec_addr = (uintptr_t)vptr;
	countdown = 15;
	while (dec_addr || countdown)
	{
		hex_addr[countdown--] = hex[dec_addr % 16];
		dec_addr /= 16;
	}
	hex_addr_cpy = hex_addr;
	while (*hex_addr_cpy == '\0')
		hex_addr_cpy++;
	write(1, "0x", 2);
	r = ft_strlen(hex_addr_cpy) + 2;
	write(1, hex_addr_cpy, r);
	free(hex_addr);
	(*i)++;
	return (r);
}
