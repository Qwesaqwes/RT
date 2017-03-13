/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:39:18 by opandolf          #+#    #+#             */
/*   Updated: 2017/03/13 20:02:18 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersect(t_ray ray, t_cell octree, t_list *obj)
{
	int			omin;
	t_vect3d	q;
	t_cell		cell;
	t_cellobj	tmp;
	float		dist;

	cell = classify(ray.origin, octree);
	q = ray.origin;
	while (cell != NULL)
	{
		dist_min = 0;
		tmp = cell->objects;
		while (tmp)
		{
			if ((dist = check_intersection(tmp, ray, obj)) > 0)
			{
				if (dist < dist_min || dist_min == 0)
				{
					dist_min = dist;
					omin = tmp->id;
				}
			}
			tmp = tmp->next;
		}
		if (dist_min != 0)
			return (omin);
		q = set_next_point(q, origin.dir);
		cell = classify(q, octree);
	}
	return (NULL);
}
