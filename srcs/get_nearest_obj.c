/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 05:36:48 by jichen-m          #+#    #+#             */
/*   Updated: 2016/11/23 19:00:36 by JimmyChen        ###   ########.fr       */
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

t_vec3d	inver_origin(t_vec3d origin, t_transform t)
{
	t_vec3d	new;

	new = mult_matrix(inver_rot_matrix(rotationX(t.rot.x)), origin);
	new = mult_matrix(inver_rot_matrix(rotationY(t.rot.y)), new);
	new = mult_matrix(inver_rot_matrix(rotationZ(t.rot.z)), new);
	new = mult_matrix(inver_transl_matrix(trans_matrix(t.transl)), new);
	new = mult_matrix(inver_scale_matrix(scale_matrix(t.scale)), new);

	return (new);
}

t_vec3d inver_dir(t_vec3d dir, t_transform t)
{
	t_vec3d new;

	new = mult_matrix(inver_scale_matrix(scale_matrix(t.scale)), dir);
	new = mult_matrix(inver_rot_matrix(rotationX(t.rot.x)), new);
	new = mult_matrix(inver_rot_matrix(rotationY(t.rot.y)), new);
	new = mult_matrix(inver_rot_matrix(rotationZ(t.rot.z)), new);
	return (new);
}

t_ray	imaginary_ray(t_ray ray, t_transform t)
{
	t_ray	new;

	new.origin = inver_origin(ray.origin, t);
	printf("origin : %f,%f,%f\n", new.origin.x, new.origin.y, new.origin.z);
	new.dir = inver_dir(ray.dir, t);
	printf("dir : %f,%f,%f\n", new.dir.x, new.dir.y, new.dir.z);

	return (new);
}

int		get_nearest_obj(t_ray ray, t_list *list, t_no *no)
{
	t_list	*tmp;
	float	distno;		//distance of nearest obj (minimum)
	float	dist;

	tmp = list;
	distno = -1;
	// printf("A\n");

	while (tmp)
	{
		// printf("A\n");
		if (((t_obj*)tmp->content)->type == 0)	//si obj = sphere
			{
				dist = sphere_dist(imaginary_ray(ray, ((t_obj*)tmp->content)->transform));
				// printf("B\n");
				if (dist > 0)
					printf("dist: %f\n", dist);
			}
		if (dist >= 0)
		{
			if ((distno == -1) || (dist < distno))
			{
				distno = dist;
				no->obj = *((t_obj*)tmp->content);
				//printf("color red:%f", no->obj.color.red);
			}
		}
		tmp = tmp->next;
	}
	// printf("B\n");

	if (distno == -1)
		return (0);
	no->ip = set_inter_point(dist, ray);
	// get_light(t_no *no, t_ray ray);
	return (1);
}
