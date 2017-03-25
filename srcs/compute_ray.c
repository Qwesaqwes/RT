/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 05:10:57 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/25 16:42:50 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		set_black_color(void)
{
	t_color	c;

	c.red = 0;
	c.green = 0;
	c.blue = 0;
	return (c);
}

t_color		set_white_color(void)
{
	t_color	c;

	c.red = 1;
	c.green = 1;
	c.blue = 1;
	return (c);
}

t_color		indirect_color(t_scene s, t_values v, t_cv cv, t_no no)
{
	float		fresnel_coeff;
	t_color		color_refl;
	t_color		color_trans;

	v.depth += 1;
	color_refl = compute_ray(reflect(no.normal,
		no.origin.dir, no.ip, cv), s, v);
	color_refl = color_fact(color_refl, no.obj.ks);
	cv.action = 0;
	if (cv.sign < 0 && !(no.obj.type == 2 || no.obj.type == 5 ||
		no.obj.type == 4))
	{
		cv.action = 2;
		ft_lstdelfirst(v.refr_index);
	}
	init_calculed_values(&cv, *(float*)(*v.refr_index)->content,
		no.obj.refr_index);
	if (cv.sinT2 > 1.0 || no.t == 0)
	{
		if (cv.action == 2 && !(no.obj.type == 2 || no.obj.type == 5 ||
			no.obj.type == 4))
			ft_lstadd(v.refr_index, ft_lstnew(&cv.n1, sizeof(float)));
		return (color_refl);
	}
	fresnel_coeff = schlick(cv);
	color_refl = color_fact(color_refl, fresnel_coeff);
	if (cv.action == 0 && !(no.obj.type == 2 || no.obj.type == 5 ||
		no.obj.type == 4))
	{
		v.enter = 1;
		cv.action = 1;
		ft_lstadd(v.refr_index, ft_lstnew(&cv.n2, sizeof(float)));
	}
	color_trans = compute_ray(refract(no.normal, no.origin.dir,
		no.ip, cv), s, v);
	color_trans = color_mult(color_trans, no.obj.color);
	color_trans = color_fact(color_trans, (1 - fresnel_coeff) * no.t);
	if (cv.action == 1 && !(no.obj.type == 2 || no.obj.type == 5 ||
		no.obj.type == 4))
		ft_lstdelfirst(v.refr_index);
	else if (cv.action == 2 && !(no.obj.type == 2 || no.obj.type == 5 ||
		no.obj.type == 4))
		ft_lstadd(v.refr_index, ft_lstnew(&cv.n1, sizeof(float)));
	return (color_add(color_refl, color_trans));
}

t_color		compute_ray(t_ray ray, t_scene s, t_values v)
{
	t_no	no;
	t_color	color;
	t_cv	cv;

	color = set_black_color();
	if (v.depth < MAX_DEPTH)
	{
		if (get_nearest_obj(ray, s.obj, &no) == 0)
			color = s.background;
		else
		{
			no.normal = compute_normal_vec(no);
			no.color = texture_color(no);
			no.normal = bump_mapping(no);
			no.t = transp_mapping(no);
			color = compute_color(no, s, no.normal, ray.origin);
			cv.cosI = -vector_dot(no.normal, no.origin.dir);
			if (cv.cosI < 0)
			{
				if (v.enter == 0 && !(no.obj.type == 2 || no.obj.type == 5 ||
					no.obj.type == 4))
					ft_lstadd(v.refr_index, ft_lstnew(&no.obj.refr_index,
					sizeof(float)));
				cv.sign = -1;
				no.normal = vector_fact(no.normal, -1);
				cv.cosI = -vector_dot(no.normal, no.origin.dir);
			}
			else
				cv.sign = 1;
			color = color_add(color, indirect_color(s, v, cv, no));
		}
	}
	return (color);
}
