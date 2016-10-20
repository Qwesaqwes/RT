/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:25:59 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/09 13:42:14 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_splitstr(char const *s, char c, char **tab)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;
	size_t			len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		len = i - start;
		if ((s[i] != '\0' || len > 0) || c == '\0')
		{
			tab[j] = ft_strsub(s, start, len);
			j++;
		}
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int				nb_cases;
	char			**tab;

	if (s != NULL)
		nb_cases = ft_nbcells(s, c);
	else
		nb_cases = 1;
	tab = (char **)ft_memalloc(sizeof(char *) * nb_cases);
	if (!tab)
		return (NULL);
	tab[nb_cases - 1] = NULL;
	if (nb_cases == 1)
		return (tab);
	tab = ft_splitstr(s, c, tab);
	return (tab);
}
