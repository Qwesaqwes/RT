/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_options1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:04:19 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/17 15:21:01 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	e->vp.dist += 0.5;
	raytracing(e);
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
}

/* Function to dezoom when click in the button*/
void 	gtk_dezoom(GtkWidget *button, t_env *e)
{
	(void)button;
	e->vp.dist -= 0.5;
	if (e->vp.dist <= 0)
	{
		e->vp.dist = 0.5;
		g_print("No more Dezoom available\n");
	}
	raytracing(e);
	gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
}
