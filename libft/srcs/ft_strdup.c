/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:00:13 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/07 15:15:51 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (str)
	{
		i = 0;
		while (i < ft_strlen(s))
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
