/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:51:26 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/18 17:26:59 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

int		ft_printf(const char *s, ...);
int		ft_printpercent(int *i);
int		ft_printalnum(char ch, int c, int *i);
int		ft_printstr(char *s, int *i);
int		ft_printhexaddr(unsigned long int vptr, int *i);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_printunsigned(char x, unsigned int n, int *i);
int		ft_printchar(char ch);

#endif
