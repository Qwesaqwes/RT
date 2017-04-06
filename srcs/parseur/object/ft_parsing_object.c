/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 22:14:30 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 22:14:34 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void				ft_verif_object_texture_4(t_e *e, int i)
{
	if (e->vobject.tex_col1 != 1)
		ft_puterror(e, "Wrong Info Object - tex_col1");
	if (e->vobject.tex_col2 != 1)
		ft_puterror(e, "Wrong Info Object - tex_col2");
	if (e->vobject.tex_col3 != 1)
		ft_puterror(e, "Wrong Info Object - tex_col3");
	if (i == 1)
	{
		if (e->vobject.square != 1)
			ft_puterror(e, "Wrong Info Object - square");
	}
}

void				ft_verif_nbr_object_v2(t_e *e, t_obj obj)
{
	if (e->vobject.rotation_xyz != 1)
		ft_puterror(e, "Wrong Info Object - rotation_xyz");
	if (e->vobject.k_ads != 1)
		ft_puterror(e, "Wrong Info Object - k_ads");
	if (e->vobject.i != 1)
		ft_puterror(e, "Wrong Info Object - i");
	if (e->vobject.t != 1)
		ft_puterror(e, "Wrong Info Object - t");
	if (e->vobject.shininess != 1)
		ft_puterror(e, "Wrong Info Object - shininess");
	if (e->vobject.refraction_index != 1)
		ft_puterror(e, "Wrong Info Object - refraction_index");
	if (e->vobject.tex_texture != 1 || e->vobject.tex_bump != 1 ||
		e->vobject.tex_transp != 1)
		ft_puterror(e, "Wrong Info Object - tex_texture");
	if (obj.tex.texture == 5 && e->vobject.map_buf != 1)
		ft_puterror(e, "Wrong Info Object - texture 5");
	if (obj.tex.bump == 1 && e->vobject.tex_bump != 1)
		ft_puterror(e, "Wrong Info Object - bump");
	if (obj.tex.transp == 1 && e->vobject.transp_buf != 1)
		ft_puterror(e, "Wrong Info Object - transp");
	if (obj.tex.texture >= 2 && obj.tex.texture <= 4)
		ft_verif_object_texture_4(e, 0);
	if (obj.tex.texture == 1)
		ft_verif_object_texture_4(e, 1);
}

void				ft_verif_nbr_object(t_e *e, t_obj obj)
{
	if (e->vobject.name != 1)
		ft_puterror(e, "Wrong Info Object - name");
	if (e->vobject.type != 1)
		ft_puterror(e, "Wrong Info Object - type");
	if (e->vobject.color_rgb != 1)
		ft_puterror(e, "Wrong Info Object - color_rgb");
	if (e->vobject.scale_xyz != 1)
		ft_puterror(e, "Wrong Info Object - scale_xyz");
	if (e->vobject.translate_xyz != 1)
		ft_puterror(e, "Wrong Info Object - translate_xyz");
	ft_verif_nbr_object_v2(e, obj);
}

void				ft_free_object(t_e *e)
{
	int				j;

	j = 0;
	if (e->split)
	{
		while (e->split[j] != NULL)
		{
			free(e->split[j]);
			j++;
		}
		free(e->split);
		e->split = NULL;
	}
}

t_obj				ft_parsing_obj_after(t_e *e, int i)
{
	t_obj			tmp;

	i++;
	ft_norme_object(e, &tmp, 1);
	while (i < e->nbr_line && i != -1)
	{
		e->line = i;
		if (e->file[i] && e->file[i][0] != '#' && (ft_strlen(e->file[i]) > 1))
		{
			e->save_i = i;
			e->split = ft_strsplit(e->file[i], '\t');
			e->faceend = i + 1;
			if (e->split[0] != NULL && ft_verif_scene_object(e->split[0]) == 0)
				ft_fill_info_object(&tmp, e);
			else if (e->split[0] != NULL && ft_verif_scene_object(e->split[0])
				!= 0)
				i = -2;
			ft_free_object(e);
		}
		i++;
	}
	ft_norme_object(e, &tmp, 2);
	ft_free_object(e);
	return (tmp);
}
