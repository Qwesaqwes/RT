/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:10:12 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/11 13:21:35 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memdup(void const *src, size_t n)
{
	void	*el;

	el = (void	*)malloc(sizeof(void) * n);
	if (el)
	{
		el = ft_memcpy(el, src, n);
		return (el);
	}
	return (NULL);
}
