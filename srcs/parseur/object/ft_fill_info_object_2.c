/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_info_object_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 22:38:09 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 22:38:12 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void		ft_fill_info_object_11(t_obj *obj, t_e *e)
{
	int i;

	if (ft_strcmp(e->split[0], "tex_texture") == 0 && e->split[1] != NULL)
	{
		e->vobject.tex_texture++;
		e->tmp = atoi(e->split[1]);
		if (e->tmp < 0 || e->tmp > 5)
			ft_puterror(e, "Wrong Info in Object - tex_texture");
		if (e->tmp == 5)
			e->texture_5++;
		obj->tex.texture = e->tmp;
	}
	else if (ft_strcmp(e->split[0], "map_buf") == 0 && e->split[1] != NULL)
	{
		e->vobject.map_buf++;
		e->file_name = e->split[1];
		if ((i = open(e->file_name, O_RDONLY)) < 0)
			ft_puterror(e, "error file given - map_buf");
		if ((i = get_next_line(i, &e->tmpc)) < 0)
			ft_puterror(e, "error file given - bump_buf");
		obj->map_buf = gdk_pixbuf_new_from_file(e->file_name, NULL);
	}
	else
		ft_fill_info_object_12(obj, e);
}

static void		ft_fill_info_object_10(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "shininess") == 0 && e->split[1] != NULL)
	{
		e->vobject.shininess++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0)
			ft_puterror(e, "Wrong Info in Object - shininess");
		obj->shininess = e->tmp;
	}
	else if (ft_strcmp(e->split[0], "refraction_index") == 0 &&
		e->split[1] != NULL)
	{
		e->vobject.refraction_index++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 1)
			ft_puterror(e, "Wrong Info in Object - refraction_index");
		obj->refr_index = e->tmp;
	}
	else
		ft_fill_info_object_11(obj, e);
}

static void		ft_fill_info_object_9(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "i") == 0 && e->split[1] != NULL)
	{
		e->vobject.i++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - i");
		obj->i = e->tmp;
	}
	else if (ft_strcmp(e->split[0], "t") == 0 && e->split[1] != NULL)
	{
		e->vobject.t++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - t");
		obj->t = e->tmp;
	}
	else
		ft_fill_info_object_10(obj, e);
}

static void		ft_fill_info_object_7(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "k_ads") == 0 && e->split[1] != NULL &&
		e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.k_ads++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - k_a");
		obj->ka = e->tmp;
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - k_d");
		obj->kd = e->tmp;
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - k_s");
		obj->ks = e->tmp;
	}
	else
		ft_fill_info_object_9(obj, e);
}

void			ft_fill_info_object_6(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "rotation_xyz") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.rotation_xyz++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror(e, "Wrong Info in Object - rotation_x");
		obj->transform.rot.x = e->tmp;
		e->tmp = atof(e->split[2]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror(e, "Wrong Info in Object - rotation_y");
		obj->transform.rot.y = e->tmp;
		e->tmp = atof(e->split[3]);
		if (e->tmp < -360 || e->tmp > 360)
			ft_puterror(e, "Wrong Info in Object - rotation_z");
		obj->transform.rot.z = e->tmp;
	}
	else
		ft_fill_info_object_7(obj, e);
}
