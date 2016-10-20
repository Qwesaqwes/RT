/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:43:48 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/07 17:33:45 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (*s2 == '\0')
		return ((char *)(s1));
	i = 0;
	len = ft_strlen(s2);
	while (s1[i] && i + len <= n)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s2[j] && s1[i + j] == s2[j])
			{
				j++;
			}
			if (j == ft_strlen(s2))
				return ((char*)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
