/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:01:54 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/04 17:56:13 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_lstdelfirst(t_list **alst)
{
	t_list	*tmp;

	if (*alst == NULL)
	{
		return ;
	}
	tmp = (*alst)->next;
	if ((*alst)->next != NULL)
	{
		ft_lstdelone(alst, ft_free_float);
		*alst = tmp;
	}
}
