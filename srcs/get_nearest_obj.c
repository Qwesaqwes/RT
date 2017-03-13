/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 05:36:48 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 19:56:56 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3d	set_inter_point(float dist, t_ray ray)
{
	t_vec3d new;

	new.x = ray.origin.x + ray.dir.x * dist;
	new.y = ray.origin.y + ray.dir.y * dist;
	new.z = ray.origin.z + ray.dir.z * dist;
	new.w = 1;
	return (new);
}

t_vec3d	inver_origin(t_vec3d origin, t_transform t)
{
	t_vec3d	new;

	new = mult_matrix(inver_transl_matrix(trans_matrix(t.transl)), origin);
	new = mult_matrix(inver_rot_matrix(rotationX(t.rot.x)), new);
	new = mult_matrix(inver_rot_matrix(rotationY(t.rot.y)), new);
	new = mult_matrix(inver_rot_matrix(rotationZ(t.rot.z)), new);
	new = mult_matrix(inver_scale_matrix(scale_matrix(t.scale)), new);
	return (new);
}

t_vec3d inver_dir(t_vec3d dir, t_transform t)
{
	t_vec3d new;

	new = mult_matrix(inver_rot_matrix(rotationX(t.rot.x)), dir);
	new = mult_matrix(inver_rot_matrix(rotationY(t.rot.y)), new);
	new = mult_matrix(inver_rot_matrix(rotationZ(t.rot.z)), new);
	new = mult_matrix(inver_scale_matrix(scale_matrix(t.scale)), new);

	return (new);
}

t_ray	imaginary_ray(t_ray ray, t_transform t)
{
	t_ray	new;

	new.origin = inver_origin(ray.origin, t);
	new.dir = inver_dir(ray.dir, t);
	return (new);
}

int		get_nearest_obj(t_ray ray, t_list *list, t_no *no)
{
	t_list	*tmp;
	float	distno;		//distance of nearest obj (minimum)
	float	dist;
	t_ray	img_ray;
	t_obj	obj;
	t_pret	poly;

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
		if (obj.type == 1)	//si obj = cylindre
		{
			img_ray = imaginary_ray(ray, obj.transform);
			dist = cylindre_dist(img_ray);
		}
		if (obj.type == 2)	//si obj = plane
		{
			dist = plane_dist(obj, ray);
		}
		if (obj.type == 3)	//si obj = cone
		{
			img_ray = imaginary_ray(ray, obj.transform);
			dist = cone_dist(img_ray);
		}
		if (obj.type == 4)
			dist = triangle_dist(ray, *obj.faces);
		if (obj.type == 5 || obj.type == 6)
		{
			poly = polygone_dist(ray, obj);
			dist = poly.dist;
		}
		if (dist > SHADOW_BIAS)
		{
			if ((distno == -1) || (dist < distno))
			{
				distno = dist;
				no->obj = obj;
				no->img_ray = img_ray;
				if (obj.type == 5 || obj.type == 6)
					no->poly_face = poly.no;
				else
					no->poly_face = NULL;
			}
		}
		tmp = tmp->next;
	}
	if (distno <= 0)
		return (0);
	no->ip = set_inter_point(distno, ray);
	no->origin = ray;
	return (1);
}
