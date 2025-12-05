/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:00:28 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/05 17:10:01 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

void	ft_printhex(void *vptr, int *i)
{
	char	*hex;
	uintptr_t	addr;

	hex = "0123456789abcdef";
	addr = (uintptr_t)vptr;
	

	(*i)++;
}
