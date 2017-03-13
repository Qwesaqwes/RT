/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:32:03 by opandolf          #+#    #+#             */
/*   Updated: 2017/03/13 19:05:45 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		compute_color_light(t_obj lum, t_no no, t_vec3d n, t_vec3d origin)
{
	t_vec3d	light;
	t_vec3d	halfway;
	t_vec3d	view;
	t_color	ret;

	ret = color_init();
	light = normalizevec(vector_sub(lum.transform.transl, no.ip));
	if (vector_dot(light, n) > 0.0)
	{
		view = normalizevec(vector_sub(origin, no.ip));
		halfway = normalizevec(vector_add(view, light));
		ret = color_add(ret, color_add(diffuse_color(no, lum,
			vector_dot(light, n)), spec_color(no.obj, lum,
				pow(vector_dot(halfway, n), no.obj.shininess))));
	}
	return (ret);
}

t_color		get_intersection_obj1(t_list *list, t_ray ray, float dist_lum,
				t_color ret)
{
	t_list	*tmp;
	t_obj	obj;
	t_ray	img_ray;
	float	dist;

	tmp = list;
	while (tmp)
	{
		obj = *(t_obj*)tmp->content;
		img_ray = imaginary_ray(ray, obj.transform);
		if (obj.type == 0 || obj.type == 1 || obj.type == 2 || obj.type == 3 ||
			obj.type == 4 || obj.type == 5 || obj.type == 6)
			dist = dist_ip(obj, img_ray, ray);
		if (dist > SHADOW_BIAS && dist < dist_lum)
			ret = color_fact(ret, obj.t);
		tmp = tmp->next;
	}
	return (ret);
}

t_color		get_intersection_obj(t_list *list, t_obj lum, t_no no)
{
	t_ray	ray;
	float	dist_lum;
	t_color	ret;

	ret = set_white_color();
	ray.origin = no.ip;
	ray.dir = normalizevec(vector_sub(lum.transform.transl, no.ip));
	dist_lum = vector_length(vector_sub(lum.transform.transl, no.ip));
	ret = get_intersection_obj1(list, ray, dist_lum, ret);
	return (ret);
}

t_color		color_lights(t_scene s, t_no no, t_vec3d n, t_vec3d origin)
{
	t_color	ret;
	t_list	*tmp;
	t_obj	lum;
	t_color	k;

	ret = color_init();
	tmp = s.lum;
	while (tmp)
	{
		lum = (*(t_obj*)tmp->content);
		if ((color_cmp(k = get_intersection_obj(s.obj, lum, no),
			set_black_color()) > 0))
			ret = color_add(ret, color_mult(k,
				compute_color_light(lum, no, n, origin)));
		tmp = tmp->next;
	}
	return (ret);
}

t_color		compute_color(t_no no, t_scene s, t_vec3d n, t_vec3d origin)
{
	t_color		color_ambiant;

	color_ambiant = color_mult(no.color, color_fact(s.ambiant,
		no.obj.ka * (1 - no.obj.t)));
	return (color_add(color_ambiant, color_lights(s, no, n, origin)));
}
