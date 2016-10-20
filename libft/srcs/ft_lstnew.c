/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 16:10:03 by opandolf          #+#    #+#             */
/*   Updated: 2015/09/14 16:10:10 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*el;
	void			*content_cpy;

	el = (t_list *)ft_memalloc(sizeof(t_list));
	if (el)
	{
		if (content)
		{
			content_cpy = ft_memdup(content, content_size);
			if (content_cpy)
			{
				el->content = content_cpy;
				el->content_size = content_size;
			}
		}
		else
		{
			el->content = NULL;
			el->content_size = 0;
		}
		el->next = NULL;
		return (el);
	}
	return (NULL);
}
