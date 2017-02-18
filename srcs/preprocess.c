/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:57:25 by opandolf          #+#    #+#             */
/*   Updated: 2017/02/18 17:17:24 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_cell *preprocess(t_cell *parent, char j, t_list *obj)
{
	t_cell		*list;
	t_cell		*cell;
	t_cellobj	*tmp;
	char		k;	

	if (j = 0)
	{
		return (NULL);
	}
	list = NULL;
	k = 1;
	while (k <= 8)
	{
		cell = init_cell(parent, k);
		tmp = parent->objects;
		while (tmp)
		{
			if (intersect_cell(tmp, cell, obj))
			{
				add_obj(tmp->id, cell->objects);
			}
			tmp = tmp->next;
		}
		if (cell->objects != NULL)
		{
			cell->child = preprocess(cell, j - 1, obj);
		}
		k += 1;
		add_cell_to_list(cell, &list);
	}
	return (list);
}
