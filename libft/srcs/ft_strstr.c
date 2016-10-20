/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:34:19 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/07 17:07:36 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	size_t	j;

	if (!*s2)
		return ((char*)s1);
	if (!*s1)
		return (NULL);
	i = 0;
	while (s1[i])
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
