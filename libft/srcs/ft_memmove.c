/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:58:30 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/05 17:18:50 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		n;
	char		*s1;
	const char	*s2;

	s1 = dst;
	s2 = src;
	if (src > dst)
	{
		n = 0;
		while (n < len)
		{
			s1[n] = s2[n];
			n++;
		}
	}
	else
	{
		n = len;
		while (n != 0)
		{
			s1[n - 1] = s2[n - 1];
			n--;
		}
	}
	return (dst);
}
