/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:56:04 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/09 16:30:16 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static void	ft_determine_type(const char *s, int *i, va_list ap)
{
	while (s[++(*i)])
	{
		if (s[*i] == '%' && s[(*i) + 1] == '%')
				write(1, &s[++(*i)], 1);
		else if (s[*i] == '%' && (s[(*i) + 1] == 'd' || s[(*i) + 1] == 'c'
			|| s[(*i) + 1] == 'i'))
				ft_printalnum(s[(*i) + 1], va_arg(ap, int), i);
		else if (s[*i] == '%' && s[(*i) + 1] == 's')
				ft_printstr(va_arg(ap, char *), i);
		else if (s[*i] == '%' && s[(*i) + 1] == 'p')
				ft_printhexaddr(va_arg(ap, void *), i);
		else if (s[*i] == '%' && s[(*i) + 1] == 'u')
				ft_printunsdec(va_arg(ap, unsigned int), i);
		else
			write(1, &s[*i], 1);
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int	i;

	va_start(ap, s);
	i = -1;
	ft_determine_type(s, &i, ap);
	va_end(ap);
	return (0);
}

int	main(void)
{
	char vptr[1] = "O";

	
	ft_printf("test input\nA char: %c\nA str: %s\nAn int (d): %d\nA void ptr: %p\n" \
		"An int (i): %i\n",
		'G', "Cheese", -42, (void *)vptr, -42);
	return (0);
}
