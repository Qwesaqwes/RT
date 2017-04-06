/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_info_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 22:37:18 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 22:37:20 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void		ft_fill_info_object_4(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "translate_xyz") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.translate_xyz++;
		e->tmp = stof(e->split[1]);
		obj->transform.transl.x = e->tmp;
		e->tmp = stof(e->split[2]);
		obj->transform.transl.y = e->tmp;
		e->tmp = stof(e->split[3]);
		obj->transform.transl.z = e->tmp;
	}
	else
		ft_fill_info_object_6(obj, e);
}

static void		ft_fill_info_object_3(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "scale") == 0 && e->split[1] != NULL)
	{
		e->vobject.scale_xyz++;
		e->tmp = stof(e->split[1]);
		if (e->tmp <= 0)
			ft_puterror(e, "Wrong Info in Object - scale");
		if (e->tmp > 1.8)
			e->tmp = 1.8;
		obj->transform.scale.x = e->tmp;
		obj->transform.scale.y = e->tmp;
		obj->transform.scale.z = e->tmp;
	}
	else
		ft_fill_info_object_4(obj, e);
}

static void		ft_fill_info_object_2(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "color_rgb") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.color_rgb++;
		e->tmp = stof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - color_green");
		obj->color.red = e->tmp;
		e->tmp = stof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - color_blue");
		obj->color.green = e->tmp;
		e->tmp = stof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - color_red");
		obj->color.blue = (e->tmp);
	}
	else
		ft_fill_info_object_3(obj, e);
}

static char		ft_verif_type(t_e *e, char *type)
{
	if (ft_strcmp(type, "sphere") == 0)
		return (0);
	else if (ft_strcmp(type, "cylindre") == 0)
		return (1);
	else if (ft_strcmp(type, "plane") == 0)
		return (2);
	else if (ft_strcmp(type, "cone") == 0)
		return (3);
	else if (ft_strcmp(type, "triangle") == 0)
		return (4);
	else if (ft_strcmp(type, "polygone2d") == 0)
		return (5);
	else if (ft_strcmp(type, "polygone3d") == 0)
		return (6);
	else if (ft_strcmp(type, "circle") == 0)
		return (7);
	else if (ft_strcmp(type, "quadrics") == 0)
		return (8);
	ft_puterror(e, "Wrong Info Object - Type");
	return (0);
}

void			ft_fill_info_object(t_obj *obj, t_e *e)
{
	int i;

	e->tmp = 0;
	i = 0;
	if (ft_strcmp(e->split[0], "name") == 0 && e->split[1] != NULL)
	{
		e->vobject.name++;
		obj->name = e->split[1];
	}
	else if (ft_strcmp(e->split[0], "type") == 0 && e->split[1] != NULL)
	{
		e->vobject.type++;
		obj->type = ft_verif_type(e, e->split[1]);
	}
	else if (ft_strcmp(e->split[0], "face") == 0)
	{
		e->vobject.faces++;
		add_after_face(ft_parsing_face_after(e, e->save_i, 0), &obj->faces);
	}
	else
		ft_fill_info_object_2(obj, e);
}
