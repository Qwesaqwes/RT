/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_effect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:16:51 by jichen-m          #+#    #+#             */
/*   Updated: 2017/02/16 20:16:04 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	gtk_effect(GtkWidget *button, t_env *e)
{
	int		active;

	(void)button;
	active = gtk_combo_box_get_active(GTK_COMBO_BOX(e->gtk.n_effect));
	if (active > -1)
	{
		if (active == 1)
		{
			e->gtk.nb_effect = 1;
			raytracing(e);
			// gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);

		}
		else if (active == 0)
		{
			e->gtk.nb_effect = 0;
			raytracing(e);
		}
		else if (active == 2)
		{
			e->gtk.nb_effect = 2;
			raytracing(e);
			// gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
		}
		else if (active == 3)
		{
			e->gtk.nb_effect = 3;
			raytracing(e);
			// gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
		}
		else if (active == 4)
		{
			e->gtk.nb_effect = 4;
			raytracing(e);
			// gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
		}
		else if (active == 5)
		{
			e->gtk.nb_effect = 5;
			raytracing(e);
			// gtk_image_set_from_pixbuf(GTK_IMAGE(e->gtk.img), e->gtk.buffer);
		}
	}
}
