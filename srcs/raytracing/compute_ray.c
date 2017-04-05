/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 05:10:57 by jichen-m          #+#    #+#             */
/*   Updated: 2017/04/04 16:20:42 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		modif_refr_index(t_cv cv, t_no no, t_values *v, int i)
{
	if (!(no.obj.type == 2 || no.obj.type == 5 || no.obj.type == 4))
	{
		if (cv.action == 0 && i == 0 && cv.sign < 0)
		{
			cv.action = 2;
			ft_lstdelfirst(v->refr_index);
		}
		else if (cv.action == 0 && i == 1)
		{
			v->enter = 1;
			cv.action = 1;
			ft_lstadd(v->refr_index, ft_lstnew(&cv.n2, sizeof(float)));
		}
		else
		{
			if (cv.action == 1)
				ft_lstdelfirst(v->refr_index);
			else if (cv.action == 2)
				ft_lstadd(v->refr_index, ft_lstnew(&cv.n1, sizeof(float)));
		}
	}
}

t_color		indirect_color(t_scene s, t_values v, t_cv cv, t_no no)
{
	t_color		color_refl;
	t_color		color_trans;
	float		fres_c;

	v.depth += 1;
	color_refl = color_fact(compute_ray(reflect(no.normal, no.origin.dir,
		no.ip, cv), s, v), no.obj.ks);
	cv.action = 0;
	modif_refr_index(cv, no, &v, 0);
	init_calculed_values(&cv, *(float*)(*v.refr_index)->content,
	no.obj.refr_index);
	if (cv.sint2 > 1.0 || no.t == 0)
	{
		if (cv.action == 2 && !(no.obj.type == 2 || no.obj.type == 5 ||
			no.obj.type == 4))
			ft_lstadd(v.refr_index, ft_lstnew(&cv.n1, sizeof(float)));
		return (color_refl);
	}
	fres_c = schlick(cv);
	modif_refr_index(cv, no, &v, 1);
	color_refl = color_fact(color_refl, fres_c);
	color_trans = color_fact(color_mult(compute_ray(refract(no.normal,
		no.origin.dir, no.ip, cv), s, v), no.obj.color), (1 - fres_c) * no.t);
	modif_refr_index(cv, no, &v, 2);
	return (color_add(color_refl, color_trans));
}

void		texture_no(t_no *no, t_ray ray)
{
	no->normal = compute_normal_vec(*no);
	if (no->obj.type == 8 && vector_dot(no->normal, ray.dir) > 0)
		no->normal = vector_fact(no->normal, -1);
	no->color = texture_color(*no);
	no->normal = bump_mapping(*no);
	no->t = transp_mapping(*no);
}

void		negative_cos(t_cv *cv, t_no *no, t_values v)
{
	if (v.enter == 0 && !(no->obj.type == 2 || no->obj.type == 5 ||
		no->obj.type == 4))
		ft_lstadd(v.refr_index, ft_lstnew(&no->obj.refr_index,
		sizeof(float)));
	cv->sign = -1;
	no->normal = vector_fact(no->normal, -1);
	cv->cosi = -vector_dot(no->normal, no->origin.dir);
}

t_color		compute_ray(t_ray ray, t_scene s, t_values v)
{
	t_no	no;
	t_color	color;
	t_cv	cv;

	color = set_black();
	if (v.depth < MAX_DEPTH)
	{
		if (get_nearest_obj(ray, s.obj, &no) == 0)
			color = s.background;
		else
		{
			texture_no(&no, ray);
			color = compute_color(no, s, no.normal, ray.origin);
			if ((cv.cosi = -vector_dot(no.normal, no.origin.dir)) < 0)
				negative_cos(&cv, &no, v);
			else
				cv.sign = 1;
			color = color_add(color, indirect_color(s, v, cv, no));
		}
	}
	return (color);
}
