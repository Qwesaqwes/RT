/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_modif_obj1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:19:34 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/08 21:25:54 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


// void 	init_modif_obj_l_e(t_gtk *gtk, t_obj **obj)
// {
//
// }

t_obj	*get_selected_row(t_gtk *gtk, t_list 	*list)
{
	t_obj	*tmp_obj;
	GtkTreeSelection	*select;
	GtkTreeIter			iter;
	GtkTreeModel		*model;
	gchar				*object;

	if (list == NULL)
		return (NULL);
	tmp_obj = NULL;
	select = gtk_tree_view_get_selection(GTK_TREE_VIEW(gtk->gtklist));
	if (gtk_tree_selection_get_selected (select, &model, &iter))
	{
		gtk_tree_model_get(model, &iter, OBJ_COLUMN, &object, -1);
		while (list != NULL)
		{
			tmp_obj = (t_obj*)list->content;
			if(ft_strcmp(tmp_obj->name, (const char*)object) == 0)
				break;
			list = list->next;
		}
		g_free(object);
	}
	return (tmp_obj);
}

int		view_modif_obj(int response, int clic_mod, t_env *e, GtkWidget *view)
{
	GtkWidget	*dialog;
	GtkWidget	*area;
	// gint 		resp;

	t_obj		*tmp_obj;

	if (response == clic_mod)
	{
		gtk_widget_hide(view);
		dialog = gtk_dialog_new_with_buttons("Add Object",
		GTK_WINDOW(e->gtk.window), GTK_DIALOG_MODAL, ("CANCEL"),
		GTK_RESPONSE_REJECT, ("OK"), GTK_RESPONSE_ACCEPT, NULL);
		if (get_selected_row(&e->gtk, e->scene.obj) == NULL)
		{
			g_print("No Object to Modif\n");
			gtk_widget_destroy(dialog);
			return (1);
		}
		tmp_obj = get_selected_row(&e->gtk, e->scene.obj);
		printf("%s\n", tmp_obj->name);
		// init_modif_obj_l_e(&e->gtk, &(get_selected_row(e->gtk.gtklist)))
		init_add_obj_l_e(&e->gtk, response);
		init_add_obj_box(&e->gtk, response);

		area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
		put_label_inside_box(&e->gtk, response);
		put_box_inside_gbox(&e->gtk, response);
		gtk_container_add(GTK_CONTAINER(area), e->gtk.obj_gbox);
		gtk_widget_show_all(dialog);

	}
	return (0);
}
