/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_delete_obj1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:49:48 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/18 15:46:05 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void ft_list_remove_if(t_list **begin_list, const char *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_obj	*tmp_obj;

	if (*begin_list)
	{
		tmp_obj = (t_obj*)(*begin_list)->content;
		if (cmp(tmp_obj->name, data_ref) == 0)
		{
			tmp = *begin_list;
			*begin_list = (*begin_list)->next;
			free(tmp);
			ft_list_remove_if(begin_list, data_ref, cmp);
		}
		else
			ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
	}
}

void 	delete_obj1(t_list **list, t_gtk *gtk)
{
	GtkTreeSelection	*select;
	GtkTreeIter			iter;
	GtkTreeModel		*model;
	gchar				*object;

	select = gtk_tree_view_get_selection(GTK_TREE_VIEW(gtk->gtklist));
	if (gtk_tree_selection_get_selected (select, &model, &iter))
	{
		gtk_tree_model_get(model, &iter, OBJ_COLUMN, &object, -1);
		ft_list_remove_if(list, (const char*)object, &ft_strcmp);
		g_free(object);
	}
}

void 	view_delete_obj(int response, int clicked_del, t_env *e, GtkWidget *view)
{
	GtkWidget	*dialog;
	GtkWidget	*area;
	GtkWidget	*label;
	gint		res;

	if (response == clicked_del)
	{
		gtk_widget_hide(view);
		dialog = gtk_dialog_new_with_buttons("Delete", GTK_WINDOW(e->gtk.window),
		GTK_DIALOG_MODAL, ("NO"), GTK_RESPONSE_REJECT, ("YES"),
		GTK_RESPONSE_ACCEPT, NULL);
		label = gtk_label_new("Are you sure?");
		area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
		gtk_container_add(GTK_CONTAINER(area), label);
		gtk_widget_show_all(dialog);
		res = gtk_dialog_run(GTK_DIALOG(dialog));
		if (res == GTK_RESPONSE_ACCEPT)
		{
			delete_obj1(&e->scene.obj, &e->gtk);
			raytracing(e);
			gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
		}
		gtk_widget_destroy(dialog);
	}
}
