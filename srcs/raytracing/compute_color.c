/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opandolf <opandolf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:32:03 by opandolf          #+#    #+#             */
/*   Updated: 2017/04/04 16:16:02 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		get_int_obj1(t_list *tmp, t_obj lum, t_no no)
{
	t_obj	obj;
	float	dist;
	t_ray	ray;
	float	dist_lum;
	t_color	ret;

	ret = set_white_color();
	ray.origin = no.ip;
	ray.dir = normalizevec(vector_sub(lum.transform.transl, no.ip));
	dist_lum = vector_length(vector_sub(lum.transform.transl, no.ip));
	while (tmp)
	{
		obj = *(t_obj*)tmp->content;
		if (obj.id != no.obj.id)
		{
			dist = get_int_one_obj(ray, obj);
			if (dist > SHADOW_BIAS && dist < dist_lum)
				ret = color_fact(ret, obj.t);
		}
		tmp = tmp->next;
	}
	return (ret);
}

t_color		get_int_obj(t_list *list, t_obj lum, t_no no)
{
	t_list	*tmp;

	tmp = list;
	return (get_int_obj1(tmp, lum, no));
}

t_ray		fill_ray(t_vec3d origin, t_vec3d dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = dir;
	return (ray);
}

t_color		color_lights(t_scene s, t_no no, t_vec3d n, t_vec3d origin)
{
	t_color ret;
	t_list	*tmp;
	t_obj	lum;
	t_color	k;

	ret = color_init();
	tmp = s.lum;
	while (tmp)
	{
		lum = (*(t_obj*)tmp->content);
		if (lum.typel == 0 || (lum.typel == 1 && (get_int_one_obj(fill_ray(
			no.ip, vector_fact(lum.normal, -1)), lum) > 0)))
		{
			if ((color_cmp(k = get_int_obj(s.obj, lum, no), set_black()) > 0))
				ret = color_add(ret, color_mult(k, cc_l(lum, no, n, origin)));
		}
		tmp = tmp->next;
	}
	return (ret);
}

t_color		compute_color(t_no no, t_scene s, t_vec3d n, t_vec3d origin)
{
	t_color		color_ambiant;

	color_ambiant = color_mult(no.color, color_fact(s.ambiant,
		no.obj.ka * (1 - no.t)));
	return (color_add(color_ambiant, color_lights(s, no, n, origin)));
}
