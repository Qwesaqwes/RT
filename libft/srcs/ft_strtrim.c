/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:00:45 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/09 13:44:32 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	len;
	unsigned int	lenstr;

	if (!s)
		return (NULL);
	start = 0;
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t') &&
s[start])
	{
		start++;
	}
	lenstr = ft_strlen(s);
	if (start == lenstr || lenstr == 0)
		return (ft_strnew(1));
	len = lenstr - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
	{
		len--;
	}
	return (ft_strsub(s, start, len - start + 1));
}
