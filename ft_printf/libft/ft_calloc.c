/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:51:33 by cclarke           #+#    #+#             */
/*   Updated: 2025/12/17 15:43:51 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	i;
	void			*a;
	unsigned int	total;

	total = nmemb * size;
	if (nmemb != 0 && size != 0 && (nmemb != total / size || size != total / nmemb))
		return (NULL);
	a = malloc(nmemb * size);
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		((unsigned char *)a)[i++] = 0;
	return (a);
}
