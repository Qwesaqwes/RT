/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 05:36:48 by jichen-m          #+#    #+#             */
/*   Updated: 2016/10/20 02:45:22 by jichen-m         ###   ########.fr       */
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

t_no	get_nearest_obj(t_ray ray, t_list *list)
{
	t_list	*tmp;
	t_no	no;
	float	distno;		//distance of nearest obj (minimum)
	float	dist;

	tmp = list;
	distno = -1;
	while (tmp)
	{
		if (((t_obj*)tmp->content)->type == 0)	//si obj = sphere
			dist = sphere_dist(ray, *((t_obj*)tmp->content));
		ft_putchar('C');
		if (dist >= 0)
		{
			if ((distno == -1) || (dist < distno))
			{
				distno = dist;
				no.obj = *((t_obj*)tmp->content);
			}
		}
		ft_putchar('C');
		tmp = tmp->next;
	}
	ft_putchar('D');
	no.ip = set_inter_point(dist, ray);
	ft_putchar('D');
	return (no);
}
