/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 05:36:48 by jichen-m          #+#    #+#             */
/*   Updated: 2016/12/05 15:20:09 by opandolf         ###   ########.fr       */
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

	// printf("origin0: %f, %f, %f, %f\n", origin.x, origin.y, origin.z, origin.w);
	new = mult_matrix(inver_transl_matrix(trans_matrix(t.transl)), origin);
	// printf("new t: %f, %f, %f\n", new.x, new.y, new.z);
	new = mult_matrix(inver_rot_matrix(rotationX(t.rot.x)), new);
	// printf("new rx: %f, %f, %f\n", new.x, new.y, new.z);
	new = mult_matrix(inver_rot_matrix(rotationY(t.rot.y)), new);
	// printf("new ry: %f, %f, %f\n", new.x, new.y, new.z);
	new = mult_matrix(inver_rot_matrix(rotationZ(t.rot.z)), new);
	// printf("new rz: %f, %f, %f\n", new.x, new.y, new.z);
	new = mult_matrix(inver_scale_matrix(scale_matrix(t.scale)), new);
	// printf("new s: %f, %f, %f\n", new.x, new.y, new.z);
	// printf("origin1 : %f,%f,%f\n", new.x, new.y, new.z);

	return (new);
}

t_vec3d inver_dir(t_vec3d dir, t_transform t)
{
	t_vec3d new;

	// printf("dir0: %f, %f, %f\n", dir.x, dir.y, dir.z);
	new = mult_matrix(inver_rot_matrix(rotationX(t.rot.x)), dir);
	new = mult_matrix(inver_rot_matrix(rotationY(t.rot.y)), new);
	new = mult_matrix(inver_rot_matrix(rotationZ(t.rot.z)), new);
	new = mult_matrix(inver_scale_matrix(scale_matrix(t.scale)), new);
	// printf("dir1 : %f,%f,%f\n", new.x, new.y, new.z);

	return (new);
}

t_ray	imaginary_ray(t_ray ray, t_transform t)
{
	t_ray	new;

	new.origin = inver_origin(ray.origin, t);
	// printf("origin : %f,%f,%f\n", new.origin.x, new.origin.y, new.origin.z);
	new.dir = inver_dir(ray.dir, t);
	// printf("dir : %f,%f,%f\n", new.dir.x, new.dir.y, new.dir.z);

	return (new);
}

int		get_nearest_obj(t_ray ray, t_list *list, t_no *no)
{
	t_list	*tmp;
	float	distno;		//distance of nearest obj (minimum)
	float	dist;
	t_ray	img_ray;
	t_obj	obj;

	tmp = list;
	distno = -1;
	dist = -1;
	while (tmp)
	{
		obj = *(t_obj*)(tmp->content);
		if (obj.type == 0)	//si obj = sphere
		{
			img_ray = imaginary_ray(ray, obj.transform);
			dist = sphere_dist(img_ray);
		}
		if (dist >= 0)
		{
			if ((distno == -1) || (dist < distno))
			{
				distno = dist;
				no->obj = obj;
				no->img_ray = img_ray;
			}
		}
		tmp = tmp->next;
	}
	if (distno == -1)
		return (0);
	no->ip = set_inter_point(dist, ray);
	return (1);
}
