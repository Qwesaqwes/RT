/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:32:03 by opandolf          #+#    #+#             */
/*   Updated: 2016/12/06 09:14:02 by opandolf         ###   ########.fr       */
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

t_vec3d		vector_add(t_vec3d a, t_vec3d b)
{
	t_vec3d ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	ret.w = 1;
	return(ret);
}

t_vec3d		vector_sub(t_vec3d a, t_vec3d b)
{
	t_vec3d ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	ret.w = 1;
	return (ret);
}

int			get_intersection_obj(t_list *list, t_ray ray, char id, float dist_lum)
{
	t_list	*tmp;
	t_ray	img_ray;
	float	dist;


	tmp = list;
	while (tmp)
	{
		if (((t_obj*)tmp->content)->id != id)
		{
			if (((t_obj*)tmp->content)->type == 0)	//si obj = sphere
			{
				img_ray = imaginary_ray(ray, ((t_obj*)tmp->content)->transform);
				dist = sphere_dist(img_ray);
				if (dist >= 0 && dist <= dist_lum)
				{
					return (1);
				}
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

t_color		color_diffuse(t_vec3d n, t_scene s, t_obj o, t_vec3d ip)
{
	t_color		cd;
	t_list		*tmp;
	t_obj		lum;
	float		k;
	t_ray		light;
	float		dist_lum;

	tmp = s.lum;
	cd = color_mult(o.color, 0);
	while(tmp)
	{
		lum = (*(t_obj*)tmp->content);
		light.origin = ip;
		light.dir = vector_sub(lum.transform.transl, ip);
		dist_lum = sqrt(light.dir.x * light.dir.x + light.dir.y * light.dir.y + light.dir.z * light.dir.z);
		light.dir = normalizevec(light.dir);
		if (get_intersection_obj(s.obj, light, o.id, dist_lum) == 0)
		{
			k = (n.x * light.dir.x + n.y * light.dir.y + n.z * light.dir.z) * lum.i;
			cd = color_add(cd, color_mult(o.color, fmax(0, k)));
		}
		tmp = tmp->next;
	}
	cd = color_mult(cd, o.kd);
	return (cd);
}

t_color		compute_color(t_no no, t_scene s, t_vec3d n, t_ray origin)
{
	t_color		ca;
	t_color		cd;
	t_color		color;

	(void)origin;
	ca = color_ambiant(s.ia, no.obj.kd, no.obj.color);
	cd = color_diffuse(n, s, no.obj, no.ip);
	color = color_add(ca, cd);
	return (color);
}
