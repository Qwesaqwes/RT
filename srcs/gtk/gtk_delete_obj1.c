/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_delete_obj1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:49:48 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 14:57:41 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_list_remove_if(t_list **begin, const char *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_obj	*tmp_obj;

	if (*begin)
	{
		tmp_obj = (t_obj*)(*begin)->content;
		if (cmp(tmp_obj->name, data_ref) == 0)
		{
			tmp = *begin;
			*begin = (*begin)->next;
			ft_lstdelone(&tmp, ft_free_obj);
			ft_list_remove_if(begin, data_ref, cmp);
		}
		else
			ft_list_remove_if(&(*begin)->next, data_ref, cmp);
	}
}

void	delete_obj1(t_list **list, t_gtk *gtk)
{
	GtkTreeSelection	*select;
	GtkTreeIter			iter;
	GtkTreeModel		*model;
	gchar				*object;

	select = gtk_tree_view_get_selection(GTK_TREE_VIEW(gtk->gtklist));
	if (gtk_tree_selection_get_selected(select, &model, &iter))
	{
		gtk_tree_model_get(model, &iter, OBJ_COLUMN, &object, -1);
		ft_list_remove_if(list, (const char*)object, &ft_strcmp);
		g_free(object);
	}
}

void	view_delete_obj(int response, int clic_del, t_env *e, GtkWidget *view)
{
	GtkWidget	*dial;
	GtkWidget	*area;
	GtkWidget	*label;
	gint		res;

	if (response == clic_del)
	{
		gtk_widget_hide(view);
		dial = gtk_dialog_new_with_buttons("Delete", GTK_WINDOW(e->gtk.window),
		GTK_DIALOG_MODAL, ("NO"), GTK_RESPONSE_REJECT, ("YES"),
		GTK_RESPONSE_ACCEPT, NULL);
		label = gtk_label_new("Are you sure?");
		area = gtk_dialog_get_content_area(GTK_DIALOG(dial));
		gtk_container_add(GTK_CONTAINER(area), label);
		gtk_widget_show_all(dial);
		res = gtk_dialog_run(GTK_DIALOG(dial));
		if (res == GTK_RESPONSE_ACCEPT)
		{
			delete_obj1(&e->scene.obj, &e->gtk);
			raytracing(e);
		}
		gtk_widget_destroy(dial);
	}
}
