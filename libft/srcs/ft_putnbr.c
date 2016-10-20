/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:32:37 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/11 14:04:10 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	j;

	if (n < 0)
	{
		ft_putchar('-');
		j = -1 * n;
	}
	else
		j = n;
	if (j >= 10)
	{
		ft_putnbr((int)(j / 10));
		ft_putnbr((int)(j % 10));
	}
	else
		ft_putchar((int)(j) + '0');
}
