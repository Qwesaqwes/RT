/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:16:39 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/07 15:10:11 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	unsigned char		*s2;
	unsigned char		c2;

	s1 = (unsigned char*)src;
	s2 = (unsigned char*)dst;
	c2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		if (s1[i] == c2)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
