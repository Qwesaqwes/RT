/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_set_box2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:57:51 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/25 16:29:56 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		add_view_box(t_env *e)
{
	e->gtk.view_obj = gtk_button_new_with_label("View of Objects");
	g_signal_connect(e->gtk.view_obj, "clicked", G_CALLBACK(gtk_view_obj), e);
	gtk_box_pack_start(GTK_BOX(e->gtk.stopbox), e->gtk.view_obj,
	FALSE, FALSE, 0);
}

void		choose_file(t_env *e)
{
	e->gtk.choose_f = gtk_button_new_with_label("Change Scene");
	g_signal_connect(e->gtk.choose_f, "clicked", G_CALLBACK(gtk_choose_f), e);
	gtk_box_pack_end(GTK_BOX(e->gtk.stopbox), e->gtk.choose_f, FALSE, FALSE, 0);

}

static void	gtk_antial1(t_env *e, int active)
{
	if (active == 2)
	{
		e->scene.antialiasing = 3;
		raytracing(e);
		gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
	}
	else if (active == 3)
	{
		e->scene.antialiasing = 4;
		raytracing(e);
		gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
	}
}

void		gtk_antial(GtkWidget *button, t_env *e)
{
	int		active;

	(void)button;
	active = gtk_combo_box_get_active(GTK_COMBO_BOX(e->gtk.n_antial));
	if (active == 0)
	{
		e->scene.antialiasing = 1;
		raytracing(e);
		gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
	}
	else if (active == 1)
	{
		e->scene.antialiasing = 2;
		raytracing(e);
		gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
	}
	gtk_antial1(e, active);
}
