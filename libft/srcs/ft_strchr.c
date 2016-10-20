/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:57:12 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/07 15:33:49 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c2;

	c2 = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c2)
			return ((char *)s + i);
		i++;
	}
	if (c2 == '\0')
		return ((char *)s + i);
	return (NULL);
}
