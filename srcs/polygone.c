/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:27:26 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/01 16:56:26 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		polygone_dist2(t_ray ray, t_pret *ret, int j, t_face *tmp)
{
	float	dist;
	float	olddist;

	dist = 0;
	if (j == 1)
		olddist = dist;
	dist = triangle_dist(ray, *tmp);
	if (dist > SHADOW_BIAS)
	{
		if (ret->dist == -1 || dist < ret->dist)
		{
			ret->dist = dist;
			ret->no = tmp;
		}
	}
}

t_pret		polygone_dist(t_ray ray, t_obj obj)
{
	t_face	*tmp;
	t_pret	ret;
	int		j;

	tmp = obj.faces;
	ret.no = NULL;
	ret.dist = -1;
	j = 0;
	while (tmp)
	{
		polygone_dist2(ray, &ret, j, tmp);
		j++;
		tmp = tmp->next;
	}
	return (ret);
}
