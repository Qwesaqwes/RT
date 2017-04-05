/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_object_next.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 22:16:32 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 22:16:34 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void		ft_fill_info_brut(t_obj *tmp)
{
	tmp->limit.exist.z_min = 0;
	tmp->limit.exist.z_max = 0;
	tmp->limit.exist.y_min = 0;
	tmp->limit.exist.y_max = 0;
	tmp->limit.exist.x_min = 0;
	tmp->limit.exist.x_max = 0;
	tmp->transform.scale.w = 1;
	tmp->transform.transl.w = 1;
	tmp->transform.rot.w = 1;
	tmp->normal.x = -1;
	tmp->normal.y = 0;
	tmp->normal.z = 0;
	tmp->normal.w = 1;
	tmp->faces = NULL;
}

static void		ft_verif_object_2(t_e *e)
{
	e->vobject.bump_buf = 0;
	e->vobject.transp_buf = 0;
	e->vobject.square = 0;
	e->vobject.tex_col1 = 0;
	e->vobject.tex_col2 = 0;
	e->vobject.tex_col3 = 0;
	e->vobject.x_min = 0;
	e->vobject.x_max = 0;
	e->vobject.y_min = 0;
	e->vobject.y_max = 0;
	e->vobject.z_min = 0;
	e->vobject.z_max = 0;
	e->vobject.quadrics = 0;
}

static void		ft_verif_object(t_e *e)
{
	e->vobject.name = 0;
	e->vobject.type = 0;
	e->vobject.color_rgb = 0;
	e->vobject.scale_xyz = 0;
	e->vobject.translate_xyz = 0;
	e->vobject.rotation_xyz = 0;
	e->vobject.k_ads = 0;
	e->vobject.i = 0;
	e->vobject.t = 0;
	e->vobject.shininess = 0;
	e->vobject.refraction_index = 0;
	e->vobject.tex_texture = 0;
	e->vobject.tex_bump = 0;
	e->vobject.tex_transp = 0;
	e->vobject.map_buf = 0;
	ft_verif_object_2(e);
}

void			ft_norme_object(t_e *e, t_obj *tmp, int i)
{
	if (i == 1)
	{
		tmp->refr_index = 0.1;
		ft_verif_object(e);
		ft_fill_info_brut(tmp);
		e->texture_5 = 0;
	}
	if (i == 2)
	{
		ft_verif_nbr_object(e, *tmp);
		ft_verif_limit_exist(e, tmp);
		if (e->vobject.faces != 0 && tmp->faces != NULL)
			tmp->faces = face_cuting(tmp->faces);
	}
}

void			ft_verif_limit_exist(t_e *e, t_obj *tmp)
{
	if (e->vobject.x_min > 1 || e->vobject.x_max > 1 || e->vobject.y_min > 1
		|| e->vobject.y_max > 1 || e->vobject.z_min > 1 || e->vobject.z_max > 1)
		ft_puterror(e, "Wrong Info Object - Min Max");
	if (e->vobject.x_min == 1 && e->vobject.x_max == 1)
		if (tmp->limit.x_min >= tmp->limit.x_max)
			ft_puterror(e,
			"Wrong Info Object  x_min must to be less than x_max");
	if (e->vobject.y_min == 1 && e->vobject.y_max == 1)
		if (tmp->limit.y_min >= tmp->limit.y_max)
			ft_puterror(e,
			"Wrong Info Object 	y_min must to be less than y_max");
	if (e->vobject.z_min == 1 && e->vobject.z_max == 1)
		if (tmp->limit.z_min >= tmp->limit.z_max)
			ft_puterror(e,
			"Wrong Info Object  z_min must to be less than z_max");
	if (tmp->tex.bump == 1 && tmp->tex.transp == 1)
		tmp->refr_index = 1;
	if (tmp->type == 8 && e->vobject.quadrics != 1)
		ft_puterror(e, "Wrong Info Object - quadrics");
}
