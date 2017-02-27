/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:27:26 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/27 18:36:46 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_pret		polygone_dist(t_ray ray, t_obj obj)
{
	float	dist;
	t_face	*tmp;
	t_pret	ret;
	int		j;
	float	olddist;

	tmp = obj.faces;
	ret.no = NULL;
	ret.dist = -1;
	j = 0;
	while (tmp)
	{
		if (j == 1)
			olddist = dist;
		dist = triangle_dist(ray, *tmp);
		if (dist > SHADOW_BIAS)
		{
			if (ret.dist == -1 || dist < ret.dist)
			{
				ret.dist = dist;
				ret.no = tmp;
			}
		}
		j++;
		if (dist > SHADOW_BIAS && j == 2)
			printf("j: %d, olddist: %f, dist: %f\n",j , olddist, dist);
		tmp = tmp->next;
	}
	return (ret);
}
