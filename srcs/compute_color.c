/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:32:03 by opandolf          #+#    #+#             */
/*   Updated: 2016/12/06 17:37:49 by opandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	color_mult(t_color a, t_color b)
{
	t_color res;

	res.red = fmin(a.red * b.red, 1);
	res.green = fmin(a.green * b.green, 1);
	res.blue = fmin(a.blue * b.blue, 1);
	return (res);
}

t_color		color_add(t_color a, t_color b)
{
	t_color res;

	res.red = fmin(1.0, a.red + b.red);
	res.blue = fmin(1.0, a.blue + b.blue);
	res.green = fmin(1.0, a.green + b.green);
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

t_vec3d		vector_fact(t_vec3d a, float k)
{
	t_vec3d	ret;

	ret.x = a.x * k;
	ret.y = a.y * k;
	ret.z = a.z * k;
	ret.w = a.w;
	return (ret);
}

t_color		color_fact(t_color a, float k)
{
	t_color	ret;

	ret.red = a.red * k;
	ret.green = a.green * k;
	ret.blue = a.blue * k;
	return (ret);
}

float		vector_scalar_product(t_vec3d a, t_vec3d b)
{
	return(a.x * b.x + a.y * b.y + a.z * b.z);
}

t_color		color_init(void)
{
	t_color		ret;

	ret.red = 0;
	ret.green = 0;
	ret.blue = 0;
	return (ret);
}

float		vector_length(t_vec3d a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

t_color		color_mult_fact(t_color a, t_color b, float k)
{
	t_color		ret;

	ret = color_fact(color_mult(a, b), k);
	return (ret);
}

t_color		compute_color_light(t_obj lum, t_no no, t_vec3d n, t_vec3d origin)
{
	t_vec3d	light;
	t_vec3d	halfway;
	t_vec3d	view;
	t_color	ret;

	ret = color_init();
	light = normalizevec(vector_sub(lum.transform.transl, no.ip));
	if (vector_scalar_product(light, n) > 0.0)
	{
		view = normalizevec(vector_sub(origin, no.ip));
		halfway = normalizevec(vector_add(view, light));
		ret = color_add(ret, color_add(color_mult_fact(no.obj.k.d, lum.i.d, vector_scalar_product(light, n)), color_mult_fact(no.obj.k.s, lum.i.s, pow(vector_scalar_product(halfway, n), no.obj.shininess))));
	}
	return (ret);

}

int			get_intersection_obj(t_list *list, t_obj lum, t_no no)
{
	t_list	*tmp;
	t_obj	obj;
	float	dist;
	t_ray	ray;
	t_ray	img_ray;
	float	dist_lum;

	tmp = list;
	while(tmp)
	{
		ray.origin = no.ip;
		ray.dir = normalizevec(vector_sub(lum.transform.transl, no.ip));
		obj = *(t_obj*)tmp->content;
		img_ray = imaginary_ray(ray, obj.transform);
		dist_lum = vector_length(vector_sub(lum.transform.transl, no.ip));
		if (obj.id != no.obj.id)
		{
			if (obj.type == 0)
			{
				dist = sphere_dist(img_ray);
			}
			if (obj.type == 1)
			{
				dist = cylindre_dist(img_ray);
			}
			if (obj.type == 2)
			{
				dist = plane_dist(obj, img_ray);
			}
			if (dist > 0 && dist < dist_lum)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_color		color_lights(t_scene s, t_no no, t_vec3d n, t_vec3d origin)
{
	t_color ret;
	t_list	*tmp;
	t_obj	lum;

	ret = color_init();
	tmp = s.lum;
	while(tmp)
	{
		lum = (*(t_obj*)tmp->content);
		if (get_intersection_obj(s.obj, lum, no) == 0)
		{
			ret = color_add(ret, compute_color_light(lum, no, n, origin));
		}
		tmp = tmp->next;
	}
	return (ret);
}

t_color		compute_color(t_no no, t_scene s, t_vec3d n, t_vec3d origin)
{
	t_color		color_ambiant;

	color_ambiant = color_mult(no.obj.k.a, s.ambiant);
	return(color_add(color_ambiant, color_lights(s, no, n, origin)));
}
