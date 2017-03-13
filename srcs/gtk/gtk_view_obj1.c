/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_view_obj1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JimmyChe <JimmyChe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:51:40 by JimmyChe          #+#    #+#             */
/*   Updated: 2017/03/13 16:01:08 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		view_add_obj(int response, int add_obj_accept, t_env *e,
		GtkWidget *dialog)
{
	if (response == add_obj_accept)
	{
		gtk_widget_destroy(dialog);
		gtk_add_obj(e, response);
	}
}

const char	*put_type(char type)
{
	if (type == 0)
		return ("Sphere");
	else if (type == 1)
		return ("Cylindre");
	else if (type == 2)
		return ("Plan");
	else if (type == 4 || type == 5 || type == 6)
		return ("Polygone");
	else
		return ("Cone");
}

void		add_to_list(GtkListStore *store, t_list *obj_list)
{
	GtkTreeIter		iter;
	t_list			*tmp;
	t_obj			*tmp_obj;

	tmp = obj_list;
	while (tmp != NULL)
	{
		tmp_obj = (t_obj*)tmp->content;
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, OBJ_COLUMN, tmp_obj->name, TYPE_COLUMN,
		put_type(tmp_obj->type), ID_COLUMN, itof((float)tmp_obj->id), -1);
		tmp = tmp->next;
	}
}

void		init_gtk_list(t_gtk *gtk, t_list *obj_list)
{
	GtkCellRenderer		*renderer;
	GtkTreeViewColumn	*column;
	GtkListStore		*store;

	store = gtk_list_store_new(N_COLUMNS, G_TYPE_STRING, G_TYPE_STRING);
	add_to_list(store, obj_list);
	gtk->gtklist = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(gtk->gtklist), TRUE);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Objects",
	renderer, "text", OBJ_COLUMN, NULL);
	gtk_tree_view_column_set_resizable(column, TRUE);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gtk->gtklist), column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Types",
	renderer, "text", TYPE_COLUMN, NULL);
	gtk_tree_view_column_set_resizable(column, TRUE);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gtk->gtklist), column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Id",
	renderer, "text", ID_COLUMN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(gtk->gtklist), column);
	gtk_container_add(GTK_CONTAINER(gtk->windowscr), gtk->gtklist);
}

void		gtk_view_obj(GtkWidget *button, t_env *e)
{
	GtkWidget	*dialog;
	GtkWidget	*area;
	gint		response;

	(void)button;
	e->gtk.windowscr = gtk_scrolled_window_new(NULL, NULL);
	gtk_container_set_border_width(GTK_CONTAINER(e->gtk.windowscr), 10);
	gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(e->gtk.windowscr),
	GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
	gtk_widget_set_size_request(e->gtk.windowscr, 200, 200);
	dialog = gtk_dialog_new_with_buttons("View of Objects",
	GTK_WINDOW(e->gtk.window), GTK_DIALOG_MODAL, ("DELETE"),
	GTK_RESPONSE_REJECT, ("MODIF OBJECT"), GTK_RESPONSE_ACCEPT,
	("ADD OBJECT"), GTK_RESPONSE_APPLY, NULL);
	area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
	init_gtk_list(&e->gtk, e->scene.obj);
	gtk_container_add(GTK_CONTAINER(area), e->gtk.windowscr);
	gtk_widget_show_all(dialog);
	response = gtk_dialog_run(GTK_DIALOG(dialog));
	view_add_obj(response, GTK_RESPONSE_APPLY, e, dialog);
	view_delete_obj(response, GTK_RESPONSE_REJECT, e, dialog);
	if (view_modif_obj(response, GTK_RESPONSE_ACCEPT, e, dialog) == 1)
		gtk_widget_destroy(dialog);
	if (response == -4)
		gtk_widget_destroy(dialog);
}
