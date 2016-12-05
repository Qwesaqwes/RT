/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:32:03 by opandolf          #+#    #+#             */
/*   Updated: 2016/12/05 16:23:14 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	color_mult(t_color c, float k)
{
	t_color res;

	res.red = k * c.red;
	res.blue = k * c.blue;
	res.green = k * c.green;
	return (res);
}

t_color		color_add(t_color a, t_color b)
{
	t_color res;

	res.red = a.red + b.red;
	res.blue = a.blue + b.blue;
	res.green = a.green + b.green;
	return (res);
}

t_color	color_ambiant(float ia, float kd, t_color color)
{
	t_color		res;

	res = color_mult(color, ia * kd);
	return (res);
}

t_vec3d		vector_sub(t_vec3d a, t_vec3d b)
{
	t_vec3d res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	res.w = 1;
	return (res);
}

int			get_intersection_obj(t_list *list, t_ray ray)
{
	t_list	*tmp;
	t_ray	img_ray;


	tmp = list;
	while (tmp)
	{
		if (((t_obj*)tmp->content)->type == 0)	//si obj = sphere
		{
			img_ray = imaginary_ray(ray, ((t_obj*)tmp->content)->transform);
			if (sphere_dist(img_ray) > 0)
			{
				return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

t_color		color_diffuse(t_vec3d n, t_scene s, t_obj o, t_vec3d ip)
{
	t_color		res;
	t_list		*tmp;
	t_obj		lum;
	float		k;
	t_ray		ray;

	tmp = s.lum;
	res = color_mult(o.color, 0);
	while(tmp)
	{
		lum = (*(t_obj*)tmp->content);
		ray.origin = ip;
		ray.dir = normalizevec(vector_sub(lum.transform.transl, ip));
		if (get_intersection_obj(s.obj, ray) == 0)
		{
			k = (n.x * ray.dir.x + n.y * ray.dir.y + n.z * ray.dir.z) * lum.i;
			res = color_add(res, color_mult(o.color, k));
		}
		tmp = tmp->next;
	}
	res = color_mult(res, o.kd);
	return (res);
}

t_color		compute_color(t_no no, t_scene s, t_vec3d n)
{
	t_color		ca;
	t_color		cd;
	t_color		color;

	ca = color_ambiant(s.ia, no.obj.kd, no.obj.color);
	cd = color_diffuse(n, s, no.obj, no.ip);
	color = color_add(ca, cd);
	return (color);
}
