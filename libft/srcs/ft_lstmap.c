/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:15:43 by opandolf          #+#    #+#             */
/*   Updated: 2014/11/11 14:02:22 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new;

	if (!lst)
		return (NULL);
	head = NULL;
	new = NULL;
	if (lst->next)
		head = ft_lstmap(lst->next, f);
	new = (*f)(lst);
	new->next = head;
	head = new;
	return (head);
}
