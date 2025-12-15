/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:26:11 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/15 20:04:44 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	trim_f;
	int	trim_e;

	// brillian ft_strdup idea here:
	// - trim back first, by incrementing set in s1, place null terminator
	// - just increment through the beginning of s1 until no longer on set
	// - simple as.
}
