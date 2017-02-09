/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_modif_obj1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:19:34 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/09 22:24:12 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

GdkRGBA *get_color(t_color *color)
{
	GdkRGBA		*gtk_color;

	gtk_color = NULL;
	gtk_color = malloc(sizeof(GdkRGBA));
	gtk_color->red = color->red;
	gtk_color->green = color->green;
	gtk_color->blue = color->blue;
	return (gtk_color);
}

void 	init_modif_obj_e3(t_gtk *gtk, t_obj *obj)
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
}

void 	init_modif_obj_e2(t_gtk *gtk, t_obj *obj)
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

void 	init_modif_obj_e(t_gtk *gtk, const char *object, t_list **list)
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
			break;
		}
		tmp = tmp->next;
	}
}

const char	*get_selected_row(t_env *e, t_list 	*list)
{
	GtkTreeSelection	*select;
	GtkTreeIter			iter;
	GtkTreeModel		*model;
	gchar				*object;

	if (list == NULL)
		return (NULL);
	select = gtk_tree_view_get_selection(GTK_TREE_VIEW(e->gtk.gtklist));
	if (gtk_tree_selection_get_selected (select, &model, &iter))
	{
		gtk_tree_model_get(model, &iter, OBJ_COLUMN, &object, -1);
		return ((const char*)object);
	}
	return (NULL);
}

void 	get_type(char *type, t_list *list, const char *object)
{
	t_list	*tmp;
	t_obj	*tmp_obj;

	tmp = list;
	while (tmp != NULL)
	{
		tmp_obj = (t_obj*)tmp->content;
		if (ft_strcmp(tmp_obj->name, object) == 0)
		{
			*type = tmp_obj->type;
			break;
		}
		tmp = tmp->next;
	}
}

int 	update_obj(t_env *e, const char *object)
{
	t_obj	new_obj;

	get_type(&new_obj.type, e->scene.obj, object);
	ft_list_remove_if(&e->scene.obj, object, &ft_strcmp);
	if (put_name_obj(&e->gtk, &new_obj.name, e->scene.obj, &new_obj.id) == 1 ||
		put_pos_obj(&e->gtk, &new_obj.transform.transl) == 1 ||
		put_scale_obj(&e->gtk, &new_obj.transform.scale) == 1 ||
		put_rotation_obj(&e->gtk, &new_obj.transform.rot) == 1 ||
		put_shininess_obj(&e->gtk, &new_obj.shininess) == 1 ||
		put_refraction_obj(&e->gtk, &new_obj.refr_index) == 1 ||
		put_amb_coe_obj(&e->gtk, &new_obj.ka) == 1 ||
		put_dif_coe_obj(&e->gtk, &new_obj.kd) == 1 ||
		put_spec_coe_obj(&e->gtk, &new_obj.ks) == 1 ||
		put_i_light_obj(&e->gtk, &new_obj.i) == 1 ||
		put_tr_obj(&e->gtk, &new_obj.t) == 1)
		return (1);
	put_color_obj(&e->gtk, &new_obj.color);
	ft_lstadd(&e->scene.obj, ft_lstnew(&new_obj, sizeof(t_obj)));
	gtk_widget_destroy(e->gtk.img);
	raytracing(e);
	reset_img(&e->gtk);
	return (0);
}

int		view_modif_obj(int response, int clic_mod, t_env *e, GtkWidget *view)
{
	GtkWidget	*dialog;
	GtkWidget	*area;
	gint 		resp;
	const char	*object;

	if (response == clic_mod)
	{
		gtk_widget_hide(view);
		dialog = gtk_dialog_new_with_buttons("Add Object",
		GTK_WINDOW(e->gtk.window), GTK_DIALOG_MODAL, ("CANCEL"),
		GTK_RESPONSE_REJECT, ("OK"), GTK_RESPONSE_ACCEPT, NULL);
		object = get_selected_row(e, e->scene.obj);
		if (object == NULL)
		{
			g_print("No Object to Modif\n");
			gtk_widget_destroy(dialog);
			return (1);
		}
		init_add_obj_l_e(&e->gtk, response);
		init_modif_obj_e(&e->gtk, object, &e->scene.obj);
		init_add_obj_box(&e->gtk, response);
		area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
		put_label_inside_box(&e->gtk, response);
		put_box_inside_gbox(&e->gtk, response);
		gtk_container_add(GTK_CONTAINER(area), e->gtk.obj_gbox);
		gtk_widget_show_all(dialog);
		resp = gtk_dialog_run(GTK_DIALOG(dialog));
		if (resp == GTK_RESPONSE_ACCEPT)
			update_obj(e, object);
		gtk_widget_destroy(dialog);
	}
	return (0);
}
