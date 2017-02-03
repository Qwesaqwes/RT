/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_options1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:04:19 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/01 19:05:40 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	reset_img(t_gtk *gtk)
{
	gtk->img = gtk_image_new_from_pixbuf(gtk->buffer);
	gtk_box_pack_start(GTK_BOX(gtk->imgbox), gtk->img, 0, 0, 0);
	gtk_widget_show_all(gtk->window);
}
/* Function to Save img when click*/
void 	gtk_s_img(GtkWidget	*button, gpointer buffer)
{
	GError	*err;

	(void)button;
	err = NULL;
	gdk_pixbuf_save(buffer, "RT_img", "jpeg", &err, "quality", "100", NULL);
}

/* Function to zoom when click in the button*/
void 	gtk_zoom(GtkWidget *button, t_env *e)
{
	(void)button;
	gtk_widget_destroy(e->gtk.img);
	e->vp.dist += 0.5;
	raytracing(e);
	reset_img(&e->gtk);
}

/* Function to dezoom when click in the button*/
void 	gtk_dezoom(GtkWidget *button, t_env *e)
{
	(void)button;
	gtk_widget_destroy(e->gtk.img);
	e->vp.dist -= 0.5;
	if (e->vp.dist <= 0)
	{
		e->vp.dist = 0.5;
		g_print("No more Dezoom available\n");
	}
	raytracing(e);
	reset_img(&e->gtk);
}
