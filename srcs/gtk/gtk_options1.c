/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_options1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:04:19 by jichen-m          #+#    #+#             */
/*   Updated: 2017/03/13 15:52:45 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	gtk_s_img(GtkWidget *button, gpointer buffer)
{
	GError	*err;

	(void)button;
	err = NULL;
	gdk_pixbuf_save(buffer, "RT_img", "jpeg", &err, "quality", "100", NULL);
}

void	gtk_zoom(GtkWidget *button, t_env *e)
{
	(void)button;
	e->vp.dist += 0.5;
	raytracing(e);
}

void	gtk_dezoom(GtkWidget *button, t_env *e)
{
	(void)button;
	e->vp.dist -= 0.5;
	if (e->vp.dist <= 0)
	{
		e->vp.dist = 0.5;
		g_print("No more Dezoom available\n");
	}
	raytracing(e);
}
