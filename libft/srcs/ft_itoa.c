/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:26:54 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/08 17:58:09 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_nbfigures(unsigned int nb)
{
	if (nb >= 10)
		return (1 + ft_nbfigures(nb / 10));
	else
		return (1);
}

static unsigned int	ft_sign_itoa(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char				*ft_itoa(int n)
{
	char			*str;
	int				nb_fig;
	int				sign;
	unsigned int	j;

	sign = 0;
	if (n < 0)
		sign = 1;
	j = ft_sign_itoa(n);
	nb_fig = ft_nbfigures(j);
	if(!(str = (char*)malloc(sizeof(char) * (nb_fig + sign + 1))))
		return (NULL);
	str[nb_fig + sign] = '\0';
	if (sign == 1)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (j >= 1)
	{
		str[nb_fig - 1 + sign] = j % 10 + '0';
		j = j / 10;
		nb_fig--;
	}
	return (str);
}
