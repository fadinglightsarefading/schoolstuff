/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:51:26 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/05 17:25:26 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

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

int	ft_printf(const char *s, ...);
void	ft_printalnum(char ch, int c, int *i);
void	ft_printstr(char *s, int *i);

#endif
