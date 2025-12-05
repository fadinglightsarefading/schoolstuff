/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:56:04 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/05 18:49:17 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int	i;

	va_start(ap, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1] == '%')
				write(1, &s[++i], 1);
		else if (s[i] == '%' && (s[i + 1] == 'd' || s[i + 1] == 'c'))
				ft_printalnum(s[i + 1], va_arg(ap, int), &i);
		else if (s[i] == '%' && s[i + 1] == 's')
				ft_printstr(va_arg(ap, char *), &i);
	/*	else if (s[i] == '%' && s[i + 1] == 'p')
				ft_printhex(va_arg(ap, void *), &i);*/
		else
			write(1, &s[i], 1);
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	ft_printf("test input\nA char: %c\nA str: %s\nAn int: %d\n",
		'G', "Cheese", 42);
	return (0);
}
