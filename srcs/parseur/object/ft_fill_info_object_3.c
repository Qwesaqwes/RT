/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_info_object_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 22:44:19 by gahubaul          #+#    #+#             */
/*   Updated: 2017/04/04 22:44:21 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void		ft_fill_info_object_17(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "tex_bump") == 0 && e->split[1] != NULL)
	{
		e->vobject.tex_bump++;
		e->tmp = atoi(e->split[1]);
		if (e->tmp != 1 && e->tmp != 0)
			ft_puterror(e, "Wrong Info in Object - tex_bump");
		obj->tex.bump = e->tmp;
	}
	else if (ft_strcmp(e->split[0], "tex_transp") == 0 && e->split[1] != NULL)
	{
		e->vobject.tex_transp++;
		e->tmp = atoi(e->split[1]);
		if (e->tmp != 1 && e->tmp != 0)
			ft_puterror(e, "Wrong Info in Object - tex_transp");
		obj->tex.transp = e->tmp;
	}
	else if (ft_strcmp(e->split[0], "square") == 0 && e->split[1] != NULL)
	{
		e->vobject.square++;
		e->tmp = atof(e->split[1]);
		obj->tex.square = e->tmp;
	}
	else
		ft_fill_info_object_18(obj, e);
}

static void		ft_fill_info_object_16(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "bump_buf") == 0 && e->split[1] != NULL)
	{
		e->vobject.bump_buf++;
		e->fn = e->split[1];
		if ((e->ii = open(e->fn, O_RDONLY)) < 0)
			ft_puterror(e, "error file given - bump_buf");
		if ((e->ii = get_next_line(e->ii, &e->tmpc)) < 0)
			ft_puterror(e, "error file given - bump_buf");
		close(e->ii);
		obj->bump_buf = gray_scale(gdk_pixbuf_new_from_file(e->fn, NULL));
	}
	else if (ft_strcmp(e->split[0], "transp_buf") == 0 && e->split[1] != NULL)
	{
		e->vobject.transp_buf++;
		e->fn = e->split[1];
		if ((e->ii = open(e->fn, O_RDONLY)) < 0)
			ft_puterror(e, "error file given - transp_buf");
		if ((e->ii = get_next_line(e->ii, &e->tmpc)) < 0)
			ft_puterror(e, "error file given - bump_buf");
		close(e->ii);
		obj->transp_buf = gray_scale(gdk_pixbuf_new_from_file(e->fn, NULL));
	}
	else
		ft_fill_info_object_17(obj, e);
}

static void		ft_fill_info_object_14(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "tex_col3") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.tex_col3++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col3_red");
		obj->tex.tex_col3.red = e->tmp;
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col3_green");
		obj->tex.tex_col3.green = e->tmp;
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col3_blue");
		obj->tex.tex_col3.blue = e->tmp;
	}
	else
		ft_fill_info_object_16(obj, e);
}

static void		ft_fill_info_object_13(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "tex_col2") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.tex_col2++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col2_red");
		obj->tex.tex_col2.red = e->tmp;
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col2_green");
		obj->tex.tex_col2.green = e->tmp;
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col2_blue");
		obj->tex.tex_col2.blue = e->tmp;
	}
	else
		ft_fill_info_object_14(obj, e);
}

void			ft_fill_info_object_12(t_obj *obj, t_e *e)
{
	if (ft_strcmp(e->split[0], "tex_col1") == 0 && e->split[1] != NULL
		&& e->split[2] != NULL && e->split[3] != NULL)
	{
		e->vobject.tex_col1++;
		e->tmp = atof(e->split[1]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col1_red");
		obj->tex.tex_col1.red = e->tmp;
		e->tmp = atof(e->split[2]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col1_green");
		obj->tex.tex_col1.green = e->tmp;
		e->tmp = atof(e->split[3]);
		if (e->tmp < 0 || e->tmp > 1)
			ft_puterror(e, "Wrong Info in Object - tex_col1_blue");
		obj->tex.tex_col1.blue = e->tmp;
	}
	else
		ft_fill_info_object_13(obj, e);
}
