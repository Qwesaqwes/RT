/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:36:02 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/08 16:49:13 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*ptr;
	size_t	i;

	mem = (void*)malloc(sizeof(void) * size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	ptr = (char*)mem;
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (mem);
}
