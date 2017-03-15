/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_modif_obj2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:01:25 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 15:51:37 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			init_modif_obj_e4(t_gtk *gtk, t_obj *obj)
{
	if (obj->tex.texture == 1)
	{
		gtk->e_che1 = gtk_color_button_new_with_rgba(
				get_color(&obj->tex.tex_col1));
		gtk->e_che2 = gtk_color_button_new_with_rgba(
				get_color(&obj->tex.tex_col2));
		gtk->e_square = gtk_entry_new_with_buffer(
			gtk_entry_buffer_new(itof(obj->tex.square),
		ft_strlen(itof(obj->tex.square))));
	}
	else
	{
		gtk->e_che1 = gtk_color_button_new_with_rgba(
				get_color(&obj->tex.tex_col1));
		gtk->e_che2 = gtk_color_button_new_with_rgba(
				get_color(&obj->tex.tex_col2));
		gtk->e_che3 = gtk_color_button_new_with_rgba(
				get_color(&obj->tex.tex_col3));
	}
}

void			init_modif_obj_e3(t_gtk *gtk, t_obj *obj)
{
	gtk->e_roty = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->transform.rot.y),
		ft_strlen(itof(obj->transform.rot.y))));
	gtk->e_rotz = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->transform.rot.z),
		ft_strlen(itof(obj->transform.rot.z))));
	gtk->e_shine = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->shininess),
		ft_strlen(itof(obj->shininess))));
	gtk->e_refrac = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->refr_index),
		ft_strlen(itof(obj->refr_index))));
	gtk->e_ka = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->ka), ft_strlen(itof(obj->ka))));
	gtk->e_kd = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->kd), ft_strlen(itof(obj->kd))));
	gtk->e_ks = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->ks), ft_strlen(itof(obj->ks))));
	gtk->e_i = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->i), ft_strlen(itof(obj->i))));
	gtk->e_tr = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->t), ft_strlen(itof(obj->t))));
	gtk->e_color = gtk_color_button_new_with_rgba(get_color(&obj->color));
	init_modif_obj_e4(gtk, obj);
}

void			init_modif_obj_e2(t_gtk *gtk, t_obj *obj)
{
	gtk->e_nobj = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(obj->name, ft_strlen(obj->name)));
	gtk->e_posx = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->transform.transl.x),
		ft_strlen(itof(obj->transform.transl.x))));
	gtk->e_posy = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->transform.transl.y),
		ft_strlen(itof(obj->transform.transl.y))));
	gtk->e_posz = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->transform.transl.z),
		ft_strlen(itof(obj->transform.transl.z))));
	gtk->e_scalex = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->transform.scale.x),
		ft_strlen(itof(obj->transform.scale.x))));
	gtk->e_scaley = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->transform.scale.y),
		ft_strlen(itof(obj->transform.scale.y))));
	gtk->e_scalez = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->transform.scale.z),
		ft_strlen(itof(obj->transform.scale.z))));
	gtk->e_rotx = gtk_entry_new_with_buffer(
		gtk_entry_buffer_new(itof(obj->transform.rot.x),
		ft_strlen(itof(obj->transform.rot.x))));
	init_modif_obj_e3(gtk, obj);
}

void			init_modif_obj_e(t_gtk *gtk, const char *object, t_list **list)
{
	t_list	*tmp;
	t_obj	*tmp_obj;

	tmp = *list;
	while (tmp != NULL)
	{
		tmp_obj = (t_obj*)tmp->content;
		if (ft_strcmp(tmp_obj->name, object) == 0)
		{
			init_modif_obj_e2(gtk, tmp_obj);
			break ;
		}
		tmp = tmp->next;
	}
}

const char		*get_selected_row(t_env *e, t_list *list)
{
	GtkTreeSelection	*select;
	GtkTreeIter			iter;
	GtkTreeModel		*model;
	gchar				*object;

	if (list == NULL)
		return (NULL);
	select = gtk_tree_view_get_selection(GTK_TREE_VIEW(e->gtk.gtklist));
	if (gtk_tree_selection_get_selected(select, &model, &iter))
	{
		gtk_tree_model_get(model, &iter, OBJ_COLUMN, &object, -1);
		return ((const char*)object);
	}
	return (NULL);
}
