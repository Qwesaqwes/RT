/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:19:15 by opandolf          #+#    #+#             */
/*   Updated: 2017/02/18 17:38:54 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cell	*classify(t_vect3d p, t_cell *parent)
{
	t_cell	*tmp;

	if (parent->child == null)
	{
		return (parent);
	}
	tmp = parent->child;
	while (tmp)
	{
		if (point_in_cell(tmp, p))
			return (classify(p, tmp));
		tmp = tmp->next;
	}
	return (NULL);
}
