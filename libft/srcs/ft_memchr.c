/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:22:42 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/07 15:09:47 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	size_t				i;
	unsigned char		c2;

	str = (unsigned char*)s;
	c2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == c2)
			return ((void*)str + i);
		i++;
	}
	return (NULL);
}
