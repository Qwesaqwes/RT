/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 05:36:48 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/20 05:05:31 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d	set_inter_point(float dist, t_ray ray)
{
	t_vec3d new;

	new.x = ray.origin.x + ray.dir.x * dist;
	new.y = ray.origin.y + ray.dir.y * dist;
	new.z = ray.origin.z + ray.dir.z * dist;
	return (new);
}

int		get_nearest_obj(t_ray ray, t_list *list, t_no *no)
{
	t_list	*tmp;
	// t_no	no;
	float	distno;		//distance of nearest obj (minimum)
	float	dist;

	tmp = list;
	distno = -1;
	while (tmp)
	{
		if (((t_obj*)tmp->content)->type == 0)	//si obj = sphere
			dist = sphere_dist(ray, *((t_obj*)tmp->content));
		if (dist >= 0)
		{
			if ((distno == -1) || (dist < distno))
			{
				distno = dist;
				no->obj = *((t_obj*)tmp->content);
				printf("color red:%f", no->obj.color.red);
			}
		}
		tmp = tmp->next;
	}
	if (distno == -1)
		return (0);
	no->ip = set_inter_point(dist, ray);
	return (1);
}
