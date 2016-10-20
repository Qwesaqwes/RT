/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:29:03 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/11 13:42:34 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	j;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		j = -n;
	}
	else
		j = n;
	if (j >= 10)
	{
		ft_putnbr_fd((int)(j / 10), fd);
		ft_putnbr_fd((int)(j % 10), fd);
	}
	else
		ft_putchar_fd((int)j + '0', fd);
}
