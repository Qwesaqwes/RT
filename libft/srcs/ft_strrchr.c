/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:10:39 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/07 17:47:15 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	c2;
	size_t	len;

	len = ft_strlen(s);
	c2 = (char)c;
	if (c2 == '\0')
		return ((char *)s + len);
	while (len > 0)
	{
		if (s[len - 1] == c2)
			return ((char *)s + len - 1);
		len--;
	}
	return (NULL);
}
